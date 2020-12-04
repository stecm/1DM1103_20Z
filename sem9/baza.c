#include "baza.h"

Student * wczytaj_studentow(FILE *fin) {
    char bufor[255];
    int n, i;
    char *s;
    Student *last_student = NULL;
    Student *glowa = NULL;
    fgets(bufor, 254, fin);
    sscanf(bufor, "%d", &n);

    for (i=0; i<n; i++) {
        Student *stud = (Student*) malloc(sizeof(Student));
        stud->nast = NULL;

        if (last_student == NULL)
            glowa = stud;
        else
            last_student->nast = stud;
        last_student = stud;

        fgets(bufor, 254, fin);
        s = strtok(bufor, ";");
        stud->nr_albumu = (char*) malloc( sizeof(char) * (strlen(s) + 1));
        strcpy(stud->nr_albumu, s);

        s = strtok(NULL, ";");
        stud->imie = (char*) malloc( sizeof(char) * (strlen(s) + 1));
        strcpy(stud->imie, s);

        s = strtok(NULL, ";");
        stud->nazwisko = (char*) malloc( sizeof(char) * (strlen(s) + 1));
        strcpy(stud->nazwisko, s);

        s = strtok(NULL, "\n");
        stud->email = (char*) malloc( sizeof(char) * (strlen(s) + 1));
        strcpy(stud->email, s);
    }

    return glowa;
}

Student * wczytaj_przedmioty(FILE *fin) {
    char bufor[255];
    int n, i;
    char *p;
    Przedmiot *last_przedmiot = NULL;
    Przedmiot *glowa = NULL;
    fgets(bufor, 254, fin);
    sscanf(bufor, "%d", &n);

    for (i=0; i<n; i++) {
        Przedmiot *przed = (Przedmiot*) malloc(sizeof(Przedmiot));
        przed->nast = NULL;

        if (last_przedmiot == NULL)
            glowa = przed;
        else
            last_przedmiot->nast = przed;
        last_przedmiot = przed;

        fgets(bufor, 254, fin);
        p = strtok(bufor, ";");
        przed->kod_przed = (char*) malloc( sizeof(char) * (strlen(p) + 1));
        strcpy(przed->kod_przed, p);

        p = strtok(NULL, ";");
        przed->nazwa = (char*) malloc( sizeof(char) * (strlen(p) + 1));
        strcpy(przed->nazwa, p);

        p = strtok(NULL, ";");
        przed->sem = (int*) malloc( sizeof(int) * (strlen(p) + 1));  
        strcpy(przed->sem, p);

    }

    return glowa;
}


Student * wczytaj_oceny(FILE *fin) {
    char bufor[255];
    int n, i;
    char *o;
    Ocena *last_ocena = NULL;
    Ocena *glowa = NULL;
    fgets(bufor, 254, fin);
    sscanf(bufor, "%d", &n);

    for (i=0; i<n; i++) {
        Ocena *ocena_ = (Ocena*) malloc(sizeof(Ocena));
        ocena_->nast = NULL;

        if (last_ocena == NULL)
            glowa = ocena_;
        else
            last_ocena->nast = ocena_;
        last_ocena = ocena_;

        fgets(bufor, 254, fin);
        o = strtok(bufor, ";");
        ocena_->nr_albumu = (char*) malloc( sizeof(char) * (strlen(o) + 1));
        strcpy(ocena_->nr_albumu, o);

        o = strtok(NULL, ";");
        ocena_->kod_przed = (char*) malloc( sizeof(char) * (strlen(o) + 1));
        strcpy(ocena_->kod_przed, o);

        o = strtok(NULL, ";");
        ocena_->grade = (float*) malloc( sizeof(float) * (strlen(o) + 1));  
        strcpy(ocena_->grade, o);

        o = strtok(NULL, ";");
        ocena_->komentarz = (char*) malloc( sizeof(char) * (strlen(o) + 1));  
        strcpy(ocena_->komentarz, o);
    }

    return glowa;
}


SBaza * wczytaj_baze(char *nazwa_pliku) {
    FILE *fin = fopen(nazwa_pliku, "r");
    if (fin == NULL) {
        printf("BŁĄD! Nie moge otworzyc pliku: %s.\n", nazwa_pliku);
        exit(-1);
    }

    SBaza *baza = (SBaza*) malloc( sizeof(SBaza) );
    baza->lista_studentow = wczytaj_studentow(fin);
    baza->lista_przedmiotow = wczytaj_przedmioty(fin);
    baza->lista_ocen = wczytaj_oceny(fin);

    fclose(fin);
    return baza;
}

SBaza * zapisz_baze(char *nazwa_pliku, SBaza * baza) {
    return NULL;
}

int ile_studentow(SBaza *baza) {
    int n = 0;
    Student * stud = baza->lista_studentow;
    while (stud != NULL) {
        n++;
        stud = stud->nast;
    }
    return n;
}

void listuj_studentow(SBaza *baza) {
    Student * stud = baza->lista_studentow;
    while (stud != NULL) {
        printf("%s %s %s %s\n", stud->imie, stud->nazwisko, stud->nr_albumu, stud->email);
        stud = stud->nast;
    }
}

void zwolnij_student(Student *s) {
    free(s->imie);
    free(s->nazwisko);
    free(s->nr_albumu);
    free(s->email);
    free(s);
}

void zwolnij_liste_studentow(Student *s) {
    Student *n;
    while (s != NULL) {
        n = s->nast;
        zwolnij_student(s);
        s = n;
    }
}

void zwolnij(SBaza *baza) {
    zwolnij_liste_studentow(baza->lista_studentow);
    free(baza);
}





void zwolnij_przedmiot(Przedmiot *p) {
    free(p->kod_przed);
    free(p->nazwa);
    free(p->sem);
    free(p);
}

void zwolnij_liste_przedmiotow(Przedmiot *p) {
    Przedmiot *n;
    while (p != NULL) {
        n = p->nast;
        zwolnij_przedmiot(p);
        p = n;
    }
}

void zwolnij(SBaza *baza) {
    zwolnij_liste_przedmiotow(baza->lista_przedmiotow);
    free(baza);
}





void zwolnij_ocene(Ocena *o) {
    free(o->nr_albumu);
    free(o->kod_przed);
    free(o->grade);
    free(o->komentarz);
    free(o);
}

void zwolnij_liste_ocen(Przedmiot *o) {
    Przedmiot *n;
    while (o != NULL) {
        n = o->nast;
        zwolnij_ocene(o);
        o = n;
    }
}


void dodaj_studenta(baza, char *argv[3], char *argv[4], char **argv[5], char *argv[6]);
{
    Student->imie = *argv[3];
    Student->nazwisko = argv[4];
    Student->nr_albumu = argv[5];
    Student->email = argv[6];
}

void dodaj_studenta(baza, argv[3], argv[4], argv[5]);
{
    Student->kod_przed = *argv[3];
    Student->nazwa = argv[4];
    Student->sem = argv[5];
}

