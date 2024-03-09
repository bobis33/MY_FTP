/*
** EPITECH PROJECT, 2024
** myftp
** File description:
** dele.c
*/

#include <unistd.h>
#include <string.h>
#include <malloc.h>
#include "messages.h"
#include "tools.h"

void cmd_dele(
    struct data_s *client_data,
    struct client_s *client,
    const int fd,
    const char *args)
{
    char *path = NULL;
    char buff[MAX_PATH];

    (void)client;
    if (!is_logged(client_data, fd) || is_args_empty(args, fd))
        return;
    getcwd(buff, sizeof(buff));
    if (args[0] == '/') {
        path = strdup(args);
    } else {
        path = malloc(strlen(buff) + strlen(args) + 2);
        strcpy(path, buff);
        strcat(path, "/");
        strcat(path, args);
    }
    if (remove(path) == 0) {
        write(fd, DELE_250, strlen(DELE_250));
    } else {
        write(fd, NOT_TAKEN_550, strlen(NOT_TAKEN_550));
    }
}
