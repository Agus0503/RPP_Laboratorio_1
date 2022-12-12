<<<<<<< HEAD
/*
 * Manager.h
 *
 *  Created on: 11 dic 2022
 *      Author: DIEGO
 */

#ifndef MANAGER_H_
#define MANAGER_H_
#include "inputs.h"
#define LIBRE 0
#define OCUPADO 1
#define SIZE_MANAGERS 5
#define SIZE_CADENA 50

typedef struct{

	int idManager;
	char nombre[SIZE_CADENA];
	char descripcion[SIZE_CADENA];
	int estado;

}sManager;


/**
 * @brief Inicializo lista de managers
 *
 * @param manager
 * @param sizeManager
 */
void manager_inicializar(sManager manager[], int sizeManager);


/**
 * @brief Valido que haya aun que sea un indice ocupado
 *
 * @param managers
 * @param sizeManagers
 * @return 1 si el array esta ocupado
 * 		  -1 si el array esta vacío
 */
int manager_validarArrayCargado(sManager managers[], int sizeManagers);

/**
 * @brief  Busco por un elemento que tenga el indice disponible
 *
 * @param managers
 * @param sizeManagers
 * @return Retorno el indice del elemento
 */
int manager_BuscarIndexLibre(sManager managers[], int sizeManagers);

/**
 * @brief Busco el indice de un elemento a través de su ID
 *
 * @param managers
 * @param sizeManagers
 * @param id
 * @return retorno el indice del elemento que busque
 */
int manager_BuscarID(sManager managers[], int sizeManagers, int id);

/**
 * @brief Muestreo de un manager
 *
 * @param manager
 * @return
 */
void manager_MostrarUno(sManager manager);

/**
 * @brief Muestreo de todos los managers
 *
 * @param manager
 * @param sizeManagers
 * @return 1 si se pudo mostrar
 * 		  -1 si no
 */
int manager_MostrarTodos(sManager manager[], int sizeManagers);

/**
 * @brief Cargo un managers
 *
 * @param managers
 * @param sizeManagers
 * @return id ingresado por el usuario
 */
int cargarManager(sManager managers[], int sizeManagers);

/**
 * @brief Creo un Manager
 *
 * @return
 */
sManager crearManager();

/**
 * @brief gener el id de manager, setteo su estado en ocupado y la inserto en el array con index disponible
 *
 * @param managers
 * @param sizeManagers
 * @return 1 si se pudo mostrar
 * 		  -1 si no
 */
int altaManager(sManager managers[], int sizeManagers);

/**
 * @brief menu de managers
 *
 * @param managers
 * @param sizeManagers
 * @return
 */
int manager_modificacion(sManager managers[], int sizeManagers);

/**
 * @brief modifico nombre del manager
 *
 * @param manager
 * @return
 */
sManager manager_ModificarNombre(sManager manager);

/**
 * @brief modifico Descripción del manager
 *
 * @param manager
 * @return
 */
sManager manager_ModificarDescripcion(sManager manager);


#endif /* MANAGER_H_ */
=======
/*
 * Manager.h
 *
 *  Created on: 11 dic 2022
 *      Author: DIEGO
 */

#ifndef MANAGER_H_
#define MANAGER_H_
#include "inputs.h"
#define LIBRE 0
#define OCUPADO 1
#define SIZE_MANAGERS 5
#define SIZE_CADENA 50

typedef struct{

	int idManager;
	char nombre[SIZE_CADENA];
	char descripcion[SIZE_CADENA];
	int estado;

}sManager;


/**
 * @brief Inicializo lista de managers
 *
 * @param manager
 * @param sizeManager
 */
void manager_inicializar(sManager manager[], int sizeManager);


/**
 * @brief Valido que haya aun que sea un indice ocupado
 *
 * @param managers
 * @param sizeManagers
 * @return 1 si el array esta ocupado
 * 		  -1 si el array esta vacío
 */
int manager_validarArrayCargado(sManager managers[], int sizeManagers);

/**
 * @brief  Busco por un elemento que tenga el indice disponible
 *
 * @param managers
 * @param sizeManagers
 * @return Retorno el indice del elemento
 */
int manager_BuscarIndexLibre(sManager managers[], int sizeManagers);

/**
 * @brief Busco el indice de un elemento a través de su ID
 *
 * @param managers
 * @param sizeManagers
 * @param id
 * @return retorno el indice del elemento que busque
 */
int manager_BuscarID(sManager managers[], int sizeManagers, int id);

/**
 * @brief Muestreo de un manager
 *
 * @param manager
 * @return
 */
void manager_MostrarUno(sManager manager);

/**
 * @brief Muestreo de todos los managers
 *
 * @param manager
 * @param sizeManagers
 * @return 1 si se pudo mostrar
 * 		  -1 si no
 */
int manager_MostrarTodos(sManager manager[], int sizeManagers);

/**
 * @brief Cargo un managers
 *
 * @param managers
 * @param sizeManagers
 * @return id ingresado por el usuario
 */
int cargarManager(sManager managers[], int sizeManagers);

/**
 * @brief Creo un Manager
 *
 * @return
 */
sManager crearManager();

/**
 * @brief gener el id de manager, setteo su estado en ocupado y la inserto en el array con index disponible
 *
 * @param managers
 * @param sizeManagers
 * @return 1 si se pudo mostrar
 * 		  -1 si no
 */
int altaManager(sManager managers[], int sizeManagers);

/**
 * @brief menu de managers
 *
 * @param managers
 * @param sizeManagers
 * @return
 */
int manager_modificacion(sManager managers[], int sizeManagers);

/**
 * @brief modifico nombre del manager
 *
 * @param manager
 * @return
 */
sManager manager_ModificarNombre(sManager manager);

/**
 * @brief modifico Descripción del manager
 *
 * @param manager
 * @return
 */
sManager manager_ModificarDescripcion(sManager manager);


#endif /* MANAGER_H_ */
>>>>>>> 8aeee1b24af3eadd99da22d7a0b9a252ee1d16d6
