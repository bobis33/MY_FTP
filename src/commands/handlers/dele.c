/*
** EPITECH PROJECT, 2024
** myftp
** File description:
** dele.c
*/

#include <unistd.h>
#include <string.h>
#include <malloc.h>
#include "commands/messages.h"
#include "commands/cmd_tools.h"

void cmd_dele(
    struct data_s *client_data,
    struct client_s *client,
    const int fd,
    const char *args)
{
    char *path = NULL;
    char *buff = NULL;

    (void)client;
    if (!is_logged(client_data, fd) || is_args_empty(args, fd))
        return;
    if (args[0] == '/') {
        path = strdup(args);
    } else {
        buff = get_pwd();
        path = malloc(strlen(buff) + strlen(args) + 2);
        if (!check_ptr_cmd(path, fd) || !check_ptr_cmd(buff, fd))
            return;
        strcpy(path, buff);
        strcat(path, "/");
        strcat(path, args);
    }
    return (remove(path) == 0) ?
        write_message(fd, DELE_250) :
        write_message(fd, NOT_TAKEN_550);
}
