
#include "funciones.h"

int GetInt(char mensaje[])
{
	int numeroValidado;
	char numero[20];
	int esNumero;
	int retorno;
	int largoCadena;
	int i;

	if(mensaje != NULL)
	{
		do
		{
			printf("%s", mensaje);
			fflush(stdin);
			gets(numero);

			largoCadena = strlen(numero);

			i = 1;
			retorno = 1;
			esNumero = 0;

			if(numero[0] != '-')
			{
				i = 0;
			}
			for(; i < largoCadena; i++)
			{
				if(isdigit(numero[i]) == 0)//SI ES LETRA...
				{
					retorno = 0;
					break;
				}
			}

			if(retorno == 0 || numero[0] == '\0')
			{
				printf("\nERROR, INGRESAR SOLO NUMEROS\n");
			}
			else
			{
				numeroValidado = atoi(numero);
				esNumero = 1;
			}
		}while(esNumero == 0);
	}



	return numeroValidado;
}

int GetIntRangos(char mensaje[], int minimo, int maximo)
{
	int numero;
	if(mensaje != NULL)
	{
		do
		{
			numero = GetInt(mensaje);

		}while(numero < minimo || numero > maximo);
	}

	return numero;
}



float GetFloat(char mensaje[])
{
	float numeroValidado;
	char numero[20];
	int esNumero;
	int retorno;
	int largoCadena;
	int i;
	int contadorPuntosDecimales;

	if(mensaje != NULL)
	{

		do
		{
			printf("%s", mensaje);
			fflush(stdin);
			gets(numero);

			largoCadena = strlen(numero);

			contadorPuntosDecimales = 0;
			i = 1;
			retorno = 1;
			esNumero = 0;

			if(numero[0] != '-')
			{
				i = 0;
			}
			for(; i < largoCadena; i++)
			{
				if(isdigit(numero[i]) == 0)//SI ES LETRA...
				{
					if(numero[i] == '.' && contadorPuntosDecimales < 1)
					{
						contadorPuntosDecimales++;
						continue;
					}
					retorno = 0;
					break;
				}
			}

			if(retorno == 0 || numero[0] == '\0')
			{
				printf("\nERROR, INGRESAR SOLO NUMEROS\n");
			}
			else
			{
				numeroValidado = atof(numero);
				esNumero = 1;
			}
		}while(esNumero == 0);

	}


	return numeroValidado;
}

int GetFloatRangos(char mensaje[], float minimo, float maximo)
{
	int numero;

	if(mensaje != NULL)
	{
		do
		{
			numero = GetFloat(mensaje);
		}while(numero < minimo || numero > maximo);
	}

	return numero;
}

void GetString(char mensaje[], char salida[])
{
	int retorno;
	int esLetra;
	int largoCadena;
	int cargoLetras;
	cargoLetras = 0;

	if(mensaje != NULL)
	{
		do
		{
			retorno = 0;
			esLetra = 0;
			printf("%s", mensaje);
			fflush(stdin);
			gets(salida);

			largoCadena = strlen(salida);

			for(int i = 0; i < largoCadena; i++)
			{
				if(isalpha(salida[i]) == 0)
				{
					if(salida[i] == 32 || salida[i] == 'ñ')
					{
						continue;
					}
					retorno = 1;
					break;
				}
				else
				{
					cargoLetras = 1;
				}
			}



			if(retorno == 1 || salida[0] == '\0' || cargoLetras == 0)
			{
				printf("\nERROR, INGRESAR SOLO LETRAS\n");
			}
			else
			{
				esLetra = 1;
			}
		}while(esLetra == 0);
	}


}
