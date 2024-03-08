/*
** EPITECH PROJECT, 2024
** myftp
** File description:
** user.c
*/

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include "tools.h"
#include "messages.h"

void cmd_user(
    struct data_s *client_data,
    struct client_s *client,
    const int fd,
    const char *args)
{
    (void)client;
    if (client_data->is_connected == true) {
        write(fd, WRONG_SEQUENCE_503, strlen(WRONG_SEQUENCE_503));
        return;
    }
    if (args == NULL) {
        write(fd, SYNTAX_ERROR_501, strlen(SYNTAX_ERROR_501));
        return;
    }
    if (client_data->username != NULL) {
        free(client_data->username);
        client_data->username = NULL;
    }
    write(fd, USER_331, strlen(USER_331));
    client_data->username = strdup(args);
}
