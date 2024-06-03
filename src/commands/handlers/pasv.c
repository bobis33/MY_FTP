/*
** EPITECH PROJECT, 2024
** myftp
** File description:
** pasv.c
*/

#include "commands/cmd_tools.h"

void cmd_pasv(
    data_t *client_data,
    client_t *client,
    const int fd,
    const char *args)
{
    (void)args;
    (void)client;
    if (!is_logged(client_data, fd))
        return;
}
