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

    handle_server(server);
    handle_client(client);
    del_server(server);
    free(client);
    return SUCCESS;
}
