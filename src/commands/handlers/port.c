/*
** EPITECH PROJECT, 2024
** myftp
** File description:
** port.c
*/

#include <stdio.h>
#include <arpa/inet.h>
#include "commands/cmd_tools.h"
#include "commands/messages.h"

static int set_client_address(
    struct data_s *client_data,
    const int port_array[],
    const int fd)
{
    char ip[MAX_PATH];

    sprintf(ip, "%d.%d.%d.%d", port_array[0], port_array[1],
        port_array[2], port_array[3]);
    if (inet_aton(ip, &client_data->sock.sin_addr) == 0) {
        write_message(fd, LOCAL_ERROR_451);
        return ERROR;
    }
    client_data->sock.sin_family = AF_INET;
    client_data->sock.sin_port = htons((port_array[4] * 256) + port_array[5]);
    return SUCCESS;
}

static int count_args(const char *args, const int fd)
{
    int nb_args = 0;

    for (register int index = 0; args[index] != 0; index++) {
        if (args[index] == ',')
            nb_args++;
    }
    if (nb_args != 5) {
        write_message(fd, SYNTAX_ERROR_501);
        return ERROR;
    }
    return SUCCESS;
}

static bool check_args_port(const char *args, int port_array[], int fd)
{
    if (!count_args(args, fd))
        return false;
    if (sscanf(args, "%d,%d,%d,%d,%d,%d", &port_array[0], &port_array[1],
        &port_array[2], &port_array[3],
        &port_array[4], &port_array[5]) == EOF) {
        write_message(fd, SYNTAX_ERROR_501);
        return false;
    }
    for (register int index = 0; index < 6; index++) {
        if (port_array[index] == ERROR
            || port_array[index] < 0 || port_array[index] > 255) {
            write_message(fd, SYNTAX_ERROR_501);
            return false;
        }
    }
    return true;
}

void cmd_port(
    struct data_s *client_data,
    struct client_s *client,
    const int fd,
    const char *args)
{
    int port_array[6] = {ERROR, ERROR, ERROR, ERROR, ERROR, ERROR};

    (void)args;
    (void)client;
    if (!is_logged(client_data, fd)
        || is_args_empty(args, fd)
        || !check_args_port(args, port_array, fd)
        || !set_client_address(client_data, port_array, fd))
        return;
    client_data->mode = ACTIVE;
    write_message(fd, PORT_200);
}
