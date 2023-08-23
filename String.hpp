/*****Datos administrativos************************
 * Nombre del archivo: String
 * Tipo de archivo: .hpp
 * Proyecto: Librería string
 * Autores:
 *          Dylan Montiel Zúñiga
 *          Dylan Rodríguez Chavarría
 *          Eduardo Rojas Gómez 
 * Empresa:
 *****Descripción**********************************
 * 
 * 
 *****Versión**************************************
 * ## | Fecha y hora | Autor
 * 08/22/2023 :: 10:23 PM | 
 **************************************************/

#include <iostream>
#include <cstdio>

/*****Nombre***************************************
 * Clase STRING
 *****Descripción**********************************
 * Esta clase representa una cadena de caracteres y
 * proporciona métodos para manipular y obtener
 * información sobre la cadena.
 *****Atributos************************************
 * - char *apTexto: Puntero al arreglo de caracteres que
 *   almacena el contenido de la cadena.
 * - int aLargo: Almacena la cantidad de caracteres en
 *   la cadena.
 *****Métodos**************************************
 * - STRING(char* input): Constructor que inicializa
 *   la cadena con el contenido del input proporcionado.
 * - ~STRING(): Destructor que libera la memoria
 *   asignada para el puntero de texto.
 * - int getlargo(): Retorna la cantidad de caracteres
 *   en la cadena.
 * - void imprimir(): Imprime el contenido de la cadena
 *   en la consola.
 * - char caracterEn(int indice): Retorna el caracter
 *   en el índice especificado dentro de la cadena.
 * - int contarCaracter(char caracter): Retorna la
 *   cantidad de ocurrencias del caracter especificado
 *   en la cadena.
 * - int len(): Retorna la cantidad de caracteres en
 *   la cadena.
 * - STRING** split(char separador): Retorna un arreglo
 *   de punteros a STRING que contiene las subcadenas
 *   resultantes de dividir la cadena usando el separador
 *   especificado.
 **************************************************/

class STRING {
private:
    char *apTexto;
    int aLargo;

public:
    STRING(char*);
    ~STRING();
    int getLargo();
    void imprimir();
    char caracterEn(int indice);
    int contarCaracter(char pCaracter);
    int len();
    STRING** split(char pSeparador);
    void reemplazarOcurrencias(const char *pAnterior, const char *pNuevo);
    void concatenarCadenas(char **pCadenas);
};
