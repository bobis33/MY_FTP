/*
** EPITECH PROJECT, 2024
** myftp
** File description:
** noop.c
*/

#include <unistd.h>
#include <string.h>
#include "commands.h"
#include "messages.h"

void cmd_noop(
    struct data_s *client_data,
    struct client_s *client,
    const int fd,
    const char *args)
{
    (void)args;
    (void)client;
    (void)client_data;
    write(fd, NOOP_200, strlen(NOOP_200));
}
