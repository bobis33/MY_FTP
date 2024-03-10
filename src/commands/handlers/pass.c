/*
** EPITECH PROJECT, 2024
** myftp
** File description:
** pass.c
*/

#include <string.h>
#include "commands/messages.h"
#include "commands/cmd_tools.h"

static const char DEFAULT_USER[] = "Anonymous";
static const char DEFAULT_PASS[] = "";

void cmd_pass(
    struct data_s *client_data,
    struct client_s *client,
    const int fd,
    const char *args)
{
    (void)client;
    if (client_data->is_logged == true) {
        write_message(fd, BAD_SEQUENCE_503);
        return;
    }
    if (client_data->username == NULL) {
        write_message(fd, NEED_ACCOUNT_332);
        return;
    }
    if (strcmp(client_data->username, DEFAULT_USER) == 0 &&
        (args == NULL || strcmp(args, DEFAULT_PASS) == 0)) {
        write_message(fd, LOGIN_230);
        client_data->is_logged = true;
        return;
    }
    write_message(fd, NOT_LOGGED_530);
}
