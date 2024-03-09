/*
** EPITECH PROJECT, 2024
** myftp
** File description:
** server
*/

#include <unistd.h>
#include "server.h"

int handle_server(struct server_s *server)
{
    init_sockaddr(&server->sock, server->port);
    if (create_socket(server) == ERROR
        || bind_socket(
            (const struct sockaddr *)&server->sock,
            server->fd) == ERROR)
        return ERROR;
    if (listen(server->fd, MAX_CLIENTS) == ERROR) {
        close(server->fd);
        return ERROR;
    }
    return SUCCESS;
}
