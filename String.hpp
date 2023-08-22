#include <iostream>
#include <cstdio>

class STRING {
private:
    char* texto;
    int largo;

public:
    STRING(char*);
    ~STRING();
    int getlargo();
    void imprimir();
    char caracterEn(int indice);
    int contarCaracter(char caracter);
    int len();
    STRING** split(char separador);
};
