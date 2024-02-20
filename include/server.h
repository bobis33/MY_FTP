/*
** EPITECH PROJECT, 2024
** myftp
** File description:
** server
*/

#pragma once

#ifndef _SERVER_H_
    #define _SERVER_H_

    #include "ftp.h"

int handle_server(struct server_s *server);
void del_server(struct server_s *server);

#endif /* _SERVER_H_ */
