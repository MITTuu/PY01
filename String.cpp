#include "String.hpp"

// Constructor
STRING::STRING(char* input) {
    int index = 0;
    
    for (index = 0; input[index] != '\0'; ++index) {
        this->texto[index] = input[index];
    }

    this->texto[index] = '\0';  
    this->largo = index; 
}

// Destructor
STRING::~STRING() {
    delete[] this->texto;
}
