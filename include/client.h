/*
** EPITECH PROJECT, 2024
** myftp
** File description:
** client.h
*/

#pragma once

    #include "ftp.h"

int handle_clients(server_t *server);
int handle_inputs(
    client_t *client,
    data_t *client_data,
    int fd);
