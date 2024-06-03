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
        struct data_s *client_data,
        struct client_s *client,
        int fd,
        const char *args);
} cmd_info_t;

void cmd_cdup(
    struct data_s *client_data,
    struct client_s *client,
    int fd,
    const char *args);
void cmd_cwd(
    struct data_s *client_data,
    struct client_s *client,
    int fd,
    const char *args);
void cmd_dele(
    struct data_s *client_data,
    struct client_s *client,
    int fd,
    const char *args);
void cmd_help(
    struct data_s *client_data,
    struct client_s *client,
    int fd,
    const char *args);
void cmd_list(
    struct data_s *client_data,
    struct client_s *client,
    int fd,
    const char *args);
void cmd_noop(
    struct data_s *client_data,
    struct client_s *client,
    int fd,
    const char *args);
void cmd_pass(
    struct data_s *client_data,
    struct client_s *client,
    int fd,
    const char *args);
void cmd_pasv(
    struct data_s *client_data,
    struct client_s *client,
    int fd,
    const char *args);
void cmd_port(
    struct data_s *client_data,
    struct client_s *client,
    int fd,
    const char *args);
void cmd_pwd(
    struct data_s *client_data,
    struct client_s *client,
    int fd,
    const char *args);
void cmd_quit(
    struct data_s *client_data,
    struct client_s *client,
    int fd,
    const char *args);
void cmd_retr(
    struct data_s *client_data,
    struct client_s *client,
    int fd,
    const char *args);
void cmd_stor(
    struct data_s *client_data,
    struct client_s *client,
    int fd,
    const char *args);
void cmd_user(
    struct data_s *client_data,
    struct client_s *client,
    int fd,
    const char *args);
