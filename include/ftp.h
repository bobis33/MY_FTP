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

struct server_s {
    int fd;
    struct protoent *pe;
    char *path;
    in_port_t port;
    struct sockaddr_in sock;
    socklen_t sock_size;
};

struct client_s {
    int fd;
};

int parser(const int argc, const char *args[], struct server_s *server);
int check_args(const int port, const char *path);
int init_ftp(const int port, const char *path, struct server_s *server);
int core(struct server_s *server);
void del_server(struct server_s *server);

#endif //FTP_H
