/*
** EPITECH PROJECT, 2024
** myftp
** File description:
** commands
*/

#pragma once

#ifndef COMMANDS_H
    #define COMMANDS_H

    #include <stdio.h>
    #include "ftp.h"

typedef struct cmd_info_s {
    const char *name;
    void (*handler)(
        struct data_s *client_data,
        struct client_s *client,
        int fd,
        const char *args);
} cmd_info_t;

void cmd_quit(
    struct data_s *client_data,
    struct client_s *client,
    int fd,
    const char *args);
void cmd_user(
    struct data_s *client_data,
    struct client_s *client,
    int fd,
    const char *args);
void cmd_pass(
    struct data_s *client_data,
    struct client_s *client,
    int fd,
    const char *args);


#endif /* COMMANDS_H */
