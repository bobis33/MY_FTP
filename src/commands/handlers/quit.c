/*
** EPITECH PROJECT, 2024
** myftp
** File description:
** quit.c
*/

#include <unistd.h>
#include "commands/messages.h"
#include "commands/cmd_tools.h"

void cmd_quit(
    struct data_s *client_data,
    struct client_s *client,
    const int fd,
    const char *args)
{
    (void)args;
    write_message(fd, QUIT_221);
    disconnect_client(client, client_data);
}
