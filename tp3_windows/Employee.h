#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED

#include "funciones.h"
#include <stdio.h>
#include <string.h>
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

/// Crea un empleado en memoria
/// @return un empleado
Employee* employee_new();

/// Le asigna los datos al empleado
/// @param idStr
/// @param nombreStr
/// @param horasTrabajadasStr
/// @param sueldoStr
/// @return
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr);

void employee_delete(Employee* this);

/// Asigna el id
/// @param this
/// @param id
/// @return 1 si pudo, 0 sino
int employee_setId(Employee* this,int id);
/// Lee el id
/// @param this
/// @param id
/// @return 1 si pudo, 0 sino
int employee_getId(Employee* this,int* id);

/// Asigna el nombre
/// @param this
/// @param nombre
/// @return 1 si pudo, 0 sino
int employee_setNombre(Employee* this,char* nombre);
/// Lee el nombre
/// @param this
/// @param nombre
/// @return 1 si pudo, 0 sino
int employee_getNombre(Employee* this,char* nombre);

/// Asigna las horas
/// @param this
/// @param horasTrabajadas
/// @return 1 si pudo, 0 sino
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
/// Lee las horas
/// @param this
/// @param horasTrabajadas
/// @return 1 si pudo, 0 sino
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

/// Asigna el sueldo
/// @param this
/// @param sueldo
/// @return 1 si pudo, 0 sino
int employee_setSueldo(Employee* this,int sueldo);
/// Lee el sueldo
/// @param this
/// @param sueldo
/// @return 1 si pudo, 0 sino
int employee_getSueldo(Employee* this,int* sueldo);

/// Imprime el empleado recibido
/// @param empleado
/// @return 1 si pudo, 0 sino
int employee_oneEmployee(Employee* empleado);

int employee_listEmloyees();

/// Pide un empleado por teclado
/// @param this
/// @param id
/// @param nombre
/// @param horas
/// @param sueldo
/// @return un empleado
int employee_getEmployee(Employee* this, int* id, char* nombre, int* horas, int* sueldo);

Employee* employee_employeeTeclado(int id);

/// Compara los nombres de los empleados
/// @param empleado1
/// @param empleado2
/// @return -1, 0, 1
int employee_CompareByName(void* empleado1, void* empleado2);
/// Compara los id de los empleados
/// @param empleado1
/// @param empleado2
/// @return -1, 0, 1n
int employee_CompareById(void* empleado1, void* empleado2);

/// Compara los sueldos de los empleados
/// @param empleado1
/// @param empleado2
/// @return -1, 0, 1
int employee_CompareBySueldo(void* empleado1, void* empleado2);

/// Compara las horas trabajadas de los empleados
/// @param empleado1
/// @param empleado2
/// @return -1, 0, 1
int employee_CompareByHorasTrabajadas(void* empleado1, void* empleado2);

#endif // employee_H_INCLUDED
