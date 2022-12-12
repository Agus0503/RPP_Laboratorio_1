/*
 * Club.h
 *
 *  Created on: 4 dic 2022
 *      Author: DIEGO
 */

#ifndef CLUB_H_
#define CLUB_H_

#define SIZE_CADENA 50

typedef struct
{
	int idClub;
	char nombre[SIZE_CADENA];
	char entrenador[SIZE_CADENA];
	int anioFundacion;
	int estado;
}sClub;

/**
 * \brief muestreo de un club
 *
 * \param club variable tipo eEquipo que guarda los datos de un club
 */
void club_mostrarUnClub(sClub club);

/**
 * \brief Funcion que lista los clubs
 *
 * \param arrayClubs array a estructura eClub
 * \param sizeClubes tamaño de la lista de clubes
 * \return retorno retorna -1 si esta mal y 0 si esta bien
 */
int club_listarClubes(sClub arrayClubs[], int sizeClubes);


/**
 * @brief Busco un elemento a través del ID
 *
 * @param clubes
 * @param sizeClub
 * @param id
 * @return retorno el índice del elemento encontrado
 */
int club_BuscarID(sClub clubes[], int sizeClub, int id);


/**
 * @brief Cargo un club mediante ID
 *
 * @param clubes
 * @param sizeClub
 * @param id
 * @return retorno el id ingresado por el usuario
 */
int cargarClub(sClub clubes[], int sizeClub);


#endif /* CLUB_H_ */
