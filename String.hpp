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
 * 08/23/2023 :: 12:40 PM | 
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
 * Constructor
 * Destructor
 * getLargo()
 * imprimir()
 * calcularLargo()
 * caracterEn()
 * contarCaracter()
 * ultimoIndice()
 * cambiarCadena()
 * len()
 * equals()
 * split()
 * concatenar()
 * concatenarCadenas()
 * reemplazarOcurrecias()
 **************************************************/
 
class STRING {
private:
    char *apTexto;
    int aLargo;

public:
    STRING(char*);
    ~STRING();
    void imprimir();
    int calcularLargo(const char *pCadenas);
    char caracterEn(int indice);
    int contarCaracter(char pCaracter);
    void ultimoIndice(char *caracter);
    void cambiarCadena(char* nuevaCadena);
    int len();
    void equals(char *cadena);
    STRING** split(char pSeparador);
    char* concatenar(char *pCaracteres);
    void concatenarCadenas(char **pCadenas);
    void reemplazarOcurrencias(const char *pAnterior, const char *pNuevo);
};
