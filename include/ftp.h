/*
** EPITECH PROJECT, 2024
** myftp
** File description:
** ftp
*/

#pragma once

#ifndef FTP_H
    #define FTP_H

    #define ERROR (-1)
    #define EPITECH_ERROR 84
    #define SUCCESS 0

    #include <netinet/in.h>

struct server_s {
    int fd;
    char *path;
    struct protoent *pe;
    int port;
    struct sockaddr_in sock;
    socklen_t sock_size;
};

struct client_s {
    fd_set master_fds;
    fd_set read_fds;
    struct sockaddr_in client_addr;
    socklen_t client_len;
    int max_fd;
    int new_fd;
};

int parser(const char *port, const char *path, struct server_s *server);
int check_args(int port, const char *path);
int init_ftp(int port, const char *path, struct server_s *server);
int core(struct server_s *server);

#endif /* FTP_H */
