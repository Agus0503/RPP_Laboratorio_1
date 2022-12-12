/*
 * album.c
 *
 *  Created on: 23 nov 2022
 *      Author: DIEGO
 */


#include "album.h"
#include "herramientas.h"

		/* ========================================= DESARROLLO PERFIL COLECCIONISTA =========================================*/


sAlbum inicializarAlbum(sAlbum album, int size)
{
	for (int i = 0; i < size; i++)
	{
		album.idFigurita[i] = LIBRE;
		album.esDorada[i] = -1;
	}

	return album;
}

int VerificarAlbumLleno(sAlbum album, int cantFiguritas)
{
	int retorno = -1;
	int aux = 0;

	for(int i = 0; i < cantFiguritas; i++)
	{
		if(album.idFigurita[i] != LIBRE)
		{
			aux++;
		}
	}

	if(aux == cantFiguritas)
	{
		retorno = 1;
	}

	return retorno;
}

int inicializarRepetidas(sFiguritaRepetida arrayRepetidas[], sFigurita arrayFiguritas[],int cantFiguritas)
{
	int retorno = -1;

	if(arrayRepetidas != NULL && arrayFiguritas != NULL && cantFiguritas > 0)
	{
		for(int i = 0; i < cantFiguritas; i++)
		{
			arrayRepetidas[i].idFiguritaRepetida = arrayFiguritas[i].idFigurita;
			arrayRepetidas[i].cantidadRepetidas = 0;
		}

		retorno = 1;
	}

	return retorno;
}


int album_BuscarEspacioLibre(sAlbum* album)
{
	int indice = -1;

	for(int i = 0; i < 55; i++)
	{
		if(album->idFigurita[i] == LIBRE)
		{
			indice = i;
			break;
		}
	}

	return indice;
}

/*----------------------------------------------------------------------------------------------------------------------------------*/

int guardarRepetidas(sFiguritaRepetida repetidas[], int idRepetido,int size)
{
	int retorno = -1;

	for(int i = 0; i < size; i++)
	{

		if(repetidas[i].idFiguritaRepetida == idRepetido )
		{
			repetidas[i].cantidadRepetidas += 1;
			retorno = 1;
			break;
		}
	}
	return retorno;
}

sAlbum comprarPaquete(sAlbum album, sFiguritaRepetida arrayRepetidas[], int* pContadorFiguritas, sFigurita figuritas[], int cantidadFiguritas, sSeleccion selecciones[], int sizeSelecciones,sClub clubes[],int sizeClubes,sManager managers[],int sizeManagers)
{
	srand(time(NULL));

	int paquete[CANT_POR_PAQUETE];
	int idRandom;
	int contadorFiguritas = 0;
	int dorada = -1;

	contadorFiguritas = *pContadorFiguritas;

	puts("\nCompra exitosa! \n"
		 "Usted obtuvo las siguientes figuritas:\n");

	encabezado_figuritas();
	for(int i = 0; i < CANT_POR_PAQUETE; i++)
	{
		idRandom = (rand() % (CANT_FIGURITAS));
		paquete[i] = idRandom;
		if(contadorFiguritas == 50)
		{
			dorada = paquete[i];
			puts("-------------------------------------------");
			puts("FELICIDADES, OBTUVISTE UNA FIGURITA DORADA");
			puts("-------------------------------------------");
			printf("Id de la figurita dorada: %d\n\n",paquete[i] + 1);

			contadorFiguritas = 0;
			album = guardarDorada(album, dorada);
		}

		figurita_MostrarUna(figuritas[idRandom], clubes, sizeClubes, selecciones, sizeSelecciones, managers, sizeManagers);

		contadorFiguritas++;
	}

	for(int i = 0; i < CANT_POR_PAQUETE; i++)
	{
		album = figuritas_pegar(figuritas, cantidadFiguritas, album, paquete[i], selecciones, sizeSelecciones,arrayRepetidas);
	}

	*pContadorFiguritas = contadorFiguritas;
	printf("\nContador Figuritas %d",contadorFiguritas);

	return album;
}

sAlbum figuritas_pegar(sFigurita figuritas[], int cantFiguritas, sAlbum album, int figuritaAPegar, sSeleccion selecciones[], int sizeSeleccion,sFiguritaRepetida arrayRepetidas[])
{
	if(figuritas != NULL && arrayRepetidas != NULL && cantFiguritas > 0 && figuritaAPegar > 0)
	{
		for(int i = 0; i < cantFiguritas; i++)
		{
			if(figuritas[i].idFigurita == figuritaAPegar)
			{
				if(album.idFigurita[i] != LIBRE)
				{
					guardarRepetidas(arrayRepetidas, figuritaAPegar, cantFiguritas);
					break;
				}else{
					album.idFigurita[i] = figuritaAPegar;
				}
			}
		}
	}

	return album;
}

sAlbum guardarDorada(sAlbum album, int dorada)
{
	for(int i = 0; i < CANT_FIGURITAS; i++)
	{
		if(album.esDorada[i] == -1)
		{
			album.esDorada[i] = dorada; // Guardar figurita Dorada en esta posicion
			break;
		}
	}

	return album;
}

sAlbum intercambio(sAlbum miAlbum, int cantFiguritas, sFigurita figuritas[], sSeleccion selecciones[], int sizeSelecciones,sClub clubes[],int sizeClub,sManager managers[],int sizeManagers,sFiguritaRepetida arrayRepetidas[])//Agregar selecciones,desp club y sizes
{
	int figuritaFaltante;
	int figuritaIntercambiada;
	int figuritaEnPosesion = LIBRE;

	figurita_MostrarTodas(figuritas, cantFiguritas, clubes, sizeClub, selecciones, sizeSelecciones, managers, sizeManagers);
	obtenerEnteroRemastered(&figuritaFaltante, "Ingrese el ID de la figurita que desea: ", "ERROR,dato inexistente", 1, 55);

	do{
		figurita_MostrarRepetida(arrayRepetidas, figuritas, cantFiguritas, clubes, sizeClub, selecciones, sizeSelecciones, managers, sizeManagers);
		obtenerEnteroRemastered(&figuritaIntercambiada, "Ingrese el ID de la figurita a entregar: ", "ERROR, ID incorrecto", 1, 55);

		for(int i = 0; i < cantFiguritas; i++)
		{
			if(figuritaIntercambiada == arrayRepetidas[i].idFiguritaRepetida && arrayRepetidas[i].cantidadRepetidas > 0)
			{
				arrayRepetidas[i].cantidadRepetidas = arrayRepetidas[i].cantidadRepetidas - 1;
				figuritaEnPosesion = OCUPADO;
			}
		}

		if(figuritaEnPosesion == LIBRE)
		{
			puts("ERROR, La figurita ingresada no se encuentra en tu coleccion");
		}


	}while(figuritaEnPosesion == LIBRE);


	puts("\nEl intercambio se llevo a cabo con exito!");

	miAlbum = figuritas_pegar(figuritas, cantFiguritas, miAlbum, figuritaFaltante, selecciones, sizeSelecciones, arrayRepetidas);

	return miAlbum;

}

int BuscarRepetidas(sFiguritaRepetida arrayRepetidas[], int cantFiguritas)
{
	int retorno = -1;

	for(int i = 0; i < cantFiguritas; i++)
	{
		if(arrayRepetidas[i].cantidadRepetidas > 0)
		{
			retorno = 1;
			break;
		}
	}

	return retorno;
}

