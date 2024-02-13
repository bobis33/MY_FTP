/*
** EPITECH PROJECT, 2024
** myftp
** File description:
** test
*/


#include <criterion/criterion.h>
#include "ftp.h"

Test(test1, error_return_value)
{
    const int argc = 0;
    const char *argv[] = {NULL};
    struct ftp_s *ftp = {0};

    cr_assert(parser(argc, argv, ftp) == ERROR);
}
