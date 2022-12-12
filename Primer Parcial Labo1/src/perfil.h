/*
 * perfil.h
 *
 *  Created on: 2 dic 2022
 *      Author: DIEGO
 */

#ifndef PERFIL_H_
#define PERFIL_H_

//#include "figuritas.h"
//#include "Selecciones.h"
//#include "album.h"
//#include "Club.h"
//#include "Manager.h"
#include "herramientas.h"

void perfilAdministrador(sFigurita* figuritas, int size, sSeleccion* selecciones, int sizeSeleccion,sClub* clubes, int sizeClubes,sManager* managers, int sizeManagers);

void perfilColeccionista(sFigurita* figuritas, int sizeFiguritas,sAlbum album, sSeleccion selecciones[],int sizeSelecciones, sClub clubes[], int sizeClubes, sManager managers[], int sizeManagers,int cantidadFiguritas,sFiguritaRepetida repetidas[],int* pContadorFiguritas);


#endif /* PERFIL_H_ */
