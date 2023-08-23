#include "String.hpp"
#include <iostream>

int main() {

    // implementación del constructor
    STRING str1 = STRING((char*)"OnePiece");
    
    str1.imprimir();
    
    // implementación del método caracterEn()
    int indice1 = 3; // Índice para obtener el cuarto caracter
    char caracter = str1.caracterEn(indice1);

    if (caracter != '\0') {
        std::cout << "El caracter en el índice " << indice1 << " es: " << caracter << std::endl;
    } else {
        std::cout << "Índice inválido." << std::endl;
    }

    //implementación del método contarCaracter()
    char caracterBuscado = 'e';
    int cantidad = str1.contarCaracter(caracterBuscado);

    std::cout << "El caracter '" << caracterBuscado << "' aparece " << cantidad << " veces." << std::endl;

    // implementación del método len()
    int longitud = str1.len();

    std::cout << "Cantidad de catacteres: " << longitud << std::endl;

    // implementación del método split()
    char separador = 'e';

    STRING** subcadenas = str1.split(separador);
    for (int i = 0; subcadenas[i] != nullptr; ++i) {
        subcadenas[i]->imprimir();
    }

    // Liberar la memoria asignada para las subcadenas
    for (int i = 0; subcadenas[i] != nullptr; ++i) {
        delete subcadenas[i];
    }
    delete[] subcadenas;

    // implementación del método reemplazarOcurrencias()
    const char* anterior = "One";
    const char* nuevo = "Two";
    str1.reemplazarOcurrencias(anterior, nuevo);

    // Imprimir el resultado
    str1.imprimir();

    // implementación del método concatenarCadenas()
    char *pCadenas[] = {(char*)" mundo", (char*)"!", nullptr};
    str1.concatenarCadenas(pCadenas);

    str1.imprimir();

    return 0;

}


// Compilar
// bcc32c String.cpp main.cpp -o main.exe
// .\main.exe
