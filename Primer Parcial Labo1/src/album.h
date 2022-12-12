/*
 * album.h
 *
 *  Created on: 23 nov 2022
 *      Author: DIEGO
 */

#ifndef ALBUM_H_
#define ALBUM_H_

#include <time.h>
#include "figuritas.h"

#define CANT_POR_PAQUETE 5
#define LIBRE 0
#define OCUPADO 1

typedef struct{

	int idFigurita[CANT_FIGURITAS];
	int esDorada[CANT_FIGURITAS];
	int estado;

}sAlbum;

sAlbum inicializarAlbum(sAlbum array, int size);
int VerificarAlbumLleno(sAlbum album, int cantFiguritas);
int inicializarRepetidas(sFiguritaRepetida arrayRepetidas[], sFigurita arrayFiguritas[],int cantFiguritas);

int album_BuscarEspacioLibre(sAlbum* album);
int album_buscarID(sAlbum array[], int size, int ID);

sAlbum comprarPaquete(sAlbum album, sFiguritaRepetida arrayRepetidas[], int* pContadorFiguritas, sFigurita figuritas[], int cantidadFiguritas, sSeleccion selecciones[], int sizeSelecciones,sClub clubes[],int sizeClubes,sManager managers[],int sizeManagers);

sAlbum intercambio(sAlbum miAlbum, int cantFiguritas, sFigurita figuritas[], sSeleccion selecciones[], int sizeSelecciones,sClub clubes[],int sizeClub,sManager managers[],int sizeManagers,sFiguritaRepetida arrayRepetidas[]);

int guardarRepetidas(sFiguritaRepetida repetidas[], int idRepetido,int size);

sAlbum guardarDorada(sAlbum album, int dorada);

sAlbum figuritas_pegar(sFigurita figuritas[], int cantFiguritas, sAlbum album, int figuritaAPegar, sSeleccion selecciones[], int sizeSeleccion,sFiguritaRepetida arrayRepetidas[]);

int BuscarRepetidas(sFiguritaRepetida arrayRepetidas[], int cantFiguritas);


#endif /* ALBUM_H_ */
