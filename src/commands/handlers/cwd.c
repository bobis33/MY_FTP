/*
** EPITECH PROJECT, 2024
** myftp
** File description:
** cwd.c
*/

#include <unistd.h>

#include "commands/cmd_tools.h"
#include "commands/messages.h"

void cmd_cwd(
    struct data_s *client_data,
    struct client_s *client,
    const int fd,
    const char *args)
{
    (void)args;
    (void)client;
    if (!is_logged(client_data, fd) || is_args_empty(args, fd))
        return;
    if (chdir(args) == 0) {
        write_message(fd, CDUP_200);
    } else {
        write_message(fd, NOT_TAKEN_550);
    }
}
