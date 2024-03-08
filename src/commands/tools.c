/*
** EPITECH PROJECT, 2024
** myftp
** File description:
** tools.c
*/

#include "tools.h"

int check_args_cmd(const char *args, const int fd)
{
    if (args == NULL) {
        dprintf(fd, "501 Syntax error in parameters or arguments.\n");
        return ERROR;
    }
    return SUCCESS;
}