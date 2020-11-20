
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


void najgorszy_przedmiot(student dane[100], int ile_rekordow) {
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


           
        }
    }
    najgorsza = sumy_ocen[0] / liczba_wystapien[0];
    for (i=0; i < ile_przedmiotow; i++) {
        if (najgorsza > sumy_ocen[i] / liczba_wystapien[i]) {
            najgorsza = sumy_ocen[i] / liczba_wystapien[i];
            najgorsza_pozycja = i;
           
        }
    }

printf("Najgorsza srednia: %s %s: %f \n", 
        kody_przedmiotow[najgorsza_pozycja], nazwy_przedmiotow[najgorsza_pozycja],
        sumy_ocen[najgorsza_pozycja] / liczba_wystapien[najgorsza_pozycja]);

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


    printf("Najlepsza srednia: %s %s: %f \n", 
        kody_przedmiotow[najlepsza_pozycja], nazwy_przedmiotow[najlepsza_pozycja],
        sumy_ocen[najlepsza_pozycja] / liczba_wystapien[najlepsza_pozycja]);

}