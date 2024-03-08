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
    #define MAX_CLIENTS 10


    #include <netinet/in.h>
    #include <stdbool.h>

struct server_s {
    int fd;
    char *path;
    struct protoent *pe;
    int port;
    struct sockaddr_in sock;
};

struct data_s {
    int fd;
    char *username;
    bool is_connected;
    char *path;
};

struct client_s {
    fd_set master_fds;
    fd_set read_fds;
    struct sockaddr_in client_addr;
    socklen_t client_len;
    int max_fd;
    char *path;
    struct data_s clients[10];
};

int parser(const char *port, const char *path, struct server_s *server);
int check_args(int port, const char *path);
int init_ftp(int port, const char *path, struct server_s *server);
int core(struct server_s *server);

#endif /* FTP_H */
