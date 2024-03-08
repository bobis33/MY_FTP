/*
** EPITECH PROJECT, 2024
** myftp
** File description:
** quit.c
*/

#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include "commands.h"
#include "messages.h"

void cmd_quit(
    struct data_s *client_data,
    struct client_s *client,
    const int fd,
    const char *args)
{
    (void)args;
    write(fd, QUIT_221, strlen(QUIT_221));
    client_data->is_connected = false;
    free(client_data->username);
    close(client_data->fd);
    FD_CLR(client_data->fd, &client->master_fds);
    client_data->username = NULL;
}
