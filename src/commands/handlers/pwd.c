/*
** EPITECH PROJECT, 2024
** myftp
** File description:
** pwd.c
*/

#include <unistd.h>
#include <string.h>
#include "commands.h"
#include "messages.h"

void cmd_pwd(
    struct data_s *client_data,
    struct client_s *client,
    const int fd,
    const char *args)
{
    (void)args;
    (void)client;
    if (client_data->is_connected == false) {
        write(fd, NOT_LOGGED_530, strlen(NOT_LOGGED_530));
        return;
    }
}
