/*
** EPITECH PROJECT, 2024
** myftp
** File description:
** server.h
*/

#pragma once

    #include "ftp.h"

int handle_server(struct server_s *server);

int bind_socket(const struct sockaddr *sock, int fd);
int create_socket(struct server_s *server);
void init_sockaddr(struct sockaddr_in *sock, int port);
