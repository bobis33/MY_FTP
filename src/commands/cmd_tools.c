/*
** EPITECH PROJECT, 2024
** myftp
** File description:
** cmd_tools.c
*/

#include <unistd.h>
#include <string.h>

#include "ftp.h"
#include "commands/messages.h"
#include "commands/cmd_tools.h"

char *get_pwd(void)
{
    char buff[MAX_PATH];

    if (!getcwd(buff, sizeof(buff))) {
        return NULL;
    }
    return strdup(buff);
}

bool check_ptr_cmd(const void *ptr, const int fd)
{
    if (ptr == NULL) {
        write_message(fd, LOCAL_ERROR_451);
        return false;
    }
    return true;
}

bool is_args_empty(const char *args, const int fd)
{
    if (args == NULL) {
        write_message(fd, SYNTAX_ERROR_501);
        return true;
    }
    return false;
}

bool is_logged(struct data_s *client_data, const int fd)
{
    if (client_data->is_logged == false) {
        write_message(fd, NOT_LOGGED_530);
        return false;
    }
    return true;
}

bool is_mode(const enum data_mode_e mode, const int fd)
{
    if (mode == NONE) {
        write_message(fd, NO_MODE_425);
        return false;
    }
    return true;
}
