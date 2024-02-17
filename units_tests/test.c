/*
** EPITECH PROJECT, 2024
** myftp
** File description:
** test
*/


#include <criterion/criterion.h>
#include "ftp.h"

Test(parser, error_return_value)
{
    const int argc = 0;
    const char *argv[] = {NULL};
    struct server_s *server = {0};

    cr_assert(parser(argc, argv, server) == ERROR);
}

Test(parser, success_return_value)
{
    const int argc = 3;
    const char *argv[] = {"./myftp", "4242", "doc"};
    struct server_s *server = malloc(sizeof(struct server_s));

    cr_assert(parser(argc, argv, server) == SUCCESS);
    free(server);
}

Test(check_args, error_return_value)
{
    const int port = 0;
    const char *path = "bad_path";

    cr_assert(check_args(port, path) == ERROR);
}

Test(check_args, success_return_value)
{
    const int port = 4242;
    const char *path = "doc";

    cr_assert(check_args(port, path) == SUCCESS);
}

Test(init_ftp, error_return_value)
{
    const int port = 4242;
    const char *path = "bad_path";
    struct server_s *server = NULL;

    cr_assert(init_ftp(port, path, server) == ERROR);
}

Test(init_ftp, success_return_value)
{
    const int port = 4242;
    const char *path = "doc";
    struct server_s *server = malloc(sizeof(struct server_s));

    cr_assert(init_ftp(port, path, server) == SUCCESS);
    free(server);
}