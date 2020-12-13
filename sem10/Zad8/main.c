#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "baza.h"

int main(int argc, char ** argv) {
    SBaza *baza;
    baza = wczytaj_baze(argv[1]);

    if (strcmp("list_students", argv[2]) == 0) {
        listuj_studentow(baza);


    } else if (strcmp("list_students_nazw_rosnaco", argv[2]) == 0) {
        listuj_studentow_nazwisko_rosnaco(baza);
    } else if (strcmp("list_students_nazw_malejaco", argv[2]) == 0) {
        listuj_studentow_nazwisko_malejaco(baza);

    } else if (strcmp("list_students_from_end", argv[2]) == 0) {
        listuj_studentow_od_konca(baza);
    } else if (strcmp("sort_descending", argv[2]) == 0) {
        baza->lista_studentow = sortuj_przez_wybieranie(baza->lista_studentow); 
        listuj_studentow(baza);
    } else if (strcmp("add_student", argv[2]) == 0) {
        // dodaj_studenta(baza, argv[3], argv[4], argv[5], argv[6]);
    } else if (strcmp("count_students", argv[2]) == 0) {
        printf("Liczba studentów: %d\n", ile_studentow(baza));
    }


    } else if (strcmp("przedmioty_sortowane_po_kodzie", argv[2]) == 0) {
        przedmioty_sortowane_po_kodzie(baza));
    }
    } else if (strcmp("przedmioty_sortowane_po_nazwie", argv[2]) == 0) {
        przedmioty_sortowane_po_nazwie(baza));
    }
    } else if (strcmp("przedmiot_o_zadanym_kodzie", argv[2]) == 0) {
        przedmiot_o_zadanym_kodzie(baza));
    }
    } else if (strcmp("oceny_danego_studenta", argv[2]) == 0) {
        oceny_danego_studenta(baza));
    }



    zapisz_baze(argv[1], baza);
    zwolnij(baza);
    return 0;
}
