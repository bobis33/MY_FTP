/*
** EPITECH PROJECT, 2024
** myftp
** File description:
** main.c
*/

#include <stdlib.h>
#include <string.h>

#include "ftp.h"
#include "tools.h"

static void print_help(void)
{
    write_message(1, "USAGE: ./myftp port path\n\tport  is the port number on "
        "which the server socket listens\n\tpath  is the path to the home"
        " directory for the \x1B[3mAnonymous\x1B[0m user\n");
}

int main(int argc, const char *argv[])
{
    server_t *server;

    if (argc == 2) {
        if (strcmp(argv[1], "-help") == 0) {
            print_help();
            return SUCCESS;
        }
        return EPITECH_ERROR;
    }
    if (argc == 3) {
        server = malloc(sizeof(server_t));
        if (!check_ptr(server, "malloc"))
            return EPITECH_ERROR;
        return parser(server, argv[1], argv[2])
        || core(server) == ERROR ? EPITECH_ERROR : SUCCESS;
    } else {
        return EPITECH_ERROR;
    }
}
