/*
** EPITECH PROJECT, 2024
** myftp
** File description:
** handle_inputs.c
*/

#include <unistd.h>
#include <string.h>
#include "commands.h"
#include "tools.h"

static void cmd_user(struct client_s *client, const int fd, const char *args) {
    (void)client;
    if (check_args_cmd(args, fd) == ERROR)
        return;
    dprintf(fd, "331 User name okay, need password.\n");
}

static void cmd_quit(struct client_s *client, const int fd, const char *args) {
    (void)client;
    (void)args;
    dprintf(fd, "221 Goodbye.\n");
    close(fd);
    FD_CLR(fd, &client->master_fds);
}

static cmd_info_t cmd_table[] = {
        {"USER", cmd_user},
        {"PASS", NULL},
        {"CWD", NULL},
        {"CDUP", NULL},
        {"QUIT", cmd_quit},
        {"DELE", NULL},
        {"PWD", NULL},
        {"PASV", NULL},
        {"PORT", NULL},
        {"HELP", NULL},
        {"NOOP", NULL},
        {"RETR", NULL},
        {"STOR", NULL},
        {"LIST", NULL},
        {NULL, NULL}
};

void check_cmd(struct client_s *client, const int fd, const char *buffer)
{
    char *cmd_str = strtok((char *)buffer, " \r\n");
    char *args = strtok(NULL, "\r\n");

    if (cmd_str == NULL)
        return;

    for (size_t i = 0; cmd_table[i].name != NULL; i++) {
        if (strncmp(cmd_str, cmd_table[i].name, strlen(cmd_table[i].name)) == 0) {
            if (cmd_table[i].handler != NULL) {
                cmd_table[i].handler(client, fd, args);
            }
            return;
        }
    }
    dprintf(fd, "502 Command not implemented.\n");
}

int handle_inputs(struct client_s *client, const int fd)
{
    char buffer[1024] = "\0";
    int buffer_size = sizeof(buffer);
    ssize_t read_value = read(fd, buffer, buffer_size);

    switch (read_value) {
        case -1:
            perror("read");
            break;
        case 0:
            close(fd);
            FD_CLR(fd, &client->master_fds);
            break;
        default:
            check_cmd(client, fd, buffer);
            break;
    }
    return SUCCESS;
}
