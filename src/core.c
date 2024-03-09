/*
** EPITECH PROJECT, 2024
** myftp
** File description:
** core
*/

#include "server.h"
#include "client.h"

int core(struct server_s *server)
{
    if (handle_server(server) == ERROR || handle_clients(server) == ERROR) {
        del_server(server);
        return ERROR;
    }
    del_server(server);
    return SUCCESS;
}
