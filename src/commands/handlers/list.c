/*
** EPITECH PROJECT, 2024
** myftp
** File description:
** list.c
*/

#include <unistd.h>
#include <string.h>
#include <malloc.h>
#include "commands.h"
#include "messages.h"
#include "tools.h"

void cmd_list(
    struct data_s *client_data,
    struct client_s *client,
    const int fd,
    const char *args)
{
    (void)args;
    (void)client;
    if (!is_logged(client_data, fd))
        return;
}
