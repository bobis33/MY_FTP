/*
** EPITECH PROJECT, 2024
** myftp
** File description:
** tools.c
*/

#include <unistd.h>
#include <stdlib.h>
#include "ftp.h"

void disconnect_client(
    struct client_s *client,
    struct data_s *disconnected_client)
{
    disconnected_client->is_logged = false;
    free(disconnected_client->username);
    close(disconnected_client->fd);
    FD_CLR(disconnected_client->fd, &client->master_fds);
    disconnected_client->username = NULL;
}

struct data_s *get_client_by_fd(struct client_s *client, int fd)
{
    for (int index = 0; index < MAX_CLIENTS; index++) {
        if (client->clients[index].fd == fd) {
            return &client->clients[index];
        }
    }
    return NULL;
}

void del_server(struct server_s *server)
{
    free(server->path);
    free(server);
}
