/*
** EPITECH PROJECT, 2024
** myftp
** File description:
** pwd.c
*/

#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include "commands/messages.h"
#include "commands/cmd_tools.h"

void cmd_pwd(
    struct data_s *client_data,
    struct client_s *client,
    const int fd,
    const char *args)
{
    char buff[MAX_PATH];

    (void)args;
    (void)client;
    if (!is_logged(client_data, fd))
        return;
    if (snprintf(buff, sizeof(buff), PWD_257, get_pwd()) < 0) {
        write_message(fd, LOCAL_ERROR_451);
        return;
    } else {
        write_message(fd, buff);
    }
}
