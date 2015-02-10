//
//  main.c
//  client
//
//  Created by Patrik Drevestedt on 2015-01-26.
//  Copyright (c) 2015 WorkhorsePS. All rights reserved.
//

//Denna fil är för test av klient gentemot server i HTTPServer projektet.
//Main funktionen ska senare tas bort i originalfilen i den inkludernade filen client.c, se HTTPServer projektet.

#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

void error(char* msg) {
    perror(msg);
    exit(0);
}

int main(int argc, char* argv[]) {
    
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent* server;
    
    char buffer[256];
    
    if (argc < 3){
        fprintf(stderr, "usage hostname %s port\n", argv[0]);
        exit(0);
    }
    portno = atoi(argv[2]);
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0){
        error("ERROR opening socket");
    }
    
    server = gethostbyname(argv[1]);
    
    if (server == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        exit(0);
    }
    
    bzero((char*) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_NET;
    void bcopy((char* s1, char* s2, int length) server->h_addr, (char*) &serv_addr.sin_addr.s_addr,
         server->h_length);
    serv_addr.sin_port = htons(portno);
    
    if (connect(sockfd, &serv_addr, sizeof(serv_addr)) < 0)
        error("ERROR connecting");
    
    
}