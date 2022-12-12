<<<<<<< HEAD
/*
 * herramientas.h
 *
 *  Created on: 2 dic 2022
 *      Author: DIEGO
 */

#ifndef HERRAMIENTAS_H_
#define HERRAMIENTAS_H_

#include "album.h"
#include "figuritas.h"
#include "Club.h"
#include "Manager.h"


void encabezado_figuritas();

int figuritas_mostrarPegadas(sAlbum album,sFigurita figuritas[], int cantFiguritas, sClub clubes[], int sizeClubes,sSeleccion selecciones[], int sizeSelecciones,sManager managers[], int sizeManagers);

int figuritas_MostrarDoradas(sAlbum album,sFigurita figuritas[], int cantFiguritas, sClub clubes[], int sizeClubes,sSeleccion selecciones[], int sizeSeleccion,sManager managers[], int sizeManagers);

void encabezado_Selecciones();
int selecciones_getNombre(sFigurita unaFigurita, sSeleccion selecciones[], int sizeSelecciones,char* seleccion);

void encabezado_Club();
int clubes_getNombre(sFigurita unaFigurita, sClub clubes[], int sizeClubes, char* nombreClubAux);

void encabezado_Managers();
int manager_getNombre(sFigurita figurita, sManager managers[], int sizeManagers,char* auxManager);

void clubes_filtro(sFigurita figuritas[],int cantFiguritas,sClub clubes[],int sizeClubes,sSeleccion selecciones[],int sizeSelecciones,sManager managers[], int sizeManagers);
void selecciones_filtro(sFigurita figuritas[],int cantFiguritas,sClub clubes[],int sizeClubes,sSeleccion selecciones[],int sizeSelecciones,sManager managers[], int sizeManagers);
void managers_filtro(sFigurita figuritas[],int cantFiguritas,sClub clubes[],int sizeClubes,sSeleccion selecciones[],int sizeSelecciones,sManager managers[], int sizeManagers);

void mostrarPaquetesLleno(int cantSobresTotal,sAlbum album);

#endif /* HERRAMIENTAS_H_ */
=======
/*
 * herramientas.h
 *
 *  Created on: 2 dic 2022
 *      Author: DIEGO
 */

#ifndef HERRAMIENTAS_H_
#define HERRAMIENTAS_H_

#include "album.h"
#include "figuritas.h"
#include "Club.h"
#include "Manager.h"


void encabezado_figuritas();

int figuritas_mostrarPegadas(sAlbum album,sFigurita figuritas[], int cantFiguritas, sClub clubes[], int sizeClubes,sSeleccion selecciones[], int sizeSelecciones,sManager managers[], int sizeManagers);

int figuritas_MostrarDoradas(sAlbum album,sFigurita figuritas[], int cantFiguritas, sClub clubes[], int sizeClubes,sSeleccion selecciones[], int sizeSeleccion,sManager managers[], int sizeManagers);

void encabezado_Selecciones();
int selecciones_getNombre(sFigurita unaFigurita, sSeleccion selecciones[], int sizeSelecciones,char* seleccion);

void encabezado_Club();
int clubes_getNombre(sFigurita unaFigurita, sClub clubes[], int sizeClubes, char* nombreClubAux);

void encabezado_Managers();
int manager_getNombre(sFigurita figurita, sManager managers[], int sizeManagers,char* auxManager);

void clubes_filtro(sFigurita figuritas[],int cantFiguritas,sClub clubes[],int sizeClubes,sSeleccion selecciones[],int sizeSelecciones,sManager managers[], int sizeManagers);
void selecciones_filtro(sFigurita figuritas[],int cantFiguritas,sClub clubes[],int sizeClubes,sSeleccion selecciones[],int sizeSelecciones,sManager managers[], int sizeManagers);
void managers_filtro(sFigurita figuritas[],int cantFiguritas,sClub clubes[],int sizeClubes,sSeleccion selecciones[],int sizeSelecciones,sManager managers[], int sizeManagers);

void mostrarPaquetesLleno(int cantSobresTotal,sAlbum album);

#endif /* HERRAMIENTAS_H_ */
>>>>>>> 8aeee1b24af3eadd99da22d7a0b9a252ee1d16d6
