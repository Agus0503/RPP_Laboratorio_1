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

/// \brief Iniciazlizo estados del album
///
/// \param array albul
/// \param size tamaño
/// \return album
sAlbum inicializarAlbum(sAlbum array, int size);

/// \brief Verifico si el album esta completo o no
///
/// \param album
/// \param cantFiguritas
/// \return 1 si esta lleno
/// 		-1 si no
int VerificarAlbumLleno(sAlbum album, int cantFiguritas);

/// \brief Inicializo estado de figuritas repetidas
///
/// \param arrayRepetidas lista de repetidas
/// \param arrayFiguritas lista de figuritas
/// \param cantFiguritas size
/// \return 1 si pudo inicializar correctamante
/// 		-1 si no
int inicializarRepetidas(sFiguritaRepetida arrayRepetidas[], sFigurita arrayFiguritas[],int cantFiguritas);

int album_BuscarEspacioLibre(sAlbum* album);
int album_buscarID(sAlbum array[], int size, int ID);


/// \brief Compro un paquete de figuritas
///
/// \param album
/// \param arrayRepetidas lista de repetidas
/// \param pContadorFiguritas
/// \param figuritas lista de figuritas
/// \param cantidadFiguritas
/// \param selecciones lista de selecciones
/// \param sizeSelecciones tamaño de la lista de selecciones
/// \param clubes lista de clubes
/// \param sizeClubes tamaño de la lista de clubes
/// \param managers lista de managers
/// \param sizeManagers
/// \return Album
sAlbum comprarPaquete(sAlbum album, sFiguritaRepetida arrayRepetidas[], int* pContadorFiguritas, sFigurita figuritas[], int cantidadFiguritas, sSeleccion selecciones[], int sizeSelecciones,sClub clubes[],int sizeClubes,sManager managers[],int sizeManagers);

/// \brief
///
/// \param miAlbum
/// \param cantFiguritas
/// \param figuritas
/// \param selecciones
/// \param sizeSelecciones
/// \param clubes
/// \param sizeClub
/// \param managers
/// \param sizeManagers
/// \param arrayRepetidas
/// \return
sAlbum intercambio(sAlbum miAlbum, int cantFiguritas, sFigurita figuritas[], sSeleccion selecciones[], int sizeSelecciones,sClub clubes[],int sizeClub,sManager managers[],int sizeManagers,sFiguritaRepetida arrayRepetidas[]);

int guardarRepetidas(sFiguritaRepetida repetidas[], int idRepetido,int size);

sAlbum guardarDorada(sAlbum album, int dorada);

sAlbum figuritas_pegar(sFigurita figuritas[], int cantFiguritas, sAlbum album, int figuritaAPegar, sSeleccion selecciones[], int sizeSeleccion,sFiguritaRepetida arrayRepetidas[]);

int BuscarRepetidas(sFiguritaRepetida arrayRepetidas[], int cantFiguritas);


#endif /* ALBUM_H_ */
