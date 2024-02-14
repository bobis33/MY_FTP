/*
** EPITECH PROJECT, 2024
** myftp
** File description:
** parser
*/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

#include "ftp.h"

static bool is_dir(const char *path)
{
    struct stat st;

    if (path == NULL)
        return false;
    if (stat(path, &st) == -1) {
        perror("stat");
        return false;
    }
    if (S_ISDIR(st.st_mode))
        return true;
    return false;
}

static int check_args(const int port, const char *path)
{
    if (port < 1024 || port > 65535) {
        fprintf(stderr, "Port must be between 1024 and 65535\n");
        return ERROR;
    }
    if (is_dir(path) == false)
        return ERROR;
    return SUCCESS;
}

int init_ftp(const int port, const char *path, struct server_s *server)
{
    if (server == NULL) {
        perror("malloc");
        return ERROR;
    }
    server->port = port;
    server->path = strdup(path);
    if (server->path == NULL) {
        perror("strdup");
        free(server);
        return ERROR;
    }
    return SUCCESS;
}

int parser(const int argc, const char *args[], struct server_s *server)
{
    int port;

    if (argc == 3) {
        port = atoi(args[1]);
        if (check_args(port, args[2]) == ERROR)
            return ERROR;
        return init_ftp(port, args[2], server);
    }
    return ERROR;
}
