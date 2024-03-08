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
#include "messages.h"

static cmd_info_t cmd_table[] = {
    {"USER", cmd_user},
    {"PASS", cmd_pass},
    {"CWD", NULL},
    {"CDUP", NULL},
    {"QUIT", cmd_quit},
    {"DELE", NULL},
    {"PWD", cmd_pwd}, // to finish
    {"PASV", NULL},
    {"PORT", NULL},
    {"HELP", NULL},
    {"NOOP", cmd_noop},
    {"RETR", NULL},
    {"STOR", NULL},
    {"LIST", NULL},
    {NULL, NULL}
};

void exec_client_command(
    struct client_s *client,
    const int fd,
    const char *args,
    size_t index)
{
    struct data_s *current_client = NULL;

    for (int j = 0; j < MAX_CLIENTS; j++) {
        if (client->clients[j].fd == fd) {
            current_client = &client->clients[j];
            break;
        }
    }
    if (current_client)
        cmd_table[index].handler(current_client, client, fd, args);
}

void check_cmd(
    struct client_s *client,
    const int fd,
    const char *buffer)
{
    char *cmd_str = strtok((char *)buffer, " \r\n");
    char *args = strtok(NULL, "\r\n");

    if (cmd_str == NULL)
        return;
    for (size_t i = 0; cmd_table[i].name != NULL; i++) {
        if (strncmp(cmd_str,
                cmd_table[i].name,
                strlen(cmd_table[i].name)) != 0)
            continue;
        if (cmd_table[i].handler != NULL)
            exec_client_command(client, fd, args, i);
        return;
    }
    write(fd, NOT_IMPLEMENTED_502, strlen(NOT_IMPLEMENTED_502));
}

int handle_inputs(
    struct client_s *client,
    struct data_s *client_data,
    const int fd)
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
            disconnect_client(client, client_data);
            break;
        default:
            check_cmd(client, fd, buffer);
            break;
    }
    return SUCCESS;
}
