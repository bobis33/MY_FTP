/*
** EPITECH PROJECT, 2024
** myftp
** File description:
** ftp
*/

#ifndef FTP_H
    #define FTP_H

    #define ERROR -1
    #define EPITECH_ERROR 84
    #define SUCCESS 0

    #include <netinet/in.h>

struct ftp_s {
    struct server_s *server;
    char *path;
    in_port_t port;
};

struct server_s {
    int fd;
    struct sockaddr_in addr;
};

int parser(const int argc, const char *args[], struct ftp_s *ftp);
int core(struct ftp_s *ftp);

#endif //FTP_H
