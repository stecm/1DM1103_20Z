// Edycja Pana programu - p5_4.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct _mac {
    float **data;
    int r;
    int c;
} mac;


void zwolnij(mac)
{
    free(mac.r);
    free(mac.c);
    for(int i = 0; i < *mac.dane, i++)
        {
            free(tab[i]);
        }
}

int main(int argc, char *argv[]) {
    float **tablica;
    int i;
    tablica = (float*) malloc(sizeof(float*) * 25);
    for (i=0;i<25;i++)
        {
            tablica[i] = (float) malloc(sizeof(float) * 25);
        }

    if ( strcmp( argv[1], "norm") == 0) {
        fin  = fopen(argv[2], "r");
        wczytaj(fin, &mac);
        wypisz(mac);
        printf("Norma macierzy %s = %f\n", argv[1], norm(mac));
        fclose(fin);
        zwolnij(mac);
    } else if ( strcmp( argv[1], "suma") == 0) {
        fin  = fopen(argv[2], "r");
        wczytaj(fin, &mac);
        wypisz(mac);
        printf("Suma elementów macierzy %s = %f\n", argv[1], suma(mac));
        fclose(fin);
        zwolnij(mac);
    } else {
        printf("Nierozpoznany argument %s, Oczekiwałem: norm.\n", argv[1]);
    }    

    zapisz("wynik.txt", mac);
    return 0;
}