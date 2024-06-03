/*
** EPITECH PROJECT, 2024
** myftp
** File description:
** cmd_tools.h
*/

#pragma once

    #include "ftp.h"

void disconnect_client(
    client_t *client,
    data_t *disconnected_client);

bool is_args_empty(const char *args, int fd);
bool is_logged(data_t *client_data, int fd);
bool is_mode(data_mode_t mode, int fd);
bool check_ptr_cmd(const void *ptr, int fd);
char *get_pwd(void);
void write_message(int fd, const char *message);
