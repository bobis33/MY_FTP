/*
** EPITECH PROJECT, 2024
** myftp
** File description:
** client
*/

#include <stdio.h>

#include "client.h"


int handle_client(struct server_s *server)
{
    struct sockaddr client;

    while (1) {
        server->fd_client = accept(server->fd,
            &client, &server->sock_size);
        if (server->fd_client != -1) {
            dprintf(server->fd_client, "220 (vsFTPd 3.0.0)\n");
        }
    }
}
