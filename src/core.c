/*
** EPITECH PROJECT, 2024
** myftp
** File description:
** core
*/

#include <stdlib.h>

#include "ftp.h"
#include "server.h"
#include "client.h"

static void del_ftp(struct ftp_s *ftp)
{
    free(ftp->path);
    free(ftp);
}

int core(struct ftp_s *ftp)
{
    server(ftp);
    client(ftp);
    del_ftp(ftp);
    return SUCCESS;
}
