/*
** EPITECH PROJECT, 2024
** myftp
** File description:
** client
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include "client.h"
#include "tools.h"
#include "messages.h"

static void create_new_client(struct client_s *client, int new_fd)
{
    for (int i = 0; i < MAX_CLIENTS; i++) {
        if (client->clients[i].username == NULL) {
            client->clients[i].fd = new_fd;
            client->clients[i].username = strdup("\n");
            client->clients[i].is_logged = false;
            client->clients[i].path = strdup(client->path);
            FD_SET(new_fd, &client->master_fds);
            client->max_fd = client->max_fd > new_fd ? client->max_fd : new_fd;
            write(new_fd, CONNECTED_220, strlen(CONNECTED_220));
            break;
        }
    }
}

static int accept_new_client(struct client_s *client, int server_fd)
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

static void process_ready_fds(struct client_s *client, int serv_fd, int fd)
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

static int handle_select(struct client_s *client, int rv_select, int server_fd)
{
    switch (rv_select) {
    case ERROR:
        perror("select");
        return ERROR;
    case 0:
        return SUCCESS;
    default:
        for (int index = 0; index != MAX_CLIENTS; index++)
            process_ready_fds(client, server_fd, index);
        return SUCCESS;
    }
}

int handle_clients(struct server_s *server)
{
    struct client_s *client;
    int rv_select;
    int nfds;

    client = malloc(sizeof(struct client_s));
    client->client_len = sizeof(client->client_addr);
    client->path = strdup(server->path);
    chdir(client->path);
    FD_ZERO(&client->master_fds);
    FD_SET(server->fd, &client->master_fds);
    client->max_fd = server->fd;
    while (1) {
        nfds = client->max_fd + 1;
        client->read_fds = client->master_fds;
        rv_select = select(nfds, &client->read_fds, NULL, NULL, NULL);
        if (handle_select(client, rv_select, server->fd) == ERROR) {
            free(client);
            return ERROR;
        }
    }
}
