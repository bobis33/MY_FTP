/*
** EPITECH PROJECT, 2024
** myftp
** File description:
** tools.c
*/

#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include "tools.h"
#include "messages.h"

bool is_logged(struct data_s *client_data, const int fd)
{
    if (client_data->is_connected == false) {
        write(fd, NOT_LOGGED_530, strlen(NOT_LOGGED_530));
        return false;
    }
    return true;
}

void disconnect_client(
    struct client_s *client,
    struct data_s *disconnected_client)
{
    disconnected_client->is_connected = false;
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
