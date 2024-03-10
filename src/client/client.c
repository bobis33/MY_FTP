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

static void create_new_client(struct client_s *client, const int new_fd)
{
    for (register int index = 0; index < MAX_CLIENTS; index++) {
        if (client->clients[index].username == NULL) {
            client->clients[index].fd = new_fd;
            client->clients[index].username = strdup("\n");
            client->clients[index].is_logged = false;
            client->clients[index].mode = NONE;
            FD_SET(new_fd, &client->master_fds);
            client->max_fd = client->max_fd > new_fd ? client->max_fd : new_fd;
            write_message(new_fd, CONNECTED_220);
            break;
        }
    }
}

static int accept_new_client(struct client_s *client, const int server_fd)
{
    int new_fd = accept(server_fd,
                        (struct sockaddr *)&client->client_addr,
                        &client->client_len);

    if (new_fd == ERROR) {
        perror("accept");
        return ERROR;
    }
    create_new_client(client, new_fd);
    if (client->clients[MAX_CLIENTS - 1].username != NULL) {
        close(new_fd);
        return ERROR;
    }
    return new_fd;
}

static void process_ready_fds(
    struct client_s *client,
    const int serv_fd,
    const int fd)
{
    struct data_s *current_client;
    int new_fd;

    if (!FD_ISSET(fd, &client->read_fds))
        return;
    if (fd == serv_fd) {
        new_fd = accept_new_client(client, serv_fd);
        if (new_fd != ERROR)
            FD_SET(new_fd, &client->master_fds);
    } else {
        current_client = get_client_by_fd(client, fd);
        if (!current_client)
            return;
        handle_inputs(client, current_client, fd);
    }
}

static int handle_select(
    struct client_s *client,
    const int rv_select,
    const int server_fd)
{
    switch (rv_select) {
    case ERROR:
        free(client);
        perror("select");
        return ERROR;
    case 0:
        return SUCCESS;
    default:
        for (register int index = 0; index != MAX_CLIENTS; index++)
            process_ready_fds(client, server_fd, index);
        return SUCCESS;
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
        if (handle_select(client, rv_select, server->fd) == ERROR) {
            free(client);
            return ERROR;
        }
    }
}

int handle_clients(struct server_s *server)
{
    struct client_s *client;

    client = malloc(sizeof(struct client_s));
    if (!check_ptr(client, "malloc")) {
        free(client);
        return ERROR;
    }
    client->client_len = sizeof(client->client_addr);
    client->root_path = get_pwd();
    if (chdir(server->path) == ERROR || client->root_path == NULL) {
        free(client);
        return ERROR;
    }
    FD_ZERO(&client->master_fds);
    FD_SET(server->fd, &client->master_fds);
    client->max_fd = server->fd;
    return loop_client(client, server);
}
