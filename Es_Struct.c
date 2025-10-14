
#include<stdio.h>
#include<string.h>

#DEFINE DIM 5

struct Macchina{
    String ModelloAuto[20];
    int Anno_Immatricolazione;
    String marca[20];
    int cilindrata;
    float prezzo;
    String targa[10];
}

void Prezzomax_MIN(struct macchina auto[]){

    struct Macchina max, min;

    max.prezzo = auto[0].prezzo;
    min.prezzo = auto[0].prezzo;
    max.ModelloAuto = auto[0].ModelloAuto;
    min.ModelloAuto = auto[0].ModelloAuto;

    for(int i=1; i<; i++){
        if(auto[i].prezzo > max.prezzo){
            max.prezzo = auto[i].prezzo;
            max.ModelloAuto = auto[i].ModelloAuto;
        }
        if(auto[i].prezzo < min.prezzo){
            min.prezzo = auto[i].prezzo;
            min.ModelloAuto = auto[i].ModelloAuto;
        }
    }

    printf("Auto piu costosa: %s con prezzo %.2f\n", max.ModelloAuto, max.prezzo);
    printf("Auto piu economica: %s con prezzo %.2f\n", min.ModelloAuto, min.prezzo);
}


void Organizza_Immatricolazione(struct MAcchina auto[]){

    struct auto autoOrdinato[DIM];

    for(int i=0; i<DIM-1; i++){
        for(int j=i+1; j<DIM; j++){
            if(auto[i].Anno_Immatricolazione > auto[j].Anno_Immatricolazione){
                struct Macchina temp = auto[i];
                auto[i] = auto[j];
                auto[j] = temp;
            }
        }
    }

    printf("Auto ordinate per anno di immatricolazione:\n");
    for(int i=0; i<DIM; i++){
        printf("%s - %d\n", auto[i].ModelloAuto, auto[i].Anno_Immatricolazione);
    }
    
}

void VisualizzaPrezzo(struct Macchina auto[]){

    float prezzo;

    printf("Inserisci il prezzo minimo: ");
    scanf("%f", &prezzo);

    for(int i = 0; i < DIM; i++){
        if auto[i].prezzo >= prezzo{
            printf("%s - %.2f\n", auto[i].ModelloAuto, suto[i].prezzo);
        }
    }
}

void ricercaAuto(struct Macchina auto[]){
    
    String targaCercata[10];
    
    printf("Inserisci la targa dell'auto da cercare: ");
    scanf("%s", targaCercata);

    for>(int i = 0; i < DIM; i++){

        if(strcmp(auto[i].targa targaCercata) == 0){
            printf("Auto trovata: %s, Anno: %d, Marca: %s, Cilindrata: %d, Prezzo: %.2f, Targa: %s\n", auto[i].ModelloAuto, auto[i].Anno_Immatricolazione, auto[i].marca, auto[i].cilindrata, auto[i].prezzo, auto[i].targa)
        }
        else if(i == DIM - 1){
            printf("Auto non trovata.\n");
        }            
        
    }
}

MediaPrezziAuto(struct Macchina auto[]){

    float somma = 0.0;

    for(int i = 0; i < DIM; i++){
        somma += auto[i].prezzo;
    }

    float media = somma / DIM;
    printf("Prezzo medio delle auto: %.2f\n", media);
}

void VisualizzaMacchina_anno(struct Macchina auto[]){

    int anno;

    printf("Inserisci l'anno di immatricolazione: ");
    scanf("%d", &anno);

    for(int i = 0; i < DIM; i++){
        if(auto[i].Anno_Immatricolazione == anno){
            printf("%s - %d\n", auto[i].ModelloAuto, auto[i].Anno_Immatricolazione);
        }
    }
}

int main(){

    struct Macchina auto[DIM] = {
        {"golf", 2010, "Volkswagen", 1600, 15000.0, "ABC123"},
        {"clio", 2015, "Renault", 2000, 25000.0, "DEF456"},
        {"punto", 2012, "Fiat", 1800, 18000.0, "GHI789"},
        {"multipla", 2018, "Fiat", 2200, 30000.0, "JKL012"},
        {"yaris", 2011, "Toyota", 1500, 12000.0, "MNO345"}
    };

    int scelta;

    do{
    printf("--MENU--\n");
    printf("[1] Ricerca un atuo in base al prezzo minimo\n");
    printf("[2] Organizza le auto in base all'anno di immatricolazione\n");
    printf("[3] Visualizza le auto con prezzo superiore o uguale a quello inserito\n");
    printf("[4] Ricerca un'auto in base alla targa\n");
    printf("[5] Calcola e visualizza il prezzo medio delle auto\n");
    printf("[6] Visualizza le auto immatricolate in un anno specifico\n");
    printf("[7] Visualizza l'auto piu costosa e quella piu economica\n");
    printf("[8] Esci\n");
    printf("Inserisci la tua scelta: ");
    scanf("%d", &scelta);

    switch(scelta){
        case 1:
            VisualizzaPrezzo(auto);
            break;
        case 2:
            Organizza_Immatricolazione(auto);
            break;
        case 3:
            VisualizzaPrezzo(auto);
            break;
        case 4:
            ricercaAuto(auto);
            break;
        case 5:
            MediaPrezziAuto(auto);
            break;
        case 6:
            VisualizzaMacchina_anno(auto);
            break;
        case 7:
            Prezzomax_MIN(auto);
            break;
        case 8:
            printf("Uscita dal programma...\n");
            break;
        default:
            printf("Scelta non valida. Riprova.\n");}

    }while(scelta != 8);
    
    
    return 0;
}