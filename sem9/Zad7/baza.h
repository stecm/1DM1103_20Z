#ifndef _BAZA_H
#define _BAZA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _Student {
    char * imie;
    char * nazwisko;
    char * nr_albumu;
    char * email;

    struct _Student *nast;
} Student;

typedef struct _Przedmiot {
    char * kod_przed;
    char * nazwa;
    int * sem;

    struct _Przedmiot *nast;
} Przedmiot;

typedef struct _Ocena {
    char * nr_albumu;
    char * kod_przed;
    float * grade;
    char * komentarz;

    struct _Ocena *nast;
} Ocena;


typedef struct _SBaza {
    Student *lista_studentow;
    Student *lista_przedmiotow;
    Student *lista_ocen;
} SBaza;

SBaza * wczytaj_baze(char *nazwa_pliku);
SBaza * zapisz_baze(char *nazwa_pliku, SBaza * baza);
void listuj_studentow(SBaza *baza);
void zwolnij(SBaza *baza);
int ile_studentow(SBaza *baza);

#endif
