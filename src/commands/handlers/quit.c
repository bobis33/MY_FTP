/*
** EPITECH PROJECT, 2024
** myftp
** File description:
** quit.c
*/

#include <unistd.h>
#include <string.h>
#include "messages.h"
#include "tools.h"

void cmd_quit(
    struct data_s *client_data,
    struct client_s *client,
    const int fd,
    const char *args)
{
    (void)args;
    write(fd, QUIT_221, strlen(QUIT_221));
    disconnect_client(client, client_data);
}
