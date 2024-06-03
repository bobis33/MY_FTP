/*
** EPITECH PROJECT, 2024
** myftp
** File description:
** core.c
*/

#include "server.h"
#include "client.h"
#include "tools.h"

int core(server_t *server)
{
    if (handle_server(server) == ERROR || handle_clients(server) == ERROR) {
        del_server(server);
        return ERROR;
    }
    del_server(server);
    return SUCCESS;
}
