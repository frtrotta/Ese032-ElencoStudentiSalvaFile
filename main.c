#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definisci le costanti
#define N 3
#define MAX_STRLEN 30
#define FNAME "elenco.dat"

// Definisci il tipo di dato struct s_studente
struct s_studente {
    char nome[MAX_STRLEN+1];
    char cognome[MAX_STRLEN+1];
    int eta;
    char classe[MAX_STRLEN+1];
};

// Definisci studente come struct s_studente
typedef struct s_studente studente;

int main(int argc, char** argv) {
    // Dichiara le variabili locali
    studente s;
    int i;
    FILE *outf;
    int written;
    
    // Codice per l'inserimento, da parte dell'utente, dei dati e del salvataggio
    // nel file
    outf = fopen(FNAME, "wb");
    if(outf == NULL) {
        fprintf(stderr, "Impossibile aprire il file %s\n", FNAME);
        exit(1);
    }
    else {
        printf("File %s aperto\n", FNAME);
    }
    
    printf("Inserisci i dati per %d studenti\n", N);
    for(i=0; i<N; i++) {
        printf("\nInserisci il nome (%d max): ", MAX_STRLEN);
        scanf("%s", s.nome);
        printf("Inserisci il cognome (%d max): ", MAX_STRLEN);
        scanf("%s", s.cognome);
        printf("Inserisci l'eta': ");
        scanf("%d", &(s.eta));
        printf("Inserisci la classe (%d max): ", MAX_STRLEN);
        scanf("%s", s.classe);
        written = fwrite(&s, sizeof(studente), 1, outf);
        if(written != 1) {
            fprintf(stderr, "Errore di scrittura nel file\n");
            exit(2);
        }
        else {
            printf("Dato scritto\n");
        }
    }
    
    fclose(outf);
    printf("Dati salvati in %s\n", FNAME);
    return (EXIT_SUCCESS);
}