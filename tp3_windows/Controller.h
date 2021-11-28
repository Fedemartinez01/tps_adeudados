#include "parser.h"
#include "Employee.h"
#include "funciones.h"
#include "LinkedList.h"


int controller_loadFromText(char* path , LinkedList* pArrayListEmployee);
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee);
int controller_addEmployee(LinkedList* pArrayListEmployee);
int controller_editEmployee(LinkedList* pArrayListEmployee);
int controller_removeEmployee(LinkedList* pArrayListEmployee);
int controller_ListEmployee(LinkedList* pArrayListEmployee);
int controller_sortEmployee(LinkedList* pArrayListEmployee);
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee);
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee);

int controller_altaEmployee(LinkedList* pArrayListEmployee);

/// Crea el archivo de manejo de id
/// @param path
/// @return
int controller_crearIdEmpleados(char* path);

/// Lee el ultimo id, para saber si hay que crear o no un archivo
/// @param path
/// @return
int controller_leerIdEmpleados(char* path);

