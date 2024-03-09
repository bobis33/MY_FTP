/*
** EPITECH PROJECT, 2024
** myftp
** File description:
** port.c
*/

#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include "commands/cmd_tools.h"
#include "commands/messages.h"

static bool count_args(const char *args, int fd)
{
    int nb_args = 0;

    for (int i = 0; args[i] != 0; i++) {
        if (args[i] == ',')
            nb_args++;
    }
    if (nb_args != 5) {
        write_message(fd, SYNTAX_ERROR_501);
        return false;
    }
    return true;
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
    for (int i = 0; i < 6; i++) {
        if (port_array[i] == ERROR
            || port_array[i] < 0 || port_array[i] > 255) {
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
        || !check_args_port(args, port_array, fd))
        return;
    client_data->mode = ACTIVE;
    write_message(fd, PORT_200);
}
