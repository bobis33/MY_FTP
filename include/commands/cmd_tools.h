/*
** EPITECH PROJECT, 2024
** myftp
** File description:
** cmd_tools.h
*/

#pragma once

#ifndef CMD_TOOLS_H
    #define CMD_TOOLS_H

    #include "ftp.h"

void disconnect_client(
    struct client_s *client,
    struct data_s *disconnected_client);

bool is_args_empty(const char *args, int fd);
bool is_logged(struct data_s *client_data, int fd);
bool is_mode(enum data_mode_e mode, int fd);
bool check_ptr_cmd(const void *ptr, int fd);
char *get_pwd(void);
void write_message(int fd, const char *message);

#endif /* CMD_TOOLS_H */
