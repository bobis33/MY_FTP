/*
** EPITECH PROJECT, 2024
** myftp
** File description:
** messages
*/

#pragma once

#ifndef MESSAGES_H
    #define MESSAGES_H

static const char CDUP_200[] = "200 Directory successfully changed.\r\n";
static const char NOOP_200[] = "200 NOOP ok.\r\n";
static const char HELP_214[] = "214 Help message.\r\n";
static const char CONNECTED_220[] = "\"220 Welcome to the FTP server.\r\n";
static const char QUIT_221[] = "221 Goodbye\r\n";
static const char LOGIN_230[] = "230 User logged in, proceed.\r\n";
static const char PWD_257[] = "257 \"%s\"\r\n";
static const char USER_OK_331[] = "331 User name okay, need password\r\n";
static const char LOCAL_ERROR_451[] = "451 Requested action aborted.\r\n";
static const char SYNTAX_ERROR_501[] = "501 Syntax error\r\n";
static const char NOT_IMPLEMENTED_502[] = "502 Command not implemented\r\n";
static const char WRONG_SEQUENCE_503[] = "503 Bad sequence.\n\r";
static const char NOT_LOGGED_530[] = "530 Not logged in\r\n";
static const char NOT_FOUND_550[] = "550 Requested action not taken.\r\n";





#endif /* MESSAGES_H */
