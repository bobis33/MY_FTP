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

void disconnect_client(
    struct client_s *client,
    struct data_s *disconnected_client);
struct data_s *get_client_by_fd(struct client_s *client, int fd);
bool is_logged(struct data_s *client_data, int fd);
bool is_args_empty(const char *args, int fd);

#endif /* TOOLS_H */
