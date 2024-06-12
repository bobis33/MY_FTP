/*
** EPITECH PROJECT, 2024
** myftp
** File description:
** pasv.c
*/

#include <unistd.h>
#include <stdio.h>
#include <string.h>

#include "commands/cmd_tools.h"
#include "commands/messages.h"

static void display_address(struct sockaddr_in *pasv_addr, int fd)
{
    int port = ntohs(pasv_addr->sin_port);
    char response[256];

    snprintf(response, sizeof(response), PASV_227,
        (pasv_addr->sin_addr.s_addr & 0xFF),
        (pasv_addr->sin_addr.s_addr >> 8 & 0xFF),
        (pasv_addr->sin_addr.s_addr >> 16 & 0xFF),
        (pasv_addr->sin_addr.s_addr >> 24 & 0xFF),
        (port >> 8) & 0xFF,
        port & 0xFF);
    write_message(fd, response);
}

static bool set_connection(
    struct sockaddr_in *pasv_addr,
    const int *pasv_fd,
    data_t *client_data)
{
    socklen_t len = sizeof(*pasv_addr);

    memset(pasv_addr, 0, len);
    pasv_addr->sin_family = AF_INET;
    pasv_addr->sin_addr.s_addr = INADDR_ANY;
    pasv_addr->sin_port = 0;
    if (bind(*pasv_fd, pasv_addr, len) == -1 ||
        listen(*pasv_fd, 1) == -1 ||
        getsockname(*pasv_fd, pasv_addr, &len) == -1) {
        return false;
    }
    client_data->pasv_fd = *pasv_fd;
    client_data->mode = PASSIVE;
    display_address(pasv_addr, client_data->fd);
    return true;
}

void cmd_pasv(
    data_t *client_data,
    client_t *client,
    const int fd,
    const char *args)
{
    struct sockaddr_in pasv_addr;
    int pasv_fd = 0;

    (void)args;
    (void)client;
    if (!is_logged(client_data, fd))
        return;
    if (client_data->mode == PASSIVE) {
        close(client_data->pasv_fd);
    }
    pasv_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (pasv_fd == -1) {
        perror("socket");
        write_message(fd, LOCAL_ERROR_451);
        return;
    }
    if (!set_connection(&pasv_addr, &pasv_fd, client_data)) {
        close(pasv_fd);
        write_message(fd, LOCAL_ERROR_451);
    }
}
