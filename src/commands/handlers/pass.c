/*
** EPITECH PROJECT, 2024
** myftp
** File description:
** pass.c
*/

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "tools.h"
#include "messages.h"

static const char DEFAULT_USER[] = "Anonymous";
static const char DEFAULT_PASS[] = "";

void cmd_pass(
    struct data_s *client_data,
    struct client_s *client,
    const int fd,
    const char *args)
{
    (void)client;
    if (client_data->username == NULL || client_data->is_connected == true) {
        write(fd, WRONG_SEQUENCE_503, strlen(WRONG_SEQUENCE_503));
        return;
    }
    if (strcmp(client_data->username, DEFAULT_USER) == 0 &&
        (args == NULL || strcmp(args, DEFAULT_PASS) == 0)) {
        write(fd, LOGIN_230, strlen(LOGIN_230));
        client_data->is_connected = true;
        return;
    }
    write(fd, NOT_LOGGED_530, strlen(NOT_LOGGED_530));
}
