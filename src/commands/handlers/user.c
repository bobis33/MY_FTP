/*
** EPITECH PROJECT, 2024
** myftp
** File description:
** user.c
*/

#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include "commands/cmd_tools.h"
#include "commands/messages.h"

void cmd_user(
    struct data_s *client_data,
    struct client_s *client,
    const int fd,
    const char *args)
{
    (void)client;
    if (client_data->is_logged == true) {
        write_message(fd, BAD_SEQUENCE_503);
        return;
    }
    if (is_args_empty(args, fd))
        return;
    if (client_data->username != NULL) {
        free(client_data->username);
        client_data->username = NULL;
    }
    write_message(fd, USER_331);
    client_data->username = strdup(args);
}
