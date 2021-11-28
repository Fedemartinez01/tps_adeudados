#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Controller.h"


/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/



int main()
{
	setbuf(stdout, NULL);
	LinkedList* miLista;
	miLista = ll_newLinkedList();

	if(!(controller_leerIdEmpleados("id_empleados.csv")))
	{
		controller_crearIdEmpleados("id_empleados.csv");
	}

	int opcion;
	int flagCarga;
	int flagArchivos;
	int finalizar;
	int confirmarCarga;

	flagArchivos = 0;
	flagCarga = 0;
	finalizar = 0;
	confirmarCarga = 0;

	do
	{
		opcion = GetIntRangos("\n1. Cargar los datos de los empleados desde el archivo data.csv (modo texto)"
							  "\n2. Cargar los datos de los empleados desde el archivo data.csv (modo binario)"
							  "\n3. Alta de empleado"
							  "\n4. Modificar datos de empleado"
							  "\n5. Baja de empleado"
							  "\n6. Listar empleados"
							  "\n7. Ordenar empleados"
							  "\n8. Guardar los datos de los empleados en el archivo data.csv (modo texto)"
							  "\n9. Guardar los datos de los empleados en el archivo data.bin (modo binario)"
							  "\n10 Salir"
							  "\n\nIngresar opcion: ", 1, 10);

			switch(opcion)
			{
			case 1:///1. Cargar los datos de los empleados desde el archivo data.csv (modo texto)
				if(flagCarga == 0)
				{
					if(controller_loadFromText("data.csv", miLista))
					{
						printf("\n--------------------------\n");
						printf("\n-   LINKEDLIST CARGADA   -\n");
						printf("\n--------------------------\n");
						flagCarga = 1;
					}
				}
				else
				{
					printf("\nLos datos ya han sido cargados\n");
				}
				break;

			case 2:///2. Cargar los datos de los empleados desde el archivo data.bin (modo binario)
				if(flagCarga == 0)
				{
					if(controller_loadFromBinary("dataBinary.bin", miLista))
					{
						printf("\n--------------------------\n");
						printf("\n-   LINKEDLIST CARGADA   -\n");
						printf("\n--------------------------\n");
						flagCarga = 1;
					}
				}
				else
				{
					printf("\nLos datos ya han sido cargados\n");
				}
				break;

			case 3:///3. Alta de empleado
				if(controller_addEmployee(miLista))
				{
					printf("\n----------------------------------------\n");
					printf("\n-    EMPLEADO AGREGADO A LINKEDLIST    -\n");
					printf("\n- PARA AGREGAR AL ARCHIVO OPCION 8 Y 9 -\n");
					printf("\n----------------------------------------\n");
					flagArchivos = 0;
				}
				break;

			case 4:///4. Modificar datos de empleado
				if(controller_editEmployee(miLista))
				{
					flagArchivos = 0;
				}
				break;

			case 5:///5. Baja de empleado
				if(controller_removeEmployee(miLista))
				{
					printf("\n--------------------------\n");
					printf("\n-   EMPLEADO ELIMINADO   -\n");
					printf("\n--------------------------\n");
					flagArchivos = 0;
				}
				break;

			case 6:///6. Listar empleados
				controller_ListEmployee(miLista);
				break;

			case 7:/// Ordenar empleados
				controller_sortEmployee(miLista);
				break;

			case 8:///8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
				if(flagArchivos == 0)
				{
					confirmarCarga = GetIntRangos("\nEstá a punto de sobreescribir los datos en el archivo\n"
											"Si no han sido cargados en la lista, se perderán\n"
											"Para confirmar la carga presionar 1\n"
											"Para cancelar la carga presionar 2: ", 1, 2);
					if(confirmarCarga == 1)
					{
						if(controller_saveAsText("data.csv", miLista))
						{
							printf("\n-------------------------------------\n");
							printf("\n-   ARCHIVO CARGADO CORRECTAMENTE   -\n");
							printf("\n-------------------------------------\n");
							flagArchivos = 1;
						}
					}

				}
				else
				{
					printf("\n-----------------------------------------------------\n");
					printf("\n-   LOS DATOS YA HAN SIDO GUARDADOS ANTERIORMENTE   -\n");
					printf("\n-----------------------------------------------------\n");
				}
				break;

			case 9:///9. Guardar los datos de los empleados en el archivo data.bin (modo binario)

				if(flagArchivos == 0)
				{
					confirmarCarga = GetIntRangos("\nEstá a punto de sobreescribir los datos en el archivo\n"
											"Si no han sido cargados en la lista, se perderán\n"
											"Para confirmar la carga presionar 1\n"
											"Para cancelar la carga presionar 2: ", 1, 2);
					if(confirmarCarga == 1)
					{
						if(controller_saveAsBinary("dataBinary.bin", miLista))
						{
							printf("\n-------------------------------------\n");
							printf("\n-   ARCHIVO CARGADO CORRECTAMENTE   -\n");
							printf("\n-------------------------------------\n");
							flagArchivos = 1;
						}
					}
				}
				else
				{
					printf("\n-----------------------------------------------------\n");
					printf("\n-   LOS DATOS YA HAN SIDO GUARDADOS ANTERIORMENTE   -\n");
					printf("\n-----------------------------------------------------\n");
				}
				break;

			case 10:///10. Salir
				finalizar = GetIntRangos("\nSi finaliza el programa se borrará la Linkedlist\n"
											"Si los empleados no fueron agregados al archivo sus ID se perderán\n"
											"¿Estás seguro?\n"
											"1 SI - 2 NO: ", 1, 2);
				if(finalizar == 1)
				{
					ll_deleteLinkedList(miLista);
					printf("\n-------------------------------------\n");
					printf("\n-   PROGRAMA FINALIZADO CON EXITO   -\n");
					printf("\n-------------------------------------\n");
				}
				else
				{
					opcion = 11;
				}
				break;
			}
	}while(opcion != 10);

    return 0;
}

