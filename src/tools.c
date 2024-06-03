/*
** EPITECH PROJECT, 2024
** myftp
** File description:
** tools.c
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "ftp.h"
#include "commands/messages.h"

void write_message(const int fd, const char *message)
{
    if (write(fd, message, strlen(message)) == -1)
        write(fd, LOCAL_ERROR_451, strlen(LOCAL_ERROR_451));
}

bool check_ptr(void *ptr, const char *function_name)
{
    if (ptr == NULL) {
        perror(function_name);
        return false;
    }
    return true;
}

void disconnect_client(
    client_t *client,
    data_t *disconnected_client)
{
    disconnected_client->is_logged = false;
    free(disconnected_client->username);
    close(disconnected_client->fd);
    FD_CLR(disconnected_client->fd, &client->master_fds);
    disconnected_client->username = NULL;
}

data_t *get_client_by_fd(client_t *client, int fd)
{
    for (register int index = 0; index < MAX_CLIENTS; index++) {
        if (client->clients[index].fd == fd) {
            return &client->clients[index];
        }
    }
    return NULL;
}

void del_server(server_t *server)
{
    free(server->path);
    free(server);
}
