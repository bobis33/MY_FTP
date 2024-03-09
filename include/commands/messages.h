/*
** EPITECH PROJECT, 2024
** myftp
** File description:
** messages
*/

#pragma once

#ifndef MESSAGES_H
    #define MESSAGES_H

static const char SERVICE_READY_120[] = "120 Service ready in nn minutes.\r\n";
static const char CONNECTED_125[] = "125 Data connection already open.\r\n";
static const char FILE_STATUS_150[] = "150 File status okay.\r\n";
static const char CDUP_200[] = "200 Directory successfully changed.\r\n";
static const char NOOP_200[] = "200 NOOP ok.\r\n";
static const char PORT_200[] = "200 PORT ok.\r\n";
static const char HELP_214[] = "214 Help message.\r\n";
static const char CONNECTED_220[] = "220 Service ready for new user.\r\n";
static const char QUIT_221[] = "221 Service closing control connection.\r\n";
static const char CLOSE_CONNECTION_226[] = "226 Closing data connection.\r\n";
static const char PASV_227[] = "227 Passive Mode (%d,%d,%d,%d,%d,%d).\r\n";
static const char LOGIN_230[] = "230 User logged in, proceed.\r\n";
static const char DELE_250[] = "250 Requested file action okay.\r\n";
static const char PWD_257[] = "257 \"%s\"\r\n";
static const char USER_331[] = "331 User name okay, need password.\r\n";
static const char NEED_ACCOUNT_332[] = "332 Need account for login.\r\n";
static const char LOCAL_ERROR_451[] = "451 Requested action aborted.\r\n";
static const char SYNTAX_ERROR_501[] = "501 Syntax error.\r\n";
static const char NOT_IMPLEMENTED_502[] = "502 Command not implemented.\r\n";
static const char BAD_SEQUENCE_503[] = "503 Bad sequence.\n\r";
static const char NOT_LOGGED_530[] = "530 Not logged in.\r\n";
static const char NOT_TAKEN_550[] = "550 Requested action not taken.\r\n";

#endif /* MESSAGES_H */
