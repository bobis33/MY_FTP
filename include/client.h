/*
** EPITECH PROJECT, 2024
** myftp
** File description:
** client
*/

#pragma once

#ifndef _CLIENT_H_
    #define _CLIENT_H_

    #include "ftp.h"

int handle_client(struct client_s *client);
void del_client(struct client_s *client);

#endif /* _CLIENT_H_ */
