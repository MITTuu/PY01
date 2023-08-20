#include <iostream>
#include <cstdio>

class STRING{
    private: 
    char* texto; 
    int largo;

    public:
    STRING(char*);
    ~STRING();
    int getlargo();
    void imprimir();
};