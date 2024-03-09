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
    #define EPITECH_ERROR (84)
    #define SUCCESS (0)
    #define MAX_CLIENTS (10)
    #define MAX_PATH (1024)

    #include <netinet/in.h>
    #include <stdbool.h>

struct server_s {
    int fd;
    int port;
    char *path;
    struct protoent *pe;
    struct sockaddr_in sock;
};

typedef enum data_mode_e {
    ACTIVE,
    PASSIVE,
    NONE
} data_mode_t;

struct data_s {
    int fd;
    bool is_logged;
    char *username;
    data_mode_t mode;
    struct sockaddr_in sock;
};

struct client_s {
    int max_fd;
    char *path;
    fd_set master_fds;
    fd_set read_fds;
    socklen_t client_len;
    struct sockaddr_in client_addr;
    struct data_s clients[MAX_CLIENTS];
};

int parser(struct server_s *server, const char *port, const char *path);
int core(struct server_s *server);

#endif /* FTP_H */
