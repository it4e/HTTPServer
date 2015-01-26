//
//  main.c
//  client
//
//  Created by Patrik Drevestedt on 2015-01-26.
//  Copyright (c) 2015 WorkhorsePS. All rights reserved.
//

#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

void error(char 'msg) {
    perror(msg);
    exit(0);
}

int main(int argc, char *argv[]) {
    
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;
}