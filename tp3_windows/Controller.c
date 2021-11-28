#include "Controller.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
	int retorno;
	retorno = 0;

	FILE* pArchivo;
	pArchivo = fopen(path, "r");

	if(pArchivo != NULL)
	{
		parser_EmployeeFromText(pArchivo, pArrayListEmployee);
		retorno = 1;
	}
	fclose(pArchivo);

    return retorno;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
	int retorno;
	retorno = 0;

	FILE* pArchivo;
	pArchivo = fopen(path, "rb");

	if(pArchivo != NULL)
	{
		parser_EmployeeFromBinary(pArchivo, pArrayListEmployee);
		retorno = 1;
	}
	fclose(pArchivo);
    return retorno;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
	int retorno;
	char id[15];
	int idInt;
	retorno = 0;

	if(pArrayListEmployee != NULL)
	{
		FILE* pArchivoID;
		pArchivoID = fopen("id_empleados.csv", "r");
		if(pArchivoID != NULL)
		{
			parser_ReadIdFromText(pArchivoID, id);//RECIBIMOS EL ULTIMO ID CARGADO
			idInt = atoi(id);//LO PARSEAMOS A INT
			idInt++;//AUMENTAMOS 1
		}
		fclose(pArchivoID);

		Employee* empleado;
		empleado = employee_employeeTeclado(idInt);
		ll_add(pArrayListEmployee, empleado);

		pArchivoID = fopen("id_empleados.csv", "w");
		{
			if(pArchivoID != NULL)
			{
				fprintf(pArchivoID, "%d,", idInt);//AGREGAMOS EL ULTIMO ID AL ARCHIVO CONTROLADOR DE IDS
			}
		}
		fclose(pArchivoID);

		retorno = 1;
	}

    return retorno;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
	int retorno;
	int len;
	int idEmpleado;
	int idBuscar;
	char nombre[31];

	retorno = 0;

	idBuscar = GetInt("Modificar el empleado del id: ");

	len = ll_len(pArrayListEmployee);

	Employee* miEmpleado;

	for(int i = 0; i < len; i++)
	{
		miEmpleado = (Employee*)ll_get(pArrayListEmployee, i);
		employee_getId(miEmpleado, &idEmpleado);

		if(idBuscar == idEmpleado)
		{
			printf("Nuevo nombre: ");
			gets(nombre);
			employee_setNombre(miEmpleado, nombre);
			retorno = 1;
		}

	}
    return retorno;

}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
	int retorno;
	int len;
	int idEmpleado;
	int idBuscar;

	retorno = 0;
	idBuscar = GetInt("ID del empleado a eliminar: ");
	len = ll_len(pArrayListEmployee);

	Employee* miEmpleado;   ///malloc???

	for(int i = 0; i < len; i++)
	{
		miEmpleado = (Employee*)ll_get(pArrayListEmployee, i);
		employee_getId(miEmpleado, &idEmpleado);

		if(idBuscar == idEmpleado)
		{
			ll_remove(pArrayListEmployee, i);
			retorno = 1;
			break;
		}

	}
    return retorno;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{

	int retorno;
	int len;

	retorno = 0;
	Employee* miEmpleado;

	if(pArrayListEmployee != NULL)
	{
		len = ll_len(pArrayListEmployee);
		retorno = 1;

		printf("------------------------------------------------\n");
		printf("-                  LINKEDLIST                  -\n");
		printf("------------------------------------------------\n");

		for(int i = 0; i < len; i++)
		{
			miEmpleado = (Employee*)ll_get(pArrayListEmployee, i);
			///Acá agarramos al empleado enlazado al nodo 'i' de la linkedlist

			employee_oneEmployee(miEmpleado);
		}
		printf("------------------------------------------------");

	}

    return retorno;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
	int retorno;
	retorno = 0;
	if(pArrayListEmployee != NULL)
	{
		printf("\nUn momento por favor...");
		//ll_sort(pArrayListEmployee, employee_CompareById, 0);
		ll_sort(pArrayListEmployee, employee_CompareByName, 0);
		//ll_sort(pArrayListEmployee, employee_CompareBySueldo, 0);
		//ll_sort(pArrayListEmployee, employee_CompareByHorasTrabajadas, 0);
	    printf("\n¡¡¡Linkedlist ordenada!!!\n");
	    retorno = 1;
	}

	return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
	int retorno;
	FILE* pArchivo;

	pArchivo = fopen(path, "w");
	retorno = 0;

	if(pArchivo != NULL)
	{
		parser_SaveEmployeeText(pArchivo, pArrayListEmployee);
		retorno = 1;
	}

	fclose(pArchivo);
    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    int retorno;
    FILE* pArchivo;

    pArchivo = fopen(path, "wb");
    retorno = 0;


    if(pArchivo != NULL && pArrayListEmployee != NULL)
    {
    	parser_SaveEmployeeBinary(pArchivo, pArrayListEmployee);
    	retorno = 1;
    }
    fclose(pArchivo);
    return retorno;

}

int controller_crearIdEmpleados(char* path)
{
	int retorno;
	FILE* pFile;

	retorno = 0;

	pFile = fopen(path, "w");
	if(pFile != NULL)
	{
		fprintf(pFile, "1000");
		retorno = 1;
	}
	fclose(pFile);

	return retorno;
}

int controller_leerIdEmpleados(char* path)
{
	int retorno;
	char id[15];
	int id1;
	FILE* pFile;

	retorno = 0;

	pFile = fopen(path, "r");
	if(pFile != NULL)
	{

		parser_ReadIdFromText(pFile, id);
		id1 = atoi(id);

		if(id1 > 1000)
		{
			retorno = 1;
		}
	}

	fclose(pFile);

	return retorno;

}


