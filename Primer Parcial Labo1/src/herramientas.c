/*
 * herramientas.c
 *
 *  Created on: 2 dic 2022
 *      Author: DIEGO
 */

#include "herramientas.h"


int figuritas_mostrarPegadas(sAlbum album,sFigurita figuritas[], int cantFiguritas, sClub clubes[], int sizeClubes,sSeleccion selecciones[], int sizeSelecciones,sManager managers[], int sizeManagers)
{
	int retorno = -1;
	int estado = LIBRE;

	if(figuritas != NULL && cantFiguritas > 0 && clubes != NULL && sizeClubes > 0 && selecciones != NULL && sizeSelecciones > 0 && managers != NULL && sizeManagers > 0)
	{
		encabezado_figuritas();
		for(int i = 0; i < cantFiguritas; i++)
		{

			if(album.idFigurita[i] != LIBRE)
			{
				estado = 1;
				figurita_MostrarUna(figuritas[i], clubes, sizeClubes, selecciones, sizeSelecciones, managers, sizeManagers);
			}
		}
		printf("\n------------------------------------------------------------------------------------------------------------------------------------------------------------------------------");
		retorno = 1;
		if(estado == 0)
		{
			puts("No hay figuritas pegadas");
			retorno = -1;
		}
	}

	return retorno;
}


int figuritas_MostrarDoradas(sAlbum album,sFigurita figuritas[], int cantFiguritas, sClub clubes[], int sizeClubes,sSeleccion selecciones[], int sizeSeleccion,sManager managers[], int sizeManagers)
{
	int retorno = -1;
	int dorada = -1;

	if( figuritas != NULL && cantFiguritas > 0 && clubes != NULL && sizeClubes > 0 && selecciones != NULL && sizeSeleccion > 0 && managers != NULL && sizeManagers > 0)
	{
		puts("\n************ LISTA DE FIGURITAS DORADAS *******************");
		encabezado_figuritas();
		for(int i = 0; i < cantFiguritas; i++)
		{
			if(album.idFigurita[i] != LIBRE)
			{
				for(int j = 0; j < cantFiguritas; j++)
				{
					if(album.esDorada[j] == album.idFigurita[i] )
					{
						dorada = 1;
						figurita_MostrarUna(figuritas[i + 1], clubes, sizeClubes, selecciones, sizeSeleccion, managers, sizeManagers);
						retorno = 1;
						break;
					}
				}
			}
		}
		if(dorada == -1)
		{
			puts("--------------- No hay figuritas DORADAS ---------------");
			retorno = -1;
		}
	}

	return retorno;
}

int manager_getNombre(sFigurita figurita, sManager managers[], int sizeManagers,char* auxManager)
{
	int retorno = -1;
	sManager manager;
	int indiceManager;
	int idManager;

	if(managers != NULL && sizeManagers > 0 && auxManager != NULL)
	{
		idManager = figurita.idManager;
		indiceManager = manager_BuscarID(managers, sizeManagers, idManager);

		if(indiceManager != -1)
		{
			manager = managers[indiceManager];
			strcpy(auxManager,manager.nombre);
			retorno = 1;
		}
	}

	return retorno;
}

int selecciones_getNombre(sFigurita unaFigurita, sSeleccion selecciones[], int sizeSelecciones,char* seleccion)
{
	sSeleccion auxSeleccion;
	int retorno = -1;
	int indexSeleccion;
	int idSeleccion;

	if(selecciones != NULL && sizeSelecciones > 0 && seleccion != NULL)
	{
		idSeleccion = unaFigurita.idSeleccion;
		indexSeleccion = selecciones_BuscarID(selecciones, sizeSelecciones, idSeleccion);

		if(indexSeleccion != -1)
		{
			auxSeleccion = selecciones[indexSeleccion];
			strcpy(seleccion,auxSeleccion.seleccion);
			retorno = 1;

		}

	}

	return retorno;
}

int clubes_getNombre(sFigurita unaFigurita, sClub clubes[], int sizeClubes, char* nombreClubAux)
{
	sClub auxClub;
	int retorno = -1;
	int indexClub;
	int idClub;

	if(clubes != NULL && sizeClubes > 0 && nombreClubAux != NULL)
	{
		idClub = unaFigurita.idClub;
		indexClub = club_BuscarID(clubes, sizeClubes, idClub);

		if(indexClub != -1)
		{
			auxClub = clubes[indexClub];
			strcpy(nombreClubAux,auxClub.nombre);
			retorno = 1;
		}
	}

	return retorno;
}

