/*
** EPITECH PROJECT, 2024
** myftp
** File description:
** cwd.c
*/

#include <unistd.h>
#include <string.h>
#include "commands.h"
#include "tools.h"
#include "messages.h"

void cmd_cwd(
    struct data_s *client_data,
    struct client_s *client,
    const int fd,
    const char *args)
{
    char new_path[1024];

    (void)args;
    (void)client;
    if (!is_logged(client_data, fd))
        return;
    if (args == NULL) {
        write(fd, SYNTAX_ERROR_501, strlen(SYNTAX_ERROR_501));
        return;
    }
    snprintf(new_path, sizeof(new_path), "%s/%s", client_data->path, args);
    if (chdir(new_path) == 0) {
        write(fd, CDUP_200, strlen(CDUP_200));
        client_data->path = strdup(new_path);
    } else {
        write(fd, NOT_FOUND_550, strlen(NOT_FOUND_550));
    }
}
