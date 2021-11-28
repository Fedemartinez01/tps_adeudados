
#ifndef FUNCIONES_H_
#define FUNCIONES_H_

#endif /* FUNCIONES_H_ */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


/// Pide un entero
/// @param mensaje
/// @return el numero entero
int GetInt(char mensaje[]);

/// Pide un entero entre rangos
/// @param mensaje
/// @param minimo
/// @param maximo
/// @return el numero entero
int GetIntRangos(char mensaje[], int minimo, int maximo);

/// Pide un numero flotante
/// @param mensaje
/// @return el numero flotante
float GetFloat(char mensaje[]);

/// Pide un numero flotante
/// @param mensaje
/// @param minimo
/// @param maximo
/// @return el numero flotante
int GetFloatRangos(char mensaje[], float minimo, float maximo);

/// Pide una cadena
/// @param mensaje
/// @param salida
void GetString(char mensaje[], char salida[]);



