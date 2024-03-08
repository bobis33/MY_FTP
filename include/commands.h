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
    #include "client.h"

typedef struct cmd_info_s {
    const char *name;
    void (*handler)(struct client_s *client, const int fd, const char *args);
} cmd_info_t;

int handle_inputs(struct client_s *client, int fd);

#endif /* COMMANDS_H */
