/*
** EPITECH PROJECT, 2024
** myftp
** File description:
** pwd.c
*/

#include <unistd.h>
#include <string.h>
#include "commands.h"
#include "messages.h"
#include "tools.h"

void cmd_pwd(
    struct data_s *client_data,
    struct client_s *client,
    const int fd,
    const char *args)
{
    char buff[1024];

    (void)args;
    (void)client;
    if (!is_logged(client_data, fd))
        return;
    if (!getcwd(buff, sizeof(buff))) {
        write(fd, NOT_FOUND_550, strlen(NOT_FOUND_550));
        return;
    } else {
        write(fd, "257 ", 4);
        write(fd, buff, strlen(buff));
        write(fd, "\r\n", 2);
    }
}
