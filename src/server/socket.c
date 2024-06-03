/*
** EPITECH PROJECT, 2024
** myftp
** File description:
** socket.c
*/

#include <netdb.h>
#include <stdio.h>

#include "tools.h"

void init_sockaddr(struct sockaddr_in *sock, const int port)
{
    sock->sin_family = AF_INET;
    sock->sin_port = htons(port);
    sock->sin_addr.s_addr = INADDR_ANY;
}

int create_socket(struct server_s *server)
{
    struct protoent proto;
    struct protoent *proto_ptr;
    char buffer[1024];

    if (getprotobyname_r("TCP",
        &proto,
        buffer,
        sizeof(buffer),
        &proto_ptr) != 0) {
        del_server(server);
        return ERROR;
    }
    server->pe = proto_ptr;
    server->fd = socket(AF_INET, SOCK_STREAM, server->pe->p_proto);
    if (server->fd == ERROR) {
        perror("socket");
        del_server(server);
        return ERROR;
    }
    return SUCCESS;
}

int bind_socket(const struct sockaddr *sock, const int fd)
{
    if (bind(fd, sock, sizeof(struct sockaddr_in)) == ERROR) {
        perror("bind");
        return ERROR;
    }
    return SUCCESS;
}
