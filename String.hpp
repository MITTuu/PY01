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
 * apTexto
 * aLargo
 *****Métodos**************************************
 * 
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
    void ultimoIndice(char *caracter);
    void cambiarCadena(char* nuevaCadena);
    int len();
    void equals(char *cadena);
    STRING** split(char pSeparador);
    // método concatenar()
    void concatenarCadenas(char **pCadenas);
    void reemplazarOcurrencias(const char *pAnterior, const char *pNuevo);
    
};
