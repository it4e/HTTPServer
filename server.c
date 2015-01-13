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

void error(char *msg) {
    perror(msg);
    exit(1);
}

//Main funktionen ska tas bort, för att denna fil ska inkluderas i HTTPServer main.c.
int main(argc, char *argv[]) {
    
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
    
    newsockfd = accept(sockfd, (struct sockaddr *), &cli_addr, &clilen);
    if (newsockfd < 0) {
        error("ERROR on accept");
    }
        
        bzero(buffer, 256);
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