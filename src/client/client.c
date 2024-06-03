/*
** EPITECH PROJECT, 2024
** myftp
** File description:
** client.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include "client.h"
#include "tools.h"
#include "commands/messages.h"
#include "commands/cmd_tools.h"

static void remove_client(struct client_s *client, const int fd)
{
    for (int i = 0; i < MAX_CLIENTS; i++) {
        if (client->clients[i].fd == fd) {
            FD_CLR(fd, &client->master_fds);
            close(fd);
            free(client->clients[i].username);
            client->clients[i].username = NULL;
            client->clients[i].fd = ERROR;
            client->clients[i].is_logged = false;
            client->clients[i].mode = NONE;
            break;
        }
    }
}

static int create_new_client(struct client_s *client, const int new_fd)
{
    for (int index = 0; index < MAX_CLIENTS; index++) {
        if (client->clients[index].username == NULL) {
            client->clients[index].fd = new_fd;
            client->clients[index].username = strdup("\n");
            client->clients[index].is_logged = false;
            client->clients[index].mode = NONE;
            FD_SET(new_fd, &client->master_fds);
            write_message(new_fd, CONNECTED_220);
            return new_fd;
        }
    }
    return SUCCESS;
}

static int accept_new_client(struct client_s *client, const int server_fd)
{
    int new_fd =
        accept(server_fd,
            (struct sockaddr *)&client->client_addr,
            &client->client_len);

    if (new_fd == -1) {
        perror("accept");
        return -1;
    }
    if (client->clients[MAX_CLIENTS - 1].username != NULL) {
        close(new_fd);
        return ERROR;
    }
    if (create_new_client(client, new_fd) > client->max_fd)
        client->max_fd = new_fd;
    return new_fd;
}

static void process_ready_fds(
    struct client_s *client,
    const int serv_fd,
    const int fd)
{
    struct data_s *current_client;

    if (!FD_ISSET(fd, &client->read_fds))
        return;
    if (fd == serv_fd) {
        if (accept_new_client(client, serv_fd) == -1) {
            return;
        }
    } else {
        current_client = get_client_by_fd(client, fd);
        if (!current_client) {
            remove_client(client, fd);
            return;
        }
        if (handle_inputs(client, current_client, fd) == -1) {
            remove_client(client, fd);
        }
    }
}

static int loop_client(struct client_s *client, struct server_s *server)
{
    int rv_select;
    int nfds;

    while (true) {
        nfds = client->max_fd + 1;
        client->read_fds = client->master_fds;
        rv_select = select(nfds, &client->read_fds, NULL, NULL, NULL);
        if (rv_select == -1) {
            perror("select");
            return -1;
        }
        for (int index = 0; index < nfds; index++) {
            process_ready_fds(client, server->fd, index);
        }
    }
}

int handle_clients(struct server_s *server)
{
    struct client_s *client = malloc(sizeof(struct client_s));

    if (!client) {
        perror("malloc");
        return ERROR;
    }
    client->client_len = sizeof(client->client_addr);
    client->root_path = get_pwd();
    if (chdir(server->path) == -1 || client->root_path == NULL) {
        free(client);
        return ERROR;
    }
    FD_ZERO(&client->master_fds);
    FD_SET(server->fd, &client->master_fds);
    client->max_fd = server->fd;
    memset(client->clients, 0, sizeof(client->clients));
    for (int i = 0; i < MAX_CLIENTS; i++) {
        client->clients[i].fd = -1;
    }
    return loop_client(client, server);
}
