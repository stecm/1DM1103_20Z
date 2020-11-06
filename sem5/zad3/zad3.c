#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
fin  = fopen(argv[2], "r");
        wczytaj(fin, &mac);
        wypisz(mac);
        printf("Norma macierzy %s = %f\n", argv[1], norm(mac));
        fclose(fin);
*/

int main(int argc, char *argv[]) 
{
    FILE * fin;

    if ( strcmp( argv[1], "sum") == 0)
    {
        sum(argv[2], argv[3])
        wypisz_wynik(wynik[i][j])
        zapisz_do_pliku("do_b.txt", wynik[i][j])
    } 
    else if ( strcmp( argv[1], "subtract") == 0) 
    {
        subtract(argv[2], argv[3])
        wypisz_wynik([i][j])
        zapisz_do_pliku("do_b.txt", wynik[i][j])
    }
    else if ( strcmp( argv[1], "multiply") == 0)
    {
        multiply(argv[2], argv[3])
        wypisz_wynik(wynik[i][j])
        zapisz_do_pliku("do_b.txt", wynik[i][j])
    }
    else if ( strcmp( argv[1], "norm") == 0) 
    {
        norm(argv[2], argv[3])
        wypisz_wynik(wynik[i][j])
        zapisz_do_pliku("do_b.txt", wynik[i][j]);
    }
    else
    {
        printf("blad\n", argv[1]);
    }    

    return 0;
}

float dodaj(int argc, char *argv[])
{
    FILE *a;
    FILE *x;
    a = fopen(argv[2], "r");
    x = fopen(argv[3], "r");

    int a_wiersz;
    int a_kolumna;
    int x_wiersz;
    int x_kolumna;
    fscanf(a, "%f, %f", &a_wiersz, &a_kolumna);
    fscanf(x, "%f, %f", &x_wiersz, &x_kolumna);
    int a[a_wiersz][a_kolumna];
    int x[x_wiersz][x_kolumna];
    int wynik[a_wiersz][a_kolumna];
    for(int i = 0; i < a_wiersz; i++)
    {
        for(int j = 0; j < x_wiersz; j++)
        {
            wynik[i][j] = a[i][j] + x[i][j];
        }
    }
    return wynik[i][j];
}

float subtract(int argc, char *argv[])
{
    FILE *a;
    FILE *x;
    a = fopen(argv[2], "r");
    x = fopen(argv[3], "r");

    int a_wiersz;
    int a_kolumna;
    int x_wiersz;
    int x_kolumna;
    fscanf(a, "%f, %f", &a_wiersz, &a_kolumna);
    fscanf(x, "%f, %f", &x_wiersz, &x_kolumna);
    int a[a_wiersz][a_kolumna];
    int x[x_wiersz][x_kolumna];
    int wynik[a_wiersz][a_kolumna];
    for(int i = 0; i < a_wiersz; i++)
    {
        for(int j = 0; j < x_wiersz; j++)
        {
            wynik[i][j] = a[i][j] - x[i][j];
        }
    }
    return wynik[i][j];
}

float multiply(int argc, char *argv[])
{
    FILE *a;
    FILE *x;
    a = fopen(argv[2], "r");
    x = fopen(argv[3], "r");

    int a_wiersz;
    int a_kolumna;
    int x_wiersz;
    int x_kolumna;
    fscanf(a, "%f, %f", &a_wiersz, &a_kolumna);
    fscanf(x, "%f, %f", &x_wiersz, &x_kolumna);
    int a[a_wiersz][a_kolumna];
    int x[x_wiersz][x_kolumna];
    int wynik[a_wiersz][a_kolumna];
    for(int i = 0; i < a_wiersz; i++)
    {
        for(int j = 0; j < x_wiersz; j++)
        {
            wynik[i][j] = a[i][j] * x[i][j];
        }
    }
    return wynik[i][j];
}

float norm(int argc, char *argv[])
{
    FILE *a;
    FILE *x;
    a = fopen(argv[2], "r");
    int a_wiersz;
    int a_kolumna;
    fscanf(a, "%f, %f", &a_wiersz, &a_kolumna);
    int a[a_wiersz][a_kolumna];
    int wynik[a_wiersz][a_kolumna];
    for(int i = 0; i < a_wiersz; i++)
    {
        for(int j = 0; j < a_wiersz; j++)
        {
            wynik[i][j] = a[i][j] * a[i][j];
        }
    }
    return sqrt(wynik[i][j]);
}

int wypisz_wynik(float wynik[i][j])
{
    for(int q = 0; q < i; q++)
    {
        for(int z = 0; z < j; j++)
        {
            printf("%f", wynik[q][z]);
        }
    }
}

int zapis_do_pliku(float wynik[i][j])
{
    FILE *plik;
    plik = fopen("argv[4]", "r");
    printf("%d", &plik);
}