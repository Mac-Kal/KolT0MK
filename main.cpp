#include "program.h"

int main() {
    const char* plik1 = "tablica.txt";
    StructInt Ints = uzupelnij(5);
    for (int i = 0; i < Ints.rozmiar; i++) {
        Ints.tablica[i] = i * 2;
    }
    zapisdopliku(plik1, Ints);

    StructInt odczytanatab = odczytajzpliku(plik1);

    bool czyRowne = true;
    if (Ints.rozmiar != odczytanatab.rozmiar) {
        czyRowne = false;
    }
    else {
        for (int j = 0; j < Ints.rozmiar; j++) {
            if (Ints.tablica[j] != odczytanatab.tablica[j]) {
                czyRowne = false;
                break;
            }
        }
    }

    if (czyRowne) {
        std::cout << "Tablica odczytana jest rowna oryginalnej" << std::endl;
    }
    else {
        std::cout << "Tablica odczytana nie jest rowna oryginalnej" << std::endl;
    }

    zwolnij(Ints);
    zwolnij(odczytanatab);

    return 0;
}
