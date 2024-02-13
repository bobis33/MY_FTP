/*
** EPITECH PROJECT, 2024
** myftp
** File description:
** main
*/

#include <stdlib.h>

#include "ftp.h"

int main(int argc, const char *argv[])
{
    struct ftp_s *ftp = malloc(sizeof(struct ftp_s));

    if (parser(argc, argv, ftp) == ERROR)
        return EPITECH_ERROR;
    core(ftp);
    return SUCCESS;
}
