
#ifndef PARSER_H_
#define PARSER_H_


#include "funciones.h"
#include "LinkedList.h"
#include "Employee.h"


/// Lee los datos del empleado, los asigna a un empleado y lo agrega a la linkedlist
/// @param pFile
/// @param pArrayListEmployee
/// @return
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee);


int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee);

int parser_SaveEmployeeText(FILE* pFile , LinkedList* pArrayListEmployee);

int parser_SaveEmployeeBinary(FILE* pFile , LinkedList* pArrayListEmployee);

int parser_ReadIdFromText(FILE* pFileID, char* id);

#endif /* PARSER_H_ */
