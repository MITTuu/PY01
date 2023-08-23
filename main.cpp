#include "String.hpp"
#include <iostream>

int main() {

    // implementaci贸n del constructor
    STRING str1 = STRING((char*)"OnePiece");
    
    str1.imprimir();
    
    // implementaci贸n del m茅todo caracterEn()
    int indice1 = 3; // 脥ndice para obtener el cuarto caracter
    char caracter = str1.caracterEn(indice1);

    if (caracter != '\0') {
        std::cout << "El caracter en el 铆ndice " << indice1 << " es: " << caracter << std::endl;
    } else {
        std::cout << "脥ndice inv谩lido." << std::endl;
    }

    //implementaci贸n del m茅todo contarCaracter()
    char caracterBuscado = 'e';
    int cantidad = str1.contarCaracter(caracterBuscado);

    std::cout << "El caracter '" << caracterBuscado << "' aparece " << cantidad << " veces." << std::endl;
    
    //Implementaci髇 del m閠odo ultimoIndice();
    std::cout <<"\n";
    str1.ultimoIndice((char*)"e");
    
    
    // implementaci贸n del m茅todo len()
    std::cout <<"\n";
    int longitud = str1.len();

    std::cout << "Cantidad de catacteres: " << longitud << std::endl;
    
    //Implementaci髇 del m閠odo equals(char *cadena)
    str1.equals((char*)"one");
    
    // implementaci贸n del m茅todo split()
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

    // implementaci贸n del m茅todo reemplazarOcurrencias()
    const char* anterior = "One";
    const char* nuevo = "Two";
    str1.reemplazarOcurrencias(anterior, nuevo);

    // Imprimir el resultado
    str1.imprimir();

    // implementaci贸n del m茅todo concatenarCadenas()
    char *pCadenas[] = {(char*)" mundo", (char*)"!", nullptr};
    str1.concatenarCadenas(pCadenas);

    str1.imprimir();

    // implementaci贸n del m茅todo cambiarCadena()
    char nuevaCadena[] = "NuevaCadena";
    str1.cambiarCadena(nuevaCadena);

    str1.imprimir();

    return 0;

}


// Compilar
// bcc32c String.cpp main.cpp -o main.exe
// .\main.exe
