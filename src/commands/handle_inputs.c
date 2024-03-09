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
    {"CWD", cmd_cwd},
    {"CDUP", cmd_cdup},
    {"QUIT", cmd_quit},
    {"DELE", cmd_dele},
    {"PWD", cmd_pwd},
    {"PASV", cmd_pasv}, // to finish
    {"PORT", cmd_port}, // to finish
    {"HELP", cmd_help},
    {"NOOP", cmd_noop},
    {"RETR", cmd_retr}, // to finish
    {"STOR", cmd_stor}, // to finish
    {"LIST", cmd_list}, // to finish
};

static void exec_client_command(
    struct client_s *client,
    int fd,
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

static void loop_cmd(
    struct client_s *client,
    int fd,
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
    int fd)
{
    char buffer[MAX_PATH] = "\0";
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
            loop_cmd(client, fd, buffer);
            break;
    }
    return SUCCESS;
}
