/*
** EPITECH PROJECT, 2024
** myftp
** File description:
** server
*/

#include <netdb.h>
#include <stdlib.h>
#include <stdio.h>

#include "server.h"

void del_server(struct server_s *server)
{
    free(server->path);
    free(server);
}

static int init_server(struct server_s *server)
{
    server->sock.sin_family = AF_INET;
    server->sock.sin_port = htons(server->port);
    server->sock.sin_addr.s_addr = INADDR_ANY;
    server->pe = getprotobyname("TCP");
    server->sock_size = sizeof(server->sock);
    if (server->pe == NULL)
        return ERROR;
    server->fd = socket(AF_INET, SOCK_STREAM, server->pe->p_proto);
    if (server->fd == -1) {
        perror("socket");
        return ERROR;
    }
    if (bind(server->fd, (const struct sockaddr*) &server->sock,
            sizeof(server->sock)) == -1) {
        perror("bind");
        return ERROR;
    }
    return SUCCESS;
}

int handle_server(struct server_s *server)
{
    if (server == NULL) {
        perror("malloc");
        return ERROR;
    }
    if (init_server(server) == ERROR) {
        return ERROR;
    }
    return SUCCESS;
}
