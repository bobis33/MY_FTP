/*
** EPITECH PROJECT, 2024
** myftp
** File description:
** client
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "client.h"
#include "commands.h"

static int accept_new_client(struct client_s *client, const int server_fd)
{
    int new_fd = accept(server_fd,
                        (struct sockaddr *)&client->client_addr,
                        &client->client_len);

    if (new_fd != -1) {
        FD_SET(new_fd, &client->master_fds);
        client->max_fd = (client->max_fd > new_fd) ? client->max_fd : new_fd;
        dprintf(new_fd, "220 Welcome to the FTP server.\n");
    }
    return new_fd;
}


static void process_ready_fds(struct client_s *client, const int server_fd, const int index)
{
    if (!FD_ISSET(index, &client->read_fds))
        return;
    if (index == server_fd) {
        client->new_fd = accept_new_client(client, server_fd);
        if (client->new_fd != -1) {
            handle_inputs(client, client->new_fd);
        }
    } else {
        handle_inputs(client, index);
    }
}

static int handle_select(struct client_s *client, const int select_value, const int server_fd)
{
    switch (select_value) {
    case -1:
        perror("select");
        return ERROR;
    case 0:
        return SUCCESS;
    default:
        for (int index = 0; index != FD_SETSIZE; index++)
            process_ready_fds(client, server_fd, index);
        return SUCCESS;
    }
}

int handle_clients(struct server_s *server)
{
    struct client_s *client;
    int rv_select;
    int nfds;

    client = malloc(sizeof(struct client_s));
    client->client_len = sizeof(client->client_addr);
    FD_ZERO(&client->master_fds);
    FD_SET(server->fd, &client->master_fds);
    client->max_fd = server->fd;
    while (1) {
        nfds = client->max_fd + 1;
        client->read_fds = client->master_fds;
        rv_select = select(nfds, &client->read_fds, NULL, NULL, NULL);
        if (handle_select(client, rv_select, server->fd) == ERROR) {
            free(client);
            return ERROR;
        }
    }
}
