//
//  server.h
//  HTTPServer
//
//  Created by Patrik Drevestedt on 2015-01-11.
//
//

#ifndef __HTTPServer__server__
#define __HTTPServer__server__

// Maximalt antal klienter som kan ansluta
#define BACKLOG 2000

void error(char *msg);
void server_config(int * server, int port);

#endif /* defined(__HTTPServer__server__) */
