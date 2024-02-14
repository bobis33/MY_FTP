/*
** EPITECH PROJECT, 2024
** myftp
** File description:
** main
*/

#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#include "ftp.h"

static void print_help(void)
{
    write(1, "USAGE: ./myftp port path\n", 25);
    write(1, "\tport  is the port number on which the server socket ", 53);
    write(1, "listens\n\tpath  is the path to the home directory for the", 55);
    write(1, " \x1B[3mAnonymous\x1B[0m user\n", 24);
}

int main(int argc, const char *argv[])
{
    struct server_s *server;

    if (argc == 2) {
        if (strcmp(argv[1], "-help") == 0) {
            print_help();
            return SUCCESS;
        }
        return EPITECH_ERROR;
    }
    server = malloc(sizeof(struct server_s));
    if (server == NULL)
        return EPITECH_ERROR;
    if (parser(argc, argv, server) == ERROR)
        return EPITECH_ERROR;
    core(server);
    return SUCCESS;
}
