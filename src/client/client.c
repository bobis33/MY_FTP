/*
** EPITECH PROJECT, 2024
** myftp
** File description:
** client
*/

#include <stdlib.h>
#include <stdio.h>

#include "client.h"

void del_client(struct client_s *client)
{
    free(client);
}

int handle_client(struct client_s *client)
{
    if (client == NULL) {
        perror("malloc");
        return ERROR;
    }
    return SUCCESS;
}
