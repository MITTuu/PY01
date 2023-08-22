#include "String.hpp"

// Constructor
STRING::STRING(char* input) {
    int indice = 0;
    
    // Calcular el largo del input
    while (input[indice] != '\0') {
        indice++;
    }

    // Asignar memoria dinámica para el puntero texto
    this->texto = new char[indice + 1]; // +1 para el caracter nulo '\0'

    // Copiar el contenido de input
    for (int i = 0; i <= indice; ++i) {
        this->texto[i] = input[i];
    }

    this->largo = indice;
}

// Destructor
STRING::~STRING() {
    delete[] this->texto;
}

// Metodo imprimir
void STRING::imprimir() {
    std::cout << "Texto: " << this->texto << std::endl;
}

// Método caracterEn
char STRING::caracterEn(int indice) {
    if (indice >= 0 && indice < largo) {
        return texto[indice];
    } else {
        return '\0'; // Caracter nulo en caso de índice inválido
    }
}

// Método contarCaracter
int STRING::contarCaracter(char caracter) {
    int contador = 0;
    for (int i = 0; i < largo; ++i) {
        if (texto[i] == caracter) {
            contador++;
        }
    }
    return contador;

}

// Método len
int STRING::len() {
    return largo;
}

// Método split
STRING** STRING::split(char separador) {
    int cantidad = contarCaracter(separador) + 1; // Calcula la cantidad de subcadenas
    STRING** lista = new STRING*[cantidad]; // Crea un arreglo de punteros a STRING

    int inicio = 0;
    int indice = 0;
    int i = 0;
    while (i <= largo) {
        if (texto[i] == separador || texto[i] == '\0') {
            int longitudSubcadena = i - inicio;
            char* subcadena = new char[longitudSubcadena + 1]; // +1 para el caracter nulo
            for (int j = 0; j < longitudSubcadena; ++j) {
                subcadena[j] = texto[inicio + j];
            }
            subcadena[longitudSubcadena] = '\0';
            
            lista[indice] = new STRING(subcadena); // Crea un nuevo STRING con la subcadena
            delete[] subcadena;

            inicio = i + 1;
            indice++;
        }
        i++;
    }

    return lista;
}
