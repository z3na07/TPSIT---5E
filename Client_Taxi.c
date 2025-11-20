#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <string.h>
#include <errno.h>
#include <ctype.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 1450

int main() {

    int sockfd;
    char Str[1024];
    char Risposta[1024];
    struct sockaddr_in server_addr = {0};

    while(1){
    // creazione socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("errore nella creazione della socket");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);

    if (inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr) <= 0) {
        perror("inet_pton error");
        exit(1);
    }

    // connessione al server
    if (connect(sockfd, (struct sockaddr *)&server_addr,sizeof(server_addr)) < 0) {
        perror("errore nella connessione con il server");
        exit(1);
    }

    printf("Connessione avvenuta con successo\n");
    printf("Inserisci città di partenza e di arrivo (separate da uno spazio): ");

    fgets(Str, sizeof(Str), stdin);

    send(sockfd, Str, strlen(Str), 0);

    int n = read(sockfd, Risposta, sizeof(Risposta));
    if(n > 0){
        Risposta[n] = '\0';
        printf("%s \n", Risposta);
    }


    close(sockfd);
    }

    
    return 0;
}
