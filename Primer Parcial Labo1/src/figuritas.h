/*
 * figuritas.h
 *
 *  Created on: 27 sept 2022
 *      Author: DIEGO
 */

#ifndef FIGURITAS_H_
#define FIGURITAS_H_

#include "Selecciones.h"
#include "Club.h"
#include "Manager.h"
#define CANT_FIGURITAS 55
#define CANT_FIGURITAS 55
#define SIZE_REPETIDAS 1000
#define SIZE_CLUBES 11

typedef struct{

	int dia;
	int mes;
	int anio;

}sFecha;

typedef struct{

	int idFigurita;
	char nombreJugador[SIZE_CADENA];
	char posicion[SIZE_CADENA];
	int idSeleccion;
	int idClub;
	int idManager;
	float altura;
	float peso;
	int anioIngresoSeleccion;
	sFecha fechaNacimiento;
	int estado;
	int estado_Album;
	int esDorada;

}sFigurita;


typedef struct{

	int idFiguritaRepetida;
	int cantidadRepetidas;

}sFiguritaRepetida;


/// @brief
/// @param array
/// @param size
/// @return
int inicializarFiguritas(sFigurita array[], int size);

/*--------------------------- ALTA ---------------------------*/
/// @brief
/// @param array
/// @param size
/// @return
int figuritas_obtenerIndexLibre(sFigurita array[], int size);


int cargarDatos(sFigurita* figuritas, int size, int idFigurita, char nombreJugador[],char posicion[],int idClub,int idManager,int idSeleccion,float altura,float peso,int anioIngresoSeleccion,int dia,int mes,int anio);


/// @brief
/// @param array
/// @param size
/// @return
int Alta(sFigurita arrayFiguritas[], int size, sSeleccion selecciones[],int sizeSelecciones,sClub clubes[],int sizeClubes,sManager managers[],int sizeManagers);

/*--------------------------- MODIFICACION ---------------------------*/
/// @brief
/// @param array
/// @param size
/// @param ID
/// @return
int buscarID(sFigurita array[], int size, int ID);


sFigurita modificar(sFigurita unaFigurita, sSeleccion selecciones[], int sizeSeleccion,sClub clubes[],int sizeClubes,sManager managers[],int sizeManagers);


int modificacion(sFigurita array[], int size,sSeleccion selecciones[],int sizeSeleccion,sClub clubes[],int sizeClub,sManager managers[],int sizeManagers);

/*--------------------------- INFORMES ---------------------------*/
void figurita_MostrarUna(sFigurita unaFigurita,sClub clubes[],int sizeClubes,sSeleccion selecciones[], int sizeSelecciones,sManager managers[], int sizeManagers);
int figurita_MostrarTodas(sFigurita figuritas[],int cantFiguritas,sClub clubes[],int sizeClub,sSeleccion selecciones[], int sizeSelecciones,sManager managers[], int sizeManagers);

int figurita_MostrarRepetida(sFiguritaRepetida arrayRepetidas[],sFigurita figuritas[], int cantFiguritas, sClub clubes[], int sizeClub,sSeleccion selecciones[], int sizeSeleccion,sManager managers[], int sizeManagers);


void figurita_mostrar(int ID, sFigurita figuritas[], int sizeFiguritas, sSeleccion selecciones[], int sizeSeleccion);

/*****************************************************************************************************************************/

#endif /* FIGURITAS_H_ */
