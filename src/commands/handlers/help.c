/*
** EPITECH PROJECT, 2024
** myftp
** File description:
** help.c
*/

#include <unistd.h>
#include <string.h>
#include "commands.h"
#include "messages.h"
#include "tools.h"

void cmd_help(
    struct data_s *client_data,
    struct client_s *client,
    const int fd,
    const char *args)
{
    (void)args;
    (void)client;
    (void)client_data;
    if (!is_logged(client_data, fd))
        return;
    if (args == NULL) {
        write(fd, HELP_214, strlen(HELP_214));
        return;
    }
}
