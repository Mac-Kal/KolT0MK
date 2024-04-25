#ifndef PROGRAM_H
#define PROGRAM_H

#include <iostream>
#include <fstream>
#include <string>

struct StructInt {
    int* tablica;
    int rozmiar;
};

StructInt uzupelnij(int rozmiar);
void zwolnij(StructInt& Ints);
void zapisdopliku(const char* plik1, const StructInt& Ints);
StructInt odczytajzpliku(const char* plik1);

#endif // PROGRAM_H
