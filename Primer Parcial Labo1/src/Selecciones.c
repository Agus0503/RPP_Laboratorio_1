/*
 * Selecciones.c
 *
 *  Created on: 11 dic 2022
 *      Author: DIEGO
 */

#include "herramientas.h"

void selecciones_MostrarUna(sSeleccion seleccion)
{
	printf("| %-3d  %-15s  %-20s|", seleccion.idSeleccion, seleccion.seleccion,seleccion.directorTecnico);
	puts("\n------------------------------------------");
}

int selecciones_MostrarTodas(sSeleccion selecciones[], int sizeSelecciones)
{
	int retorno = -1;
	int cantidad = 0;

	if(selecciones != NULL && sizeSelecciones > 0)
	{
		encabezado_Selecciones();

		for(int i = 0; i < sizeSelecciones; i++)
		{
			if(selecciones[i].estado == OCUPADO)
			{
				selecciones_MostrarUna(selecciones[i]);
				cantidad++;
			}
		}

	}

	if(cantidad > 0)
	{
		retorno = 1;
	}

	return retorno;
}


int cargarSeleccion(sSeleccion selecciones[], int sizeSeleccion)
{
	int id;

	selecciones_MostrarTodas(selecciones, sizeSeleccion);
	obtenerEnteroRemastered(&id, "\nIngrese una seleccion: ", "\nLa opcion ingresada es incorrecta ", 100, 104);

	return id;
}

int selecciones_BuscarID(sSeleccion selecciones[], int sizeSeleccion, int id)
{
	int index = -1;

	if(selecciones != NULL && sizeSeleccion > 0)
	{
		for(int i = 0; i < sizeSeleccion; i++)
		{
			if(selecciones[i].estado == OCUPADO && selecciones[i].idSeleccion == id)
			{
				index = i;
				break;
			}
		}
	}

	return index;
}

int seleccion_validarCantidadJugadores(int idSeleccionAux,sSeleccion selecciones[], int sizeSelecciones)
{
	sSeleccion seleccionAux;
	int retorno = -1;
	int indice;

	if(selecciones != NULL && sizeSelecciones > 0)
	{
		indice = selecciones_BuscarID(selecciones, sizeSelecciones, idSeleccionAux);
		seleccionAux = selecciones[indice];
		if(seleccionAux.contador < 11)
		{
			seleccionAux.contador = seleccionAux.contador + 1;
			retorno = 1;
			selecciones[indice] = seleccionAux;
			selecciones_MostrarUna(selecciones[indice]);
		}else
		{
			puts("\nError, selección llena.");
			system("pause");
		}

	}
	return retorno;
}
