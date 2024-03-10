/*
** EPITECH PROJECT, 2024
** myftp
** File description:
** cdup.c
*/

#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include "commands/messages.h"
#include "commands/cmd_tools.h"

static bool is_at_root(const int fd, const char *root_path)
{
    char root[MAX_PATH];
    char *pwd = NULL;

    snprintf(root, sizeof(root), "%s/", root_path);
    pwd = get_pwd();
    if (!check_ptr_cmd(pwd, fd))
        return false;
    if (strncmp(pwd, root, strlen(root)) != 0) {
        write_message(fd, NOT_TAKEN_550);
        return false;
    }
    return true;
}

void cmd_cdup(
    struct data_s *client_data,
    struct client_s *client,
    const int fd,
    const char *args)
{
    (void)args;
    (void)client;
    if (!is_logged(client_data, fd))
        return;
    if (!is_at_root(fd, client->root_path))
        return;
    if (chdir("..") == 0)
        write_message(fd, CDUP_200);
    else
        write_message(fd, NOT_TAKEN_550);
}
