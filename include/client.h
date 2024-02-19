/*
** EPITECH PROJECT, 2024
** myftp
** File description:
** client
*/

#pragma once

#ifndef CLIENT_H
    #define CLIENT_H

    #include "ftp.h"

int handle_client(struct client_s *client);
void del_client(struct client_s *client);

#endif //CLIENT_H
