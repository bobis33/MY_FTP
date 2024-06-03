/*
** EPITECH PROJECT, 2024
** myftp
** File description:
** noop.c
*/

#include "commands/messages.h"
#include "commands/cmd_tools.h"

void cmd_noop(
    data_t *client_data,
    client_t *client,
    const int fd,
    const char *args)
{
    (void)args;
    (void)client;
    (void)client_data;
    write_message(fd, NOOP_200);
}
