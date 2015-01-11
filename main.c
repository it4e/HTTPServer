/*
 *
 * EXEMPEL PÅ STRUKTUR FÖR MAIN 
 *
*/
#include <stdio.h>
#include <unistd.h>
#include "server.h"
#include "client.h"

//STRUKTUR
//1. Sätt igång server
//2. Gå in i en oändlig loop
//3. Ta emot klient
//4. Skapa ny process som hanterar klient
//5. Börja om från steg 2
int main() {
    //Starta och konfigurera servern, i server.h
    server_config();
    
    while(1) {
        //client = Klient socket
        //server_accept() = Tag emot en klient
        client = client_accept();
        
        //Skapa en ny process som hanterar klienten
        if(! fork())
            client_handle(client);

        ....
    }

    .....

    return 0;
}


