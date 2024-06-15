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
    data_t *client_data,
    client_t *client,
    const int fd,
    const char *args)
{
    (void)args;
    (void)client;
    if (!is_logged(client_data, fd))
        return;
    if (chdir(args) == 0) {
        write_message(fd, CWD_250);
    } else {
        write_message(fd, NOT_TAKEN_550);
    }
}
