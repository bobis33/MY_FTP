/*
** EPITECH PROJECT, 2024
** myftp
** File description:
** stor.c
*/

#include "commands/commands.h"
#include "commands/cmd_tools.h"

void cmd_stor(
    struct data_s *client_data,
    struct client_s *client,
    const int fd,
    const char *args)
{
    (void)args;
    (void)client;
    if (!is_logged(client_data, fd) || is_args_empty(args, fd))
        return;
}
