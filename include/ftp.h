/*
** EPITECH PROJECT, 2024
** myftp
** File description:
** ftp.h
*/

#pragma once

    #include <netinet/in.h>
    #include <stdbool.h>

    #define ERROR (-1)
    #define EPITECH_ERROR (84)
    #define SUCCESS (0)
    #define MAX_CLIENTS (1024)
    #define MAX_PATH (1024)

typedef struct server_s {
    int fd;
    int port;
    char *path;
    struct protoent *pe;
    struct sockaddr_in sock;
} server_t;

typedef enum data_mode_e {
    ACTIVE,
    PASSIVE,
    NONE
} data_mode_t;

typedef struct data_s {
    int fd;
    bool is_logged;
    char *username;
    data_mode_t mode;
    struct sockaddr_in sock;
} data_t;

typedef struct client_s {
    int max_fd;
    char *root_path;
    fd_set master_fds;
    fd_set read_fds;
    socklen_t client_len;
    struct sockaddr_in client_addr;
    data_t clients[MAX_CLIENTS];
} client_t;

int parser(server_t *server, const char *port, const char *path);
int core(server_t *server);
