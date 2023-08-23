#include "String.hpp"

/*****Nombre***************************************
 * Constructor
 *****Descripción**************************************
 * Constructor de la clase STRING. Inicializa el objeto
 * con el contenido del input proporcionado.
 *****Retorno**************************************
 * 
 *****Entradas*************************************
 * input: Puntero al arreglo de caracteres de entrada.
 **************************************************/

STRING::STRING(char* input) {
    int indice = 0;
    
    // Calcular el largo del input
    while (input[indice] != '\0') {
        indice++;
    }

    // Asignar memoria dinámica para el puntero texto
    this->apTexto = new char[indice + 1]; // +1 para el caracter nulo '\0'

    // Copiar el contenido de input
    for (int i = 0; i <= indice; ++i) {
        this->apTexto[i] = input[i];
    }

    this->aLargo = indice;
}


/*****Nombre***************************************
 * Destructor
 *****Descripción**************************************
 * Destructor de la clase STRING. Libera la memoria
 * asignada para el puntero de texto.
 *****Retorno**************************************
 * 
 *****Entradas*************************************
 * 
 **************************************************/

STRING::~STRING() {
    delete[] this->apTexto;
}


/*****Nombre***************************************
 * imprimir
 *****Descripción**************************************
 * Imprime el contenido del objeto STRING en la consola.
 *****Retorno**************************************
 * 
 *****Entradas*************************************
 * 
 **************************************************/

void STRING::imprimir() {
    std::cout << "Texto: " << this->apTexto << std::endl;
}


/*****Nombre***************************************
 * caracterEn()
 *****Descripción**************************************
 * Retorna el caracter en el índice especificado dentro
 * del objeto STRING.
 *****Retorno**************************************
 * Caracter según el indice
 *****Entradas*************************************
 * indice: Índice del caracter que se desea obtener.
 **************************************************/

char STRING::caracterEn(int indice) {
    if (indice >= 0 && indice < aLargo) {
        return apTexto[indice];
    } else {
        return '\0'; // Caracter nulo en caso de índice inválido
    }
}


/*****Nombre***************************************
 * contarCaracter()
 *****Descripción**************************************
 * Retorna la cantidad de ocurrencias del caracter
 * especificado en el objeto STRING.
 *****Retorno**************************************
 * Cantidad de ocurrencias del caracter.
 *****Entradas*************************************
 * caracter: Caracter que se desea contar.
 **************************************************/

int STRING::contarCaracter(char pCaracter) {
    int contador = 0;
    for (int i = 0; i < aLargo; ++i) {
        if (apTexto[i] == pCaracter) {
            contador++;
        }
    }
    return contador;
}


/*****Nombre***************************************
 * len()
 *****Descripción**************************************
 * Retorna la cantidad de caracteres en el objeto STRING.
 *****Retorno**************************************
 * Cantidad de caracteres en el objeto STRING.
 *****Entradas*************************************
 * 
 **************************************************/

int STRING::len() {
    return aLargo;
}


/*****Nombre***************************************
 * split()
 *****Descripción**************************************
 * Retorna un arreglo de punteros a STRING que contiene
 * las subcadenas resultantes de dividir el objeto STRING
 * usando el separador especificado.
 *****Retorno**************************************
 * Arreglo de punteros a STRING con las subcadenas.
 *****Entradas*************************************
 * separador: Caracter que se utiliza como separador.
 **************************************************/

