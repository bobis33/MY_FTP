/*
** EPITECH PROJECT, 2024
** myftp
** File description:
** dele.c
*/

#include <stdio.h>
#include <stdlib.h>
#include "commands/messages.h"
#include "commands/cmd_tools.h"

void cmd_dele(
    struct data_s *client_data,
    struct client_s *client,
    const int fd,
    const char *args)
{
    char buff[MAX_PATH];

    (void)client;
    if (!is_logged(client_data, fd) || is_args_empty(args, fd))
        return;
    if (realpath(args, buff) == NULL) {
        write_message(fd, NOT_TAKEN_550);
        return;
    }
    if (!check_ptr_cmd(buff, fd))
        return;
    return (remove(buff) == 0) ?
        write_message(fd, DELE_250) :
        write_message(fd, NOT_TAKEN_550);
}
