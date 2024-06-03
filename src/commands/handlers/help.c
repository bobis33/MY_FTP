/*
** EPITECH PROJECT, 2024
** myftp
** File description:
** help.c
*/

#include "commands/messages.h"
#include "commands/cmd_tools.h"

void cmd_help(
    data_t *client_data,
    client_t *client,
    const int fd,
    const char *args)
{
    (void)args;
    (void)client;
    (void)client_data;
    if (!is_logged(client_data, fd))
        return;
    write_message(fd, HELP_214);
}
