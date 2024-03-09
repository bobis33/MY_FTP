/*
** EPITECH PROJECT, 2024
** myftp
** File description:
** tools
*/

#pragma once

#ifndef TOOLS_H
    #define TOOLS_H

    #include "ftp.h"

struct data_s *get_client_by_fd(struct client_s *client, int fd);

void del_server(struct server_s *server);

#endif /* TOOLS_H */
