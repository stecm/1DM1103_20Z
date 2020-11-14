/**
Mamy mini bazę studentów (tabelę z studentami, przedmiotami i ocenami)
Cel: obliczyć ranking.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _student {
    char imie[25];
    char nazwisko[50];
    char nr_albumu[10];
    char kod_przed[10];
    char nazwa_przed[255];
    float ocena;
    int ects;
} student, *pstudent;

int wczytaj(student dane[100], char *fnazwa) {
    FILE * fin = fopen(fnazwa, "r");
    int cnt, i;
    char bufor[1024];
    char *w;

    fgets(bufor, 1023, fin);
    sscanf(bufor, "%d", &cnt);
 
    for (i=0; i<cnt; i++) {
        fgets(bufor, 1023, fin);
        // printf("%s", bufor);
        w = strtok(bufor, "|");
        strncpy(dane[i].imie, w, 24);

        w = strtok(NULL, "|");
        strncpy(dane[i].nazwisko, w, 49);
        
        w = strtok(NULL, "|");
        strncpy(dane[i].nr_albumu, w, 9);

        w = strtok(NULL, "|");
        strncpy(dane[i].kod_przed, w, 9);

        w = strtok(NULL, "|");
        strncpy(dane[i].nazwa_przed, w, 254);

        w = strtok(NULL, "|");
        dane[i].ocena = atof(w);

        w = strtok(NULL, "|");
        dane[i].ects = atoi(w);
    }

    fclose(fin);
    return cnt;
}

void wypisz(student dane[100], int n) {
    int i;
    for (i=0; i<n;i++) {
        printf("{ Przedmiot: %s - %s %s, z przedmiotu: [%s] %s za ECTS: %d otrzymał %.1f\n",
            dane[i].nr_albumu, dane[i].imie, dane[i].nazwisko,
            dane[i].kod_przed, dane[i].nazwa_przed,
            dane[i].ects, dane[i].ocena
        );
    }
}

int znajdz(char *szukany_nr, char nr_albumow[100][10], int n) {
    int i;
    for (i=0; i<n; i++) {
        if (strcmp(szukany_nr, nr_albumow[i]) == 0)
            return i;
    }
    return -1;
}

int znajdz_przedmioty(char kody_przedmiotow[100][10], student dane[100], int n) {
    int ile_znalazlem = 0;
    int i;

    for (i=0; i <n; i++) {
        if (znajdz(dane[i].kod_przed, kody_przedmiotow, ile_znalazlem ) == -1) {
            strncpy(kody_przedmiotow[ile_znalazlem], dane[i].kod_przed, 9);
            ile_znalazlem++;
        }
    }
    return ile_znalazlem;
}


void najlepszy_przedmiot(student dane[100], int ile_rekordow) {
    char kody_przedmiotow[100][10];
    char nazwy_przedmiotow[100][30];
    int ile_przedmiotow;
    float sumy_ocen[100];
    int liczba_wystapien[100];
    float srednie[100];
    int i,j=0;
    int pozycja;
    int najlepsza_pozycja, najgorsza_pozycja;
    float najlepsza = 0.0f;
    float najgorsza = 0.0f;

    ile_przedmiotow = znajdz_przedmioty(kody_przedmiotow, dane, ile_rekordow);
for (i=0; i < ile_rekordow; i++) {liczba_wystapien[i]=0;}//konieczne bylo zresetowanie wartosci w tym wektorze bo dzialy sie dziwne rzeczy
    for (i=0; i < ile_rekordow; i++) {
        pozycja = znajdz( dane[i].kod_przed, kody_przedmiotow, ile_przedmiotow );
        liczba_wystapien[pozycja]=liczba_wystapien[pozycja]+1;// if (pozycje >= 0)
        sumy_ocen[pozycja] = sumy_ocen[pozycja]+dane[i].ocena;
        strncpy(nazwy_przedmiotow[pozycja], dane[i].nazwa_przed, 28);
        // nazwy_przedmiotow[pozycja]=dane[1].nazwa_przed;
       // if(liczba_wystapien[pozycja]==0){liczba_wystapien[pozycja]=1;}
        
        
       // printf("Dane z FOR: licznik petli: %d, pozycja: %d, sumy_ocen %f, liczba_wystapien %d, kod przedmiotu: %s, nazawa przed: %s\n", 
       // i, pozycja, sumy_ocen[pozycja], liczba_wystapien[pozycja], dane[i].kod_przed, nazwy_przedmiotow[pozycja]);
    }  

   

    
    for (i=0;i<ile_przedmiotow; i++) 
        // printf("Student [%d]: %s - %f:%d - %f \n", i+1, kody_przedmiotow[i], 
        // sumy_wazonych_ocen[i], sumy_ects[i], sumy_wazonych_ocen[i] / sumy_ects[i]);

    for (i=0; i < ile_przedmiotow; i++) {
        if (najlepsza < sumy_ocen[i] / liczba_wystapien[i]) {
            najlepsza = sumy_ocen[i] / liczba_wystapien[i];
            najlepsza_pozycja = i;
           
        }
    }
    najgorsza = sumy_ocen[0] / liczba_wystapien[0];
    for (i=0; i < ile_przedmiotow; i++) {
        if (najgorsza > sumy_ocen[i] / liczba_wystapien[i]) {
            najgorsza = sumy_ocen[i] / liczba_wystapien[i];
            najgorsza_pozycja = i;
           
        }
    }
    printf("Najlepsza srednia: %s %s: %f \n", 
        kody_przedmiotow[najlepsza_pozycja], nazwy_przedmiotow[najlepsza_pozycja],
        sumy_ocen[najlepsza_pozycja] / liczba_wystapien[najlepsza_pozycja]);
printf("Najgorsza srednia: %s %s: %f \n", 
        kody_przedmiotow[najgorsza_pozycja], nazwy_przedmiotow[najgorsza_pozycja],
        sumy_ocen[najgorsza_pozycja] / liczba_wystapien[najgorsza_pozycja]);

}

int main(int argc, char ** argv) {
    student dane[100];
    int ile;
    // dane == &dane[0]
    ile = wczytaj(dane, argv[1]);
    // wypisz(dane, ile);

    najlepszy_przedmiot(dane, ile);

    return 0;
}