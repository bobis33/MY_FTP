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

void cmd_help(
    struct data_s *client_data,
    struct client_s *client,
    const int fd,
    const char *args)
{
    (void)args;
    (void)client;
    (void)client_data;
    if (args == NULL) {
        write(fd, HELP_214, strlen(HELP_214));
        return;
    }
}
