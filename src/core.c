/*
** EPITECH PROJECT, 2024
** myftp
** File description:
** core
*/

#include "ftp.h"
#include "server.h"
#include "client.h"

int core(struct server_s *server)
{
    if (handle_server(server) == ERROR || handle_client(server) == ERROR) {
        del_server(server);
        return ERROR;
    }
    del_server(server);
    return SUCCESS;
}
