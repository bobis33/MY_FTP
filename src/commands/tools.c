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

void disconnect_client(
    struct client_s *client,
    struct data_s *disconnected_client)
{
    close(disconnected_client->fd);
    FD_CLR(disconnected_client->fd, &client->master_fds);
    disconnected_client->is_connected = 0;
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

int check_args_cmd(const char *args, const int fd)
{
    if (args == NULL) {
        write(fd, SYNTAX_ERROR_501, strlen(SYNTAX_ERROR_501));
        return ERROR;
    }
    for (size_t index = 0; index < strlen(args); index++) {
        if (args[index] == ' ') {
            write(fd, SYNTAX_ERROR_501, strlen(SYNTAX_ERROR_501));
            return ERROR;
        }
    }
    return SUCCESS;
}
