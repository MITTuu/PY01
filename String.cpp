#include "String.hpp"

// Constructor
STRING::STRING(char* input) {
    int index = 0;
    
    // Calcular el largo del input
    while (input[index] != '\0') {
        index++;
    }

    // Asignar memoria dinámica para el puntero texto
    this->texto = new char[index + 1]; // +1 para el caracter nulo '\0'

    // Copiar el contenido de input
    for (int i = 0; i <= index; ++i) {
        this->texto[i] = input[i];
    }

    this->largo = index;
}

// Destructor
STRING::~STRING() {
    delete[] this->texto;
}

// Metodo imprimir
void STRING::imprimir() {
    std::cout << "Texto: " << this->texto << std::endl;
    std::cout << "Largo: " << this->largo << std::endl;
}
