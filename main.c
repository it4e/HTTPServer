/*
 * TEST FILE, GIT
 * it4e
*/

#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define CLIENTS_LIMIT 10
#define PORT 80

int main() {
    int server, client;
    struct sockaddr_in server_info;
    struct sockaddr_storage client_info;
    socklen_t client_addrlen;

    if((server = socket(AF_INET, SOCK_STREAM, 0)) < 0)
        perror("socket()");

    memset(&server_info, 0, sizeof server_info);
    server_info.sin_addr.s_addr = INADDR_ANY;
    server_info.sin_family = AF_INET;
    server_info.sin_port = htons(PORT);

    if(bind(server, (struct sockaddr *) &server_info, sizeof server_info) < 0)
        perror("bind()");

    if(listen(server, CLIENTS_LIMIT) < 0)
        perror("listen()");

    while(1) {
        if((client = accept(server, (struct sockaddr *) &client_info, &client_addrlen)) < 0)
            perror("accept()");

        printf("A client connected to the server\n");
        close(client);
    }

    return 0;
}
