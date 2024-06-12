/*
** EPITECH PROJECT, 2024
** myftp
** File description:
** handle_inputs.c
*/

#include <unistd.h>
#include <string.h>

#include "commands/commands.h"
#include "commands/cmd_tools.h"
#include "commands/messages.h"

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
    client_t *client,
    const int fd,
    const char *args,
    const int index_cmd)
{
    data_t *current_client = NULL;

    for (register int index = 0; index < MAX_CLIENTS; index++) {
        if (client->clients[index].fd == fd) {
            current_client = &client->clients[index];
            break;
        }
    }
    if (current_client)
        cmd_table[index_cmd].handler(current_client, client, fd, args);
}

static void loop_cmd(
    client_t *client,
    const int fd,
    const char *buffer)
{
    char *cmd_str = strtok((char *)buffer, " \r\n");
    char *args = strtok(NULL, "\r\n");

    if (cmd_str == NULL) {
        write_message(fd, SYNTAX_ERROR_500);
        return;
    }
    for (register int index = 0; cmd_table[index].name != NULL; index++) {
        if (strncmp(cmd_str,
                cmd_table[index].name,
                strlen(cmd_table[index].name)) != 0)
            continue;
        if (cmd_table[index].handler != NULL)
            exec_client_command(client, fd, args, index);
        return;
    }
    write_message(fd, SYNTAX_ERROR_500);
}

int handle_inputs(
    client_t *client,
    data_t *client_data,
    const int fd)
{
    char buffer[MAX_PATH] = "\0";
    int buffer_size = sizeof(buffer);
    ssize_t read_value = read(fd, buffer, buffer_size);

    switch (read_value) {
        case -1:
            perror("read");
            return ERROR;
        case 0:
            close(fd);
            disconnect_client(client, client_data);
            break;
        default:
            loop_cmd(client, fd, buffer);
            return SUCCESS;
    }
    return SUCCESS;
}
