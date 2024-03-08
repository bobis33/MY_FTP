/*
** EPITECH PROJECT, 2024
** myftp
** File description:
** pwd.c
*/

#include <unistd.h>
#include <string.h>
#include <malloc.h>
#include "commands.h"
#include "messages.h"
#include "tools.h"

void cmd_cdup(
    struct data_s *client_data,
    struct client_s *client,
    const int fd,
    const char *args)
{
    char *new_path = NULL;
    char *last_slash = NULL;

    (void)args;
    (void)client;
    if (!is_logged(client_data, fd))
        return;
    new_path = malloc(strlen(client_data->path) + 1);
    strcpy(new_path, client_data->path);
    last_slash = strrchr(new_path, '/');
    if (last_slash) {
        *last_slash = '\0';
    } else {
        free(new_path);
        write(fd, NOT_FOUND_550, strlen(NOT_FOUND_550));
        return;
    }
    client->path = new_path;
    write(fd, CDUP_200, strlen(CDUP_200));
}
