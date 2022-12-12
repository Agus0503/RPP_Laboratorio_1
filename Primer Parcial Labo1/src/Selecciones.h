/*
 * Selecciones.h
 *
 *  Created on: 11 dic 2022
 *      Author: DIEGO
 */

#ifndef SELECCIONES_H_
#define SELECCIONES_H_

#define SIZE_CADENA 50
#define CANT_SELECCIONES 5
#define LIBRE 0
#define OCUPADO 1

typedef struct {

	int idSeleccion;
	char seleccion[SIZE_CADENA];
	char directorTecnico[SIZE_CADENA];
	int contador;
	int estado;

}sSeleccion;


void selecciones_MostrarUna(sSeleccion seleccion);
int selecciones_MostrarTodas(sSeleccion selecciones[], int sizeSelecciones);

/**
 * @brief Cargo los datos de la seleccion ingresada por el ususario a través de su ID
 *
 * @param selecciones
 * @param sizeSeleccion
 * @return retorno el id
 */
int cargarSeleccion(sSeleccion selecciones[], int sizeSeleccion);

/**
 * @brief Busco el indice de un elemento a través de su ID
 *
 * @param selecciones
 * @param sizeSeleccion
 * @param id
 * @return retorno el indice del elemento que busque
 */
int selecciones_BuscarID(sSeleccion selecciones[], int sizeSeleccion, int id);

/**
 * @brief Valido cantidad maxima de 22 jugadores por selección
 *
 * @param idSeleccionAux
 * @param selecciones
 * @param sizeSelecciones
 * @return 1 si se ejecuto correctamente
 * 		  -1 si no
 */
int seleccion_validarCantidadJugadores(int idSeleccionAux,sSeleccion selecciones[], int sizeSelecciones);

#endif /* SELECCIONES_H_ */
