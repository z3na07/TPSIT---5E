#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>
int cambioCialde(int countCialdeUsate){

    printf("Cialde finite, Riempimento in corso..");
    for(int i; i < 10; i ++){
        printf(">");
        sleep(3);
    }

    countCialdeUsate = 0;

    return countCialdeUsate;
}

int main(){

    //Variabili menu
    int scelta = 0;
    

    //variabili macchinetta
    bool pieno
    int countCialdeUsate = 0;
    int QuantSerbatoio = 2000;
    

    printf("La caldaia si sta scaldando..");
    for(int i; i < 10; i ++){
        printf(">");
        sleep(3);
    }
    
    
    

    while(scelta != 5){

        if(countCialdeUsate == 15){
            countCialdeUsate = cambioCialde(countCialdeUsate);
        }

        printf("--MENU-- \n");
        printf("[1] Espresso (25 ml) \n");
        printf("[2] Macchiato (35 ml) \n");
        printf("[3] Decaffeinato (25 ml) \n");
        printf("[4] The (200 ml) \n");
        printf("[5] Esci \n");
        
        if(countCialdeUsate > 10){
            printf("SVUOTARE CESTINO DELLE CIALDE!! \n");
        }
        scanf("%d", &scelta); 
        
        printf("\n");

        switch(scelta){

            case 1:
                printf("Bevanda in erogazione...");
                for(int i; i < 5; i++){
                    printf(">");
                    sleep(1);
                }
            printf("Bevanda erogata, prego ritirare \n");
            QuantSerbatoio = QuantSerbatoio - 25;
            countCialdeUsate++;
            break;

            case 2:
                printf("Bevanda in erogazione...");
                for(int i; i < 7; i++){
                    printf(">");
                    sleep(1);
                }
            printf("Bevanda erogata, prego ritirare \n");
            QuantSerbatoio = QuantSerbatoio - 35;
            countCialdeUsate++;
            break;

            case 3:
                printf("Bevanda in erogazione...");
                for(int i; i < 5; i++){
                    printf(">");
                    sleep(1);
                }
            printf("Bevanda erogata, prego ritirare \n");
            QuantSerbatoio = QuantSerbatoio - 25;
            countCialdeUsate++;
            break;

            case 4:
                printf("Bevanda in erogazione...");
                for(int i; i < 10; i++){
                    printf(">");
                    sleep(4);
                }
            printf("Bevanda erogata, prego ritirare \n");
            QuantSerbatoio = QuantSerbatoio - 200;
            countCialdeUsate++;
            break;

            default:
                printf("Uscita in corso..");
                sleep(3);
                break;


        
    

        }
    }



    return 0;
}

