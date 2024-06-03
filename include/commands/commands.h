/*
** EPITECH PROJECT, 2024
** myftp
** File description:
** commands.h
*/

#pragma once

    #include <stdio.h>

    #include "ftp.h"

typedef struct cmd_info_s {
    const char *name;
    void (*handler)(
        data_t *client_data,
        client_t *client,
        int fd,
        const char *args);
} cmd_info_t;

void cmd_cdup(
    data_t *client_data,
    client_t *client,
    int fd,
    const char *args);
void cmd_cwd(
    data_t *client_data,
    client_t *client,
    int fd,
    const char *args);
void cmd_dele(
    data_t *client_data,
    client_t *client,
    int fd,
    const char *args);
void cmd_help(
    data_t *client_data,
    client_t *client,
    int fd,
    const char *args);
void cmd_list(
    data_t *client_data,
    client_t *client,
    int fd,
    const char *args);
void cmd_noop(
    data_t *client_data,
    client_t *client,
    int fd,
    const char *args);
void cmd_pass(
    data_t *client_data,
    client_t *client,
    int fd,
    const char *args);
void cmd_pasv(
    data_t *client_data,
    client_t *client,
    int fd,
    const char *args);
void cmd_port(
    data_t *client_data,
    client_t *client,
    int fd,
    const char *args);
void cmd_pwd(
    data_t *client_data,
    client_t *client,
    int fd,
    const char *args);
void cmd_quit(
    data_t *client_data,
    client_t *client,
    int fd,
    const char *args);
void cmd_retr(
    data_t *client_data,
    client_t *client,
    int fd,
    const char *args);
void cmd_stor(
    data_t *client_data,
    client_t *client,
    int fd,
    const char *args);
void cmd_user(
    data_t *client_data,
    client_t *client,
    int fd,
    const char *args);
