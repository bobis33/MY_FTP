/*
** EPITECH PROJECT, 2024
** myftp
** File description:
** stor.c
*/

#include "commands/cmd_tools.h"

void cmd_stor(
    data_t *client_data,
    client_t *client,
    const int fd,
    const char *args)
{
    (void)args;
    (void)client;
    if (!is_logged(client_data, fd)
    || is_args_empty(args, fd)
    || !is_mode(client_data->mode, fd))
        return;
}
