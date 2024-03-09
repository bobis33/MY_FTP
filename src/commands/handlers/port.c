/*
** EPITECH PROJECT, 2024
** myftp
** File description:
** port.c
*/

#include "tools.h"

void cmd_port(
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