void clubes_filtro(sFigurita figuritas[],int cantFiguritas,sClub clubes[],int sizeClubes,sSeleccion selecciones[],int sizeSelecciones,sManager managers[], int sizeManagers)
{
	int option;

	club_listarClubes(clubes, sizeClubes);
	obtenerEnteroRemastered(&option, "\nIngrese el ID del club: ", "\nLa opcion ingresada es incorrecta!", 1000, 1010);
	puts("\nLista de jugadores del club seleccionado: ");
	encabezado_figuritas();
	for(int i = 0; i < sizeClubes; i++)
	{
		if(clubes[i].idClub == option && clubes[i].estado == OCUPADO)
		{
			for(int j = 0; j < cantFiguritas; j++)
			{
				if(figuritas[j].idClub == option && figuritas[j].estado == OCUPADO)
				{
					figurita_MostrarUna(figuritas[j], clubes, sizeClubes, selecciones, sizeSelecciones, managers, sizeManagers);
				}
			}
		}
	}

}

void selecciones_filtro(sFigurita figuritas[],int cantFiguritas,sClub clubes[],int sizeClubes,sSeleccion selecciones[],int sizeSelecciones,sManager managers[], int sizeManagers)
{
	int option;

	selecciones_MostrarTodas(selecciones, sizeSelecciones);
	obtenerEnteroRemastered(&option, "\nIngrese el ID de seleccion: ", "\nLa opcion ingresada es incorrecta!", 100, 104);

	puts("\nLista de jugadores de la seleccion seleccionada: ");
	encabezado_figuritas();
	for(int i = 0; i < sizeClubes; i++)
	{
		if(selecciones[i].idSeleccion == option && selecciones[i].estado == OCUPADO)
		{
			for(int j = 0; j < cantFiguritas; j++)
			{
				if(figuritas[j].idSeleccion == option && figuritas[j].estado == OCUPADO)
				{
					figurita_MostrarUna(figuritas[j], clubes, sizeClubes, selecciones, sizeSelecciones, managers, sizeManagers);
				}
			}
		}
	}

}

void managers_filtro(sFigurita figuritas[],int cantFiguritas,sClub clubes[],int sizeClubes,sSeleccion selecciones[],int sizeSelecciones,sManager managers[], int sizeManagers)
{
	int option;

	manager_MostrarTodos(managers, sizeManagers);
	obtenerEnteroRemastered(&option, "\nIngrese el ID del manager: ", "\nLa opcion ingresada es incorrecta!", 200, 204);

	puts("\nLista de jugadores que poseen el manager seleccionado: ");
	encabezado_figuritas();
	for(int i = 0; i < sizeManagers; i++)
	{
		if(managers[i].idManager == option && managers[i].estado == OCUPADO)
		{
			for(int j = 0; j < cantFiguritas; j++)
			{
				if(figuritas[j].idManager == option && figuritas[j].estado == OCUPADO)
				{
					figurita_MostrarUna(figuritas[j], clubes, sizeClubes, selecciones, sizeSelecciones, managers, sizeManagers);
				}
			}
		}
	}

}

void mostrarPaquetesLleno(int cantSobresTotal,sAlbum album)
{
	if(album.estado != OCUPADO )
		{
			puts("\nEl album no esta lleno todavia,continua juntando figuritas!");
		}else
		{
			printf("\nLa cantidad de paquetes comprados para llenar el albm fueron: %3d",cantSobresTotal);
		}
}

void encabezado_figuritas()
{
	printf("\n - - - - - - - - - - - - - - Listado de Figuritas - - - - - - - - - - - - - - - - -");
	puts("\n==============================================================================================================================================================================================");
	printf("| %-2s | %-20s | %-20s | %-20s | %-20s | %-20s | %-4s | %-10s | %-4s | %4s |","ID","Nombre","Posicion","Seleccion","Club","Manager","Altura","Peso","Año ing. Selecc","Fecha de nacimiento");
	puts("\n==============================================================================================================================================================================================");

}

void encabezado_Club()
{
	printf("\n - - - - - - - - - - - - - - Listado de Clubes - - - - - - - - - - - - - - - - -");
	printf("\n================================================================================");
	printf("\n| %-5s | %-22s | %-23s | %-18s |", "ID","NOMBRE","ENTRENADOR","Año de fundacion");
	printf("\n|==============================================================================|");
}

void encabezado_Selecciones()
{
	printf("\n - - - - - - - - - - - - - - Listado de Selecciones - - - - - - - - - - - - - - - - -");
	puts("\n===============================================");
	printf("| %-3s  %-15s  %-20s |","ID","Seleccion","Director tecnico");
	puts("\n===============================================");
}

void encabezado_Managers()
{
	printf("\n - - - - - - - - - - - - - - Listado de Managers - - - - - - - - - - - - - - - - -");
	puts("\n-----------------------------------------------------");
	printf("| %-3s | %-20s | %-20s |","ID","NOMBRE","DESCRIPCION");
	puts("\n-----------------------------------------------------");
}
