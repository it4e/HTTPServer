#ifndef _HTTP_H
#define _HTTP_H

//Den största storleken för följande HTTP request headers
//Används för att undgå buffer overflow
//Dvs att man tilldelar en variabel för mycket data
#define REQ_METHOD_LIMIT 5
#define REQ_TARGET_LIMIT 100
#define REQ_HTTP_LIMIT 12
#define REQ_HOST_LIMIT 25
#define REQ_USER_AGENT_LIMIT 200
#define REQ_CONNECTION_LIMIT 20

//Den största storleken för följande HTTP response headers
#define RES_STATUS_LIMIT 40
#define RES_SERVER_LIMIT 50
#define RES_LAST_MOD_LIMIT 50
#define RES_DATE_LIMIT 50
#define RES_TYPE_LIMIT 20
#define RES_CONNECTION_LIMIT 20

//En struct som håller all data som klienten skickar
struct http_request {
    char method[REQ_METHOD_LIMIT]; //Förfrågansmetod, HTTP eller GET
    char target[REQ_TARGET_LIMIT]; //Fil som klienten efterfrågar
    char http[REQ_HTTP_LIMIT]; //HTTP version
    char host[REQ_HOST_LIMIT]; //Vilken address klienten skickade till
    char user_agent[REQ_USER_AGENT_LIMIT]; //Webbläsare
    char connection[REQ_CONNECTION_LIMIT]; //Anslutningstyp
};

//En struct som håller all data om svaret som vi skall skicka tillbaka
struct http_response {
    char status[RES_STATUS_LIMIT]; //Statuskod, tex 402 eller 200 OK
    char server[RES_SERVER_LIMIT]; //Servernamn
    char last_modified[RES_LAST_MOD_LIMIT]; //Senast modifierad fil
    char date[RES_DATE_LIMIT]; //Datum i GMT format
    char type[RES_TYPE_LIMIT]; //Datatyp, tex text/html, text/css
    char connection[RES_CONNECTION_LIMIT]; //Anslutningstyp
};

#endif
