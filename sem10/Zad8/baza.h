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

    struct _Student *poprz;
    struct _Student *nast;
} Student;

typedef struct _Przedmiot {
    char * kod_przed;
    char * nazwa;
    int * sem;

    struct _Przedmiot *nast;
} Przedmiot;


typedef struct _SBaza {
    Student *lista_studentow; /* Głowa listy! */
} SBaza;

SBaza * wczytaj_baze(char *nazwa_pliku);
SBaza * zapisz_baze(char *nazwa_pliku, SBaza * baza);
void listuj_studentow(SBaza *baza);
void listuj_studentow_od_konca(SBaza *baza);
void zwolnij(SBaza *baza);
int ile_studentow(SBaza *baza);
Student * sortuj_przez_wybieranie(Student *glowa);

Student *listuj_studentow_nazwisko_malejaco(SBaza *baza);
Student *listuj_studentow_nazwisko_rosnaco(SBaza *baza);

Przedmiot *przedmioty_sortowane_po_kodzie(SBaza *baza);
Przedmiot *przedmioty_sortowane_po_nazwie(SBaza *baza);

Przedmiot *przedmiot_o_zadanym_kodzie(SBaza *baza);
Student *oceny_danego_studenta(SBaza *baza);

#endif
 