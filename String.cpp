#include "String.hpp"

/*****Nombre***************************************
 * Constructor
 *****DescripciÃ³n**************************************
 * Constructor de la clase STRING. Inicializa el objeto
 * con el contenido del input proporcionado.
 *****Retorno**************************************
 * 
 *****Entradas*************************************
 * input: Puntero al arreglo de caracteres de entrada.
 **************************************************/

STRING::STRING(char *pEntrada) {
    int indice = 0;
    
    // Calcular el largo del input
    while (pEntrada[indice] != '\0') {
        indice++;
    }

    // Asignar memoria dinÃ¡mica para el puntero texto
    this->apTexto = new char[indice + 1]; // +1 para el caracter nulo '\0'

    // Copiar el contenido de input
    for (int i = 0; i <= indice; ++i) {
        this->apTexto[i] = pEntrada[i];
    }

    this->aLargo = indice;
}


/*****Nombre***************************************
 * Destructor
 *****DescripciÃ³n**************************************
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
 *****DescripciÃ³n**************************************
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
* calcularLargo
*****Descripción**********************************
* Este metodo recibe como paramatro un tipo char*,
*  dicho metodo cuenta la cantidad de
* elementos del parametro char *pCadena.
*****Retorno**************************************
* int largo
*****Entradas*************************************
* const char* pCadena
**************************************************/

int STRING::calcularLargo(const char *pCadena) {
    int largo = 0;
    for (int i = 0; pCadena[i] != '\0'; ++i) {
        ++largo;
    }
    return largo;
}

/*****Nombre***************************************
 * caracterEn()
 *****DescripciÃ³n**************************************
 * Retorna el caracter en el Ã­ndice especificado dentro
 * del objeto STRING.
 *****Retorno**************************************
 * Caracter segÃºn el indice
 *****Entradas*************************************
 * indice: Ãndice del caracter que se desea obtener.
 **************************************************/

char STRING::caracterEn(int indice) {
    if (indice >= 0 && indice < aLargo) {
        return apTexto[indice];
    } else {
        return '\0'; // Caracter nulo en caso de Ã­ndice invÃ¡lido
    }
}


/*****Nombre***************************************
 * contarCaracter()
 *****DescripciÃ³n**************************************
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
 * ultimoIndice()
 *****DescripciÃ³n**************************************
 * Retorna la Ãºltima apariciÃ³n del caracter
 * de la entrada dentro de la cadena almacenada
 * en el constructor
 *****Retorno**************************************
 * El Ãºltimo Ã­ndice del caracter. En caso de que
 * no aparezca, un mensaje indicandolo 
 *****Entradas*************************************
 * char *caracter
 **************************************************/


//..................................................//
void STRING::ultimoIndice(char *caracter) {
     //Verificar que solo se ingrese un caracter
     int iterador = 0;
     while(caracter[iterador] != '\0'){
        iterador++;
     }
     if (iterador >1){
        std::cout<<"Error, solo puede ingresar un caracter en la entrada del metodo";
        return;
     }
     char c1 = *caracter;
     char c2;
     int posicion = this->aLargo;
     iterador = 0;
     while(iterador < this->aLargo){ //Se itera cada caracter de la cadena almacernada en el constructor
        c2 = this->apTexto[iterador];
        if (c1 == c2){
            posicion = iterador;
        }
        iterador++;
     }
     if(posicion == this->aLargo){ //En caso de que el valor de posicion no cambie, significa que el caracter nunca aparece
        std::cout<<"El caracter que ingreso nunca aparece en la cadena "<<this->apTexto;
        return;  
     }
     std::cout<<"El caracter "<<c1<<" aparece por ultima vez en la posicion "<<posicion; //posicion si cambió porque el caracter aparece
     return;
}	

/*****Nombre***************************************
 * cambiarCadena()
 *****DescripciÃ³n**************************************
 * 
 *****Retorno**************************************
 * 
 *****Entradas*************************************
 * 
 **************************************************/

// MÃ©todo cambiarCadena
void STRING::cambiarCadena(char *pNuevaCadena) {
    // Liberar memoria del string original y asignar memoria para el nuevo string
    delete[] apTexto;

    int indice = 0;
    while (pNuevaCadena[indice] != '\0') {
        indice++;
    }

    apTexto = new char[indice + 1]; // +1 para el caracter nulo '\0'

    // Copiar el contenido de la nueva cadena al string
    for (int i = 0; i <= indice; ++i) {
        apTexto[i] = pNuevaCadena[i];
    }

    aLargo = indice;
}


