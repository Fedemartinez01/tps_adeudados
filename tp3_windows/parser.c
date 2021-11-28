
#include "parser.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int retorno;
	retorno = 0;

	char idF[51];
	char nombreF[51];
	char horasF[51];
	char sueldoF[51];

	int len;

	if(pFile != NULL && pArrayListEmployee != NULL)
	{
		fscanf(pFile, "%[^,], %[^,], %[^,], %[^\n]\n", idF, nombreF, horasF, sueldoF);//FALSA LECTURA

		while(!feof(pFile))
		{
			if(feof(pFile))
			{
				break;
			}
			len = fscanf(pFile, "%[^,], %[^,], %[^,], %[^\n]\n", idF, nombreF, horasF, sueldoF);

			if(len == 4)
			{
				Employee* unEmpleado;
				unEmpleado = employee_newParametros(idF, nombreF, horasF, sueldoF);
				ll_add(pArrayListEmployee, unEmpleado);
			}
			else
			{
				break;
			}
		}
	}


    return retorno;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int retorno;
	retorno = 0;
	Employee* unEmpleado;

	if(pFile != NULL && pArrayListEmployee != NULL)
	{
		while(!feof(pFile))
		{
			unEmpleado = employee_new();
			if(unEmpleado != NULL)
			{
				fread(unEmpleado, sizeof(Employee), 1, pFile);
				if(feof(pFile))
				{
					break;
				}
				else
				{
					ll_add(pArrayListEmployee, unEmpleado);
					retorno = 1;
				}
			}
		}
	}

	return retorno;
}


int parser_SaveEmployeeText(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int id;
	char nombre[128];
	int horas;
	int sueldo;
	int len;
	int retorno;
	retorno = 0;
	Employee* unEmpleado;

	len = ll_len(pArrayListEmployee);

	if(pFile != NULL && pArrayListEmployee != NULL)
	{
		fprintf(pFile,"id,nombre,horas,sueldo\n");

		for(int i = 0; i < len; i++)
		{
			unEmpleado = (Employee*) ll_get(pArrayListEmployee, i);

			employee_getEmployee(unEmpleado, &id, nombre, &horas, &sueldo);

			fprintf(pFile ,"%d,%s,%d,%d\n", id, nombre, horas, sueldo);
			retorno = 1;
		}
	}


	return retorno;
}

int parser_SaveEmployeeBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
	Employee* unEmpleado;
	int retorno;
	int len;

	retorno = 0;
	len = ll_len(pArrayListEmployee);

	if(pFile != NULL && pArrayListEmployee != NULL)
	{
		for(int i = 0; i < len; i++)
		{
			unEmpleado = (Employee*)ll_get(pArrayListEmployee, i);

			if(unEmpleado != NULL)
			{
				fwrite(unEmpleado, sizeof(Employee), 1, pFile);
				retorno = 1;
			}
		}
	}
	return retorno;
}


int parser_ReadIdFromText(FILE* pFileID, char* id)
{
	int retorno;
	retorno = 0;

	if(pFileID != NULL)
	{
		while(!feof(pFileID))
		{
			fscanf(pFileID, "%[^,],", id);//LEEMOS EL ULTIMO ID AGREGADO EN EL ARCHIVO
		}

	}
	return retorno;
}






