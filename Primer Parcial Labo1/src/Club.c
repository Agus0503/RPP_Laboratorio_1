/*
 * Club.c
 *
 *  Created on: 4 dic 2022
 *      Author: DIEGO
 */

#include "Club.h"
#include "herramientas.h"

void club_mostrarUnClub(sClub club)
{
	printf("\n| %-5d | %-22s | %-23s | %-17d |", club.idClub, club.nombre, club.entrenador, club.anioFundacion);
	printf("\n|------------------------------------------------------------------------------|");
}

int club_listarClubes(sClub arrayClubes[], int sizeClubes)
{
	int retorno = -1;

	if(arrayClubes != NULL)
	{
		encabezado_Club();
		for(int i = 0; i < sizeClubes; i++)
		{
			club_mostrarUnClub(arrayClubes[i]);
		}

		retorno = 1;
	}

	return retorno;
}

int club_BuscarID(sClub clubes[], int sizeClub, int id)
{
	int index = -1;

	if(clubes != NULL && sizeClub > 0)
	{
		for(int i = 0; i < sizeClub; i++)
		{
			if(clubes[i].estado == OCUPADO && clubes[i].idClub == id)
			{
				index = i;
				break;
			}
		}
	}

	return index;
}

int cargarClub(sClub clubes[], int sizeClub)
{
	int id;

	club_listarClubes(clubes, sizeClub);
	obtenerEnteroRemastered(&id, "\nIngrese club: ", "\nLa opcion ingresada es incorrecta ", 1000, 1010);

	return id;
}

