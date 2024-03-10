/*
** EPITECH PROJECT, 2024
** myftp
** File description:
** client.h
*/

#pragma once

#ifndef CLIENT_H
    #define CLIENT_H

    #include "ftp.h"

int handle_clients(struct server_s *server);
int handle_inputs(
    struct client_s *client,
    struct data_s *client_data,
    int fd);

#endif /* CLIENT_H */
