/*
** EPITECH PROJECT, 2024
** myftp
** File description:
** messages
*/

#pragma once

#ifndef MESSAGES_H
    #define MESSAGES_H

static const char QUIT_221[] = "221 Goodbye\r\n";
static const char NOT_IMPLEMENTED_502[] = "502 Command not implemented\r\n";
static const char NOT_LOGGED_530[] = "530 Not logged in\r\n";
static const char CONNECTED_220[] = "\"220 Welcome to the FTP server.\r\n";
static const char SYNTAX_ERROR_501[] = "501 Syntax error\r\n";
static const char USER_OK_331[] = "331 User name okay, need password\r\n";
static const char WRONG_SEQUENCE_503[] = "503 Bad sequence.\n\r";
static const char LOGIN_230[] = "230 User logged in, proceed.\r\n";





#endif /* MESSAGES_H */