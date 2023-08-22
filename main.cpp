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

    return 0;

    // implementación del método split()
    char separador = 'e';

    STRING** listaSubcadenas = str1.split(separador);

    // Imprimir las subcadenas usando un bucle while
    int indice2 = 0;
    while (listaSubcadenas[indice2] != nullptr) {
        listaSubcadenas[indice2]->imprimir();
        indice2++;
    }

    // Liberar memoria
    indice2 = 0;
    while (listaSubcadenas[indice2] != nullptr) {
        delete listaSubcadenas[indice2];
        indice2++;
    }
    delete[] listaSubcadenas;

}


// Compilar
// bcc32c String.cpp main.cpp -o main.exe
// .\main.exe
