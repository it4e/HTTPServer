//
//  server.c
//  HTTPServer
//
//  Created by Patrik Drevestedt on 2015-01-11.
//
//

#include <stdio.h>
#include "server.h"
#include <sys/types.h>
#include <netinet/in.h>

//Koden ej färdig
void error(char *msg) {
    perror(msg);
    exit(1);
}

int main(argc, char *argv[]) {
    
    int sockfd, newsockfd, portno, clilen, n;
    char buffer[256];
    struct sockaddr_in serv_addr, cli_addr;
    
    if (argc < 2) {
        fprintf(stderr, "ERROR, no port provided\n");
        exit(1);
    }
}