STRING** STRING::split(char pSeparador) {
    int cantidad = contarCaracter(pSeparador) + 1; // Calcula la cantidad de subcadenas
    STRING** lista = new STRING*[cantidad]; // Crea un arreglo de punteros a STRING

    int inicio = 0;
    int indice = 0;
    int i = 0;
    while (i <= aLargo) {
        if (apTexto[i] == pSeparador || apTexto[i] == '\0') {
            int longitudSubcadena = i - inicio;
            char* subcadena = new char[longitudSubcadena + 1]; // +1 para el caracter nulo
            for (int j = 0; j < longitudSubcadena; ++j) {
                subcadena[j] = apTexto[inicio + j];
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


/*****Nombre***************************************
 * reemplazarOcurrencias()
 *****Descripción**********************************
 * Este método reemplaza todas las ocurrencias de una cadena de caracteres 'anterior'
 * en el texto original con otra cadena de caracteres 'nuevo'. Busca todas las ocurrencias
 * de 'anterior' en el texto original y las reemplaza por 'nuevo'.
 *****Retorno**************************************
 * La cadena de caracteres con las sustituciones de las ocurrencias
 *****Entradas*************************************
 * anterior: La cadena de caracteres que se busca reemplazar en el texto original.
 * nuevo: La cadena de caracteres que se utilizará para reemplazar las ocurrencias de 'anterior'.
 **************************************************/

void STRING::reemplazarOcurrencias(const char *pAnterior, const char *pNuevo) {
    int largoAnterior = 0;
    while (pAnterior[largoAnterior] != '\0') {
        largoAnterior++;
    }

    int largoNuevo = 0;
    while (pNuevo[largoNuevo] != '\0') {
        largoNuevo++;
    }

    int i = 0;
    while (i < aLargo) {
        bool encontrado = true;
        for (int j = 0; j < largoAnterior; ++j) {
            if (apTexto[i + j] != pAnterior[j]) {
                encontrado = false;
                break;
            }
        }

        if (encontrado) {
            // Crear un nuevo arreglo para almacenar el string resultante
            char *nuevoTexto = new char[aLargo - largoAnterior + largoNuevo + 1];

            // Copiar la parte antes de la ocurrencia
            for (int j = 0; j < i; ++j) {
                nuevoTexto[j] = apTexto[j];
            }

            // Copiar la cadena nueva
            for (int j = 0; j < largoNuevo; ++j) {
                nuevoTexto[i + j] = pNuevo[j];
            }

            // Copiar la parte después de la ocurrencia
            for (int j = i + largoAnterior; j < aLargo; ++j) {
                nuevoTexto[j + largoNuevo - largoAnterior] = apTexto[j];
            }

            nuevoTexto[aLargo - largoAnterior + largoNuevo] = '\0'; // Agregar el caracter nulo

            // Liberar la memoria del antiguo arreglo y asignar la nueva
            delete[] apTexto;
            apTexto = nuevoTexto;

            // Actualizar el valor de 'largo'
            aLargo = aLargo - largoAnterior + largoNuevo;
            
            i += largoNuevo; // Avanzar después de la ocurrencia
        } else {
            i++;
        }
    }
}


/*****Nombre***************************************
 * concatenarCadenas()
 *****Descripción**********************************
 * Este método concatena un arreglo de cadenas de caracteres al final del string original.
 * Recorre cada cadena en el arreglo y las agrega consecutivamente al final del string original,
 * actualizando el largo total del string resultante.
 *****Retorno**************************************
 *
 *****Entradas*************************************
 * pCadenas: Un arreglo de punteros a cadenas de caracteres (char**). Cada elemento del arreglo
 * es un puntero a una cadena de caracteres que se desea concatenar.
 **************************************************/

void STRING::concatenarCadenas(char **pCadenas) {
    int nuevoLargo = aLargo;

    // Calcular el nuevo largo total
    for (int i = 0; pCadenas[i] != nullptr; ++i) {
        int cadenaLargo = 0;
        while (pCadenas[i][cadenaLargo] != '\0') {
            cadenaLargo++;
        }
        nuevoLargo += cadenaLargo;
    }

    // Crear un nuevo arreglo de caracteres para almacenar el string concatenado
    char *pNuevoTexto = new char[nuevoLargo + 1];
    int indice = 0;

    // Copiar el contenido del string original
    for (int i = 0; i < aLargo; ++i) {
        pNuevoTexto[indice] = apTexto[i];
        indice++;
    }

    // Copiar el contenido de las cadenas del arreglo
    for (int i = 0; pCadenas[i] != nullptr; ++i) {
        int cadenaLargo = 0;
        while (pCadenas[i][cadenaLargo] != '\0') {
            pNuevoTexto[indice] = pCadenas[i][cadenaLargo];
            indice++;
            cadenaLargo++;
        }
    }

    pNuevoTexto[indice] = '\0';

    // Liberar memoria del string original y actualizar atributos
    delete[] apTexto;
    apTexto = pNuevoTexto;
    aLargo= nuevoLargo;
}