/*****Nombre***************************************
 * len()
 *****DescripciÃ³n**************************************
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
 * equals()
 *****DescripciÃ³n**************************************
 * Compara la cadena de la entrada con la almacenada
 * en el constructor del objeto
 *****Retorno**************************************
 * Un mensaje indicando que son iguales, en caso
 * de serlo.
 * Un mensaje indicando que no son iguales, en dicho
 * caso
 *****Entradas*************************************
 * char *cadena
 **************************************************/
void STRING::equals(char *cadena){
     int iterador = 0;
     while (cadena[iterador] != '\0') { //Se verifica primero que la cadena de la entrada tenga la misma longitud de la almacenada en el constructor
        iterador++;
     }
     if(iterador != this->aLargo){
        std::cout<<"Las cadenas no son iguales";
        return;
     }
     char caracterEntrada;
     char caracterOriginal;
     iterador = 0;
     while (iterador < this->aLargo){ //Se itera para comparar caracter por caracter
        caracterEntrada = cadena[iterador];
        caracterOriginal = this->apTexto[iterador]; 
        if (caracterEntrada != caracterOriginal){ //En caso de que ambos caracteres no sean exactamente iguales
            std::cout<<"Las cadenas no son iguales";
            return;
        }
        iterador++;
     }
     std::cout<<"Ambas cadenas son iguales"; //Caso donde pasa la iteración sin entrar en la condición del if
     return;
     
     
}


/*****Nombre***************************************
 * split()
 *****DescripciÃ³n**************************************
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
 * concatenar
 *****Descripción**********************************
 * Este método va a recibir como parámetro una
 * cadena de caracteres (char*) y la va a concatenar
 * al final del atributo de clase 'apTexto'.
 *****Retorno**************************************
 * char* nuevaCadena
 *****Entradas*************************************
 * char *pCaracteres
 **************************************************/

char* STRING::concatenar(char *pCaracteres) {

    int largoTotal = (calcularLargo(this->apTexto) + (calcularLargo(pCaracteres)));

    char *pNuevaCadena = new char[largoTotal + 1];

    char *pNuevos = pNuevaCadena;

    
    while (*this->apTexto != '\0') {
        *pNuevos = *this->apTexto;
        ++pNuevos;
        ++this->apTexto;
    }

    while (*pCaracteres != '\0') {
        *pNuevos = *pCaracteres;
        ++pNuevos;
        ++pCaracteres;
    }

    *pNuevos = '\0'; // Agregar el carácter nulo al final

    std::cout << "Nueva cadena: " << pNuevaCadena << std::endl;

    int longitud = calcularLargo(pNuevaCadena);

    delete[] this->apTexto;

    this->apTexto = pNuevaCadena;

    this->aLargo = longitud;

    imprimir();

 
    return pNuevaCadena;

}

//..................................................//


/*****Nombre***************************************
 * concatenarCadenas()
 *****DescripciÃ³n**********************************
 * Este mÃ©todo concatena un arreglo de cadenas de caracteres al final del string original.
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


/*****Nombre***************************************
 * reemplazarOcurrencias()
 *****DescripciÃ³n**********************************
 * Este mÃ©todo reemplaza todas las ocurrencias de una cadena de caracteres 'anterior'
 * en el texto original con otra cadena de caracteres 'nuevo'. Busca todas las ocurrencias
 * de 'anterior' en el texto original y las reemplaza por 'nuevo'.
 *****Retorno**************************************
 * La cadena de caracteres con las sustituciones de las ocurrencias
 *****Entradas*************************************
 * anterior: La cadena de caracteres que se busca reemplazar en el texto original.
 * nuevo: La cadena de caracteres que se utilizarÃ¡ para reemplazar las ocurrencias de 'anterior'.
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

            // Copiar la parte despuÃ©s de la ocurrencia
            for (int j = i + largoAnterior; j < aLargo; ++j) {
                nuevoTexto[j + largoNuevo - largoAnterior] = apTexto[j];
            }

            nuevoTexto[aLargo - largoAnterior + largoNuevo] = '\0'; // Agregar el caracter nulo

            // Liberar la memoria del antiguo arreglo y asignar la nueva
            delete[] apTexto;
            apTexto = nuevoTexto;

            // Actualizar el valor de 'largo'
            aLargo = aLargo - largoAnterior + largoNuevo;
            
            i += largoNuevo; // Avanzar despuÃ©s de la ocurrencia
        } else {
            i++;
        }
    }
}
