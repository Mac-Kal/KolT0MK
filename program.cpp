#include "program.h"

StructInt uzupelnij(int rozmiar) {
    StructInt Ints;
    Ints.rozmiar = rozmiar;
    Ints.tablica = new int[rozmiar](); 
    return Ints;
}

void zwolnij(StructInt& Ints) {
    delete[] Ints.tablica;
    Ints.tablica = nullptr;
}

void zapisdopliku(const char* plik1, const StructInt& Ints) {
    std::ofstream outFile(plik1);
    if (outFile.is_open()) {
        outFile << Ints.rozmiar << std::endl;
        for (int i = 0; i < Ints.rozmiar; i++) {
            outFile << Ints.tablica[i] << " ";
        }
        outFile.close();
    }
    else {
        std::cerr << "Nie da sie zapisac do pliku!" << std::endl;
    }
}

StructInt odczytajzpliku(const char* plik1) {
    StructInt Ints;
    std::ifstream inFile(plik1);
    if (inFile.is_open()) {
        inFile >> Ints.rozmiar;
        Ints.tablica = new int[Ints.rozmiar];
        for (int i = 0; i < Ints.rozmiar; i++) {
            inFile >> Ints.tablica[i];
        }
        inFile.close();
    }
    else {
        std::cerr << "Nie da sie odczytac z pliku!" << std::endl;
    }
    return Ints;
}
