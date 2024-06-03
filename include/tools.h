/*
** EPITECH PROJECT, 2024
** myftp
** File description:
** tools.h
*/

#pragma once

    #include "ftp.h"
    #include "commands/cmd_tools.h"

struct data_s *get_client_by_fd(struct client_s *client, int fd);
void del_server(struct server_s *server);
bool check_ptr(void *ptr, const char *function_name);
