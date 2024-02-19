/*
** EPITECH PROJECT, 2024
** myftp
** File description:
** server
*/

#pragma once

#ifndef SERVER_H
    #define SERVER_H

    #include "ftp.h"

int handle_server(struct server_s *server);
void del_server(struct server_s *server);

#endif //SERVER_H
