#include <stdio.h>       //std in-out
#include <stdlib.h>      //per utilizzo di certe funzioni:htonl,rand,....
#include <sys/socket.h>  //funz. accept+bind+listen
#include <sys/types.h>   //funz. accept
#include <netinet/in.h>  //definiscono la struttura degli indirizzi
#include <string.h>      //funz. stringhe
#include <errno.h>       //gestioni errori connessione
#include <ctype.h>       //bind
#include <unistd.h>     // file header che consente l'accesso alle API dello standard POSIX
#define PORT 8080

int main(){

//dichiarazione varaibili
int sockfd;
char Str[1024];

struct Sockaddr_in server_addr;

//creazione della socket
if(sockfd=socket(AF_INET,SOCK_STREAM,0) < 0){
    perror("errore nella creazione della socket");
    exit(1);
}

server_addr.sin_family=AF_INET;
server_addr.sin_port=htons(PORT);

inet_pton(AF_INET,"127.0.0.1", &server_addr.sin_addr);

//connessione al server
if(connect(sockfd,(struct sockaddr *)&server_addr,sizeof(server_addr)) < 0){
    perror("errore nella connessione con il server");
    exit(1);
}

//scrittura e invio dei dati
printf("Connessione avvenuta con successo\n");
printf("inserisci città di partenza e di arrivo (separate da uno spazio): ");

fgets(Str, sizeof(Str), stdin);

send(sockfd, Str, sizeof(str), 0);



return 0;

}