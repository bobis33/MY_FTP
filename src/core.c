/*
** EPITECH PROJECT, 2024
** myftp
** File description:
** core
*/

#include <stdlib.h>

#include "ftp.h"
#include "server.h"
#include "client.h"

int core(struct server_s *server)
{
    struct client_s *client = malloc(sizeof(struct client_s));

    if (handle_server(server) == ERROR || handle_client(client) == ERROR) {
        del_server(server);
        del_client(client);
        return ERROR;
    }
    del_server(server);
    del_client(client);
    return SUCCESS;
}
