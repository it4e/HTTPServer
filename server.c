//
//  server.c
//  HTTPServer
//
//  Created by Patrik Drevestedt on 2015-01-11.
//
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "server.h"
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>

void error(char *msg) {
    perror(msg);
    exit(1);
}

// Gör servern redo för att ta emot klienter
// port = port att ansluta till
// server = en pekare till en variabel som skall hålla socketen
void server_config(int * server, int port) {
    struct sockaddr_in serverinfo;

    if((*server = socket(AF_INET, SOCK_STREAM, 0)) < 0)
        error("socket()");

    memset(&serverinfo, 0, sizeof serverinfo);
    serverinfo.sin_addr.s_addr = INADDR_ANY;
    serverinfo.sin_family = AF_INET;
    serverinfo.sin_port = htons(port);

    if(bind(*server, (struct sockaddr *) &serverinfo, sizeof serverinfo) < 0)
        error("bind()");

    if(listen(*server, BACKLOG) < 0)
        error("listen()");
}


//Main funktionen ska tas bort, för att denna fil ska inkluderas i HTTPServer main.c.
int main(int argc, char *argv[]) {
    
    int sockfd, newsockfd, portno, clilen, n;
    char buffer[256];
    struct sockaddr_in serv_addr, cli_addr;
    
    if (argc < 2) {
        fprintf(stderr, "ERROR, no port provided\n");
        exit(1);
    }
    
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    
    if (sockfd < 0) {
        error("ERROR opening socket");
    }
    
    bzero(&serv_addr, sizeof(serv_addr));
    
    portno = atoi(argv[1]);
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(portno);
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    
    if (bind(sockfd, (struct sockaddr *) &serv_addr,
             sizeof(serv_addr)) < 0)
        error("ERROR on binding");
    
    listen(sockfd, 5);
    
    clilen = sizeof(cli_addr);
    
    newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
    if (newsockfd < 0) {
        error("ERROR on accept");
    }
        
    n = read(newsockfd, buffer, 255);
    if (n < 0) {
        error("ERROR reading from socket");
        printf("Here is the message: %s\n", buffer);
        }
    
    n = write(newsockfd, "I got your message", 18);
    if (n < 0) {
        error("ERROR writing to socket");
    }
    return 0;
}
