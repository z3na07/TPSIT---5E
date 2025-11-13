#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>   // per inet_pton, sockaddr_in

#define SERVER_IP "192.168.60.162"
#define SERVER_PORT 1450

int main() {
    int socketfd;
    struct sockaddr_in server_addr;
    char stringa[256];

    // Creazione del socket
    socketfd = socket(AF_INET, SOCK_STREAM, 0);
    if (socketfd < 0) {
        perror("Errore creazione socket");
        exit(EXIT_FAILURE);
    }

    // Configurazione dell'indirizzo del server
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);

    // Converte l’indirizzo IP da stringa a formato binario
    if (inet_pton(AF_INET, SERVER_IP, &server_addr.sin_addr) <= 0) {
        perror("Errore conversione indirizzo IP");
        close(socketfd);
        exit(EXIT_FAILURE);
    }

    // Connessione al server
    if (connect(socketfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Errore connessione al server");
        close(socketfd);
        exit(EXIT_FAILURE);
    }

    // Input dell'utente
    printf("Inserisci la stringa da inviare al server: ");
    fgets(stringa, sizeof(stringa), stdin);
    stringa[strcspn(stringa, "\n")] = '\0';  // Rimuove il carattere newline

    // Invio della stringa
    if (write(socketfd, stringa, strlen(stringa)) < 0) {
        perror("Errore invio dati");
    } else {
        printf("Stringa inviata correttamente!\n");
    }

    close(socketfd);
    return 0;
}
