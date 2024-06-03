/*
** EPITECH PROJECT, 2024
** myftp
** File description:
** tools.h
*/

#pragma once

    #include "ftp.h"
    #include "commands/cmd_tools.h"

struct data_s *get_client_by_fd(client_t *client, int fd);
void del_server(server_t *server);
bool check_ptr(void *ptr, const char *function_name);
