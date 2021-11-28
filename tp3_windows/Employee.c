#include "Employee.h"


Employee* employee_new()
{

	Employee* empleado;
	empleado = (Employee*)malloc(sizeof(Employee));

	return empleado;
}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr)
{
	Employee* miEmpleado;
	miEmpleado = employee_new();

	if(miEmpleado != NULL)
	{
		employee_setId(miEmpleado,atoi(idStr));
		employee_setHorasTrabajadas(miEmpleado, atoi(horasTrabajadasStr));
		employee_setNombre(miEmpleado, nombreStr);
		employee_setSueldo(miEmpleado, atoi(sueldoStr));
	}
	return miEmpleado;
}

Employee* employee_employeeTeclado(int id)
{
	char nombre[128];
	int horas;
	int sueldo;

	Employee* miEmpleado;
	miEmpleado = employee_new();


	GetString("Ingresar nombre: ", nombre);
	horas = GetInt("Cantidad de horas trabajadas: ");
	sueldo = GetInt("Sueldo: ");

	employee_setId(miEmpleado, id);
	employee_setNombre(miEmpleado, nombre);
	employee_setHorasTrabajadas(miEmpleado, horas);
	employee_setSueldo(miEmpleado, sueldo);

	return miEmpleado;

}


///////////////////////////////////////////////////////////////////////////////////////


int employee_oneEmployee(Employee* empleado)
{
	int id;
	int horas;
	char nombre[128];
	int sueldo;

	employee_getId(empleado, &id);
	employee_getHorasTrabajadas(empleado, &horas);
	employee_getNombre(empleado, nombre);
	employee_getSueldo(empleado, &sueldo);

	printf("|%5d | %5d | %21s | %6d|\n", id, horas, nombre, sueldo);///MOSTRANDO EMPLEADOS

	return 1;
}


int employee_getEmployee(Employee* this, int* id, char* nombre, int* horas, int* sueldo)
{

	employee_getId(this, id);
	employee_getHorasTrabajadas(this, horas);
	employee_getNombre(this, nombre);
	employee_getSueldo(this, sueldo);

	return 1;
}

/////////////GETERS & SETERS////////////////////////////////////////////////////////////
int employee_setId(Employee* this,int id)
{
	int retorno;
	retorno = 0;

	if(this != NULL && id > 0)
	{
		this->id = id;
		retorno = 1;
	}

	return retorno;
}

int employee_getId(Employee* this,int* id)
{
	int retorno;
	retorno = 0;

	if(this != NULL)
	{
		*id = this->id;
		retorno = 1;
	}

	return retorno;
}
int employee_setNombre(Employee* this,char* nombre)
{
	int retorno;
	retorno = 0;

	if(this != NULL)
	{

		strcpy(this->nombre, nombre);
		retorno = 1;
	}

	return retorno;
}
int employee_getNombre(Employee* this,char* nombre)
{
	int retorno;
	retorno = 0;

	if(this != NULL)
	{
		strcpy(nombre, this->nombre);
		retorno = 1;
	}

	return retorno;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
	int retorno;
	retorno = 0;

	if(this != NULL)
	{
		this->horasTrabajadas = horasTrabajadas;
		retorno = 1;
	}

	return retorno;
}
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
	int retorno;
	retorno = 0;

	if(this != NULL)
	{
		*horasTrabajadas = this->horasTrabajadas;
		retorno = 1;
	}

	return retorno;
}

int employee_setSueldo(Employee* this,int sueldo)
{
	int retorno;
	retorno = 0;

	if(this != NULL)
	{

		this->sueldo = sueldo;
		retorno = 1;
	}

	return retorno;
}
int employee_getSueldo(Employee* this,int* sueldo)
{
	int retorno;
	retorno = 0;

	if(this != NULL)
	{
		*sueldo = this->sueldo;
		retorno = 1;
	}

	return retorno;
}
/////////////GETERS & SETERS////////////////////////////////////////////////////////////



/////////////ORDENAMIENTO////////////////////////////////////////////////////////////

int employee_CompareById(void* empleado1, void* empleado2)
{
	int retorno;
	int id1;
	int id2;

	retorno = 0;

	if(empleado1 != NULL && empleado2 != NULL)
	{
		Employee* empleado_1;
		Employee* empleado_2;

		empleado_1 = (Employee*) empleado1;
		empleado_2 = (Employee*) empleado2;

		employee_getId(empleado_1, &id1);
		employee_getId(empleado_2, &id2);

		if(id1 > id2)
		{
			retorno = 1;
		}
		else
		{
			if(id1 < id2)
			{
				retorno = -1;
			}
		}
	}

	return retorno;
}

int employee_CompareByName(void* empleado1, void* empleado2)
{
	int retorno;
	char nombre1[128];
	char nombre2[128];

	if(empleado1 != NULL && empleado2 != NULL)
	{

		Employee* empleado_1;
		Employee* empleado_2;

		empleado_1 = (Employee*) empleado1;
		empleado_2 = (Employee*) empleado2;

		employee_getNombre(empleado_1, nombre1);
		employee_getNombre(empleado_2, nombre2);

		retorno = strcmp(nombre1, nombre2);
	}

	return retorno;
}

int employee_CompareBySueldo(void* empleado1, void* empleado2)
{
	int retorno;
	int sueldo1;
	int sueldo2;

	retorno = 0;

	if(empleado1 != NULL && empleado2 != NULL)
	{
		Employee* empleado_1;
		Employee* empleado_2;

		empleado_1 = (Employee*) empleado1;
		empleado_2 = (Employee*) empleado2;

		employee_getSueldo(empleado_1, &sueldo1);
		employee_getSueldo(empleado_2, &sueldo2);

		if(sueldo1 > sueldo2)
		{
			retorno = 1;
		}
		else
		{
			if(sueldo1 < sueldo2)
			{
				retorno = -1;
			}
		}
	}

	return retorno;
}

int employee_CompareByHorasTrabajadas(void* empleado1, void* empleado2)
{
	int retorno;
	int horas1;
	int horas2;

	retorno = 0;

	if(empleado1 != NULL && empleado2 != NULL)
	{
		Employee* empleado_1;
		Employee* empleado_2;

		empleado_1 = (Employee*) empleado1;
		empleado_2 = (Employee*) empleado2;

		employee_getHorasTrabajadas(empleado_1, &horas1);
		employee_getHorasTrabajadas(empleado_2, &horas2);

		if(horas1 > horas2)
		{
			retorno = 1;
		}
		else
		{
			if(horas1 < horas2)
			{
				retorno = -1;
			}
		}
	}

	return retorno;
}






