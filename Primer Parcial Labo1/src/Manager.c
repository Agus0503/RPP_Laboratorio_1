<<<<<<< HEAD
/*
 * Manager.c
 *
 *  Created on: 11 dic 2022
 *      Author: DIEGO
 */

#include "herramientas.h"

static int manager_ObtenerIDIncremental(void);
static int manager_ObtenerIDIncremental(void)
{
	static int idIncrementalRepresentante = 4; //Comienzo en 4 porque tengo 4 hardcodeados
	return idIncrementalRepresentante++;
}

void manager_inicializar(sManager manager[], int size)
{
	if(manager != NULL && size > 0)
	{
		for(int i = 0; i < size; i++)
		{
			manager[i].estado = LIBRE;
		}
	}
}

int manager_validarArrayCargado(sManager managers[], int sizeManagers)
{
	int retorno;
	retorno = 1;
	if(managers != NULL && sizeManagers > 0)
	{
		for(int i = 0; i < sizeManagers; i++)
		{
			if(managers[i].estado == LIBRE)
			{
				retorno = -1;
				break;
			}
		}
	}
	return retorno;
}


int manager_BuscarIndexLibre(sManager managers[], int sizeManagers)
{
	int index;
	index = -1;

	if(managers != NULL && sizeManagers > 0)
	{
		for(int i = 0; i < sizeManagers; i++)
		{
			if(managers[i].estado == LIBRE)
			{
				index = i;
				break;
			}
		}
	}


	return index;
}
int manager_BuscarID(sManager managers[], int sizeManagers, int id)
{
	int index;
	index = -1;
	if(managers != NULL && sizeManagers > 0)
	{
		for(int i = 0; i < sizeManagers; i++)
		{
			if(managers[i].estado == OCUPADO && managers[i].idManager == id)
			{
				index = i;
				break;
			}
		}
	}

	return index;
}

void manager_MostrarUno(sManager manager)
{
	printf("\n| %-3d  %-20s  %-20s |", manager.idManager,manager.nombre,manager.descripcion);
}

int manager_MostrarTodos(sManager managers[], int sizeManagers)
{
	int retorno = -1;
	int cantidad = 0;

	if(managers != NULL && sizeManagers > 0)
	{
		encabezado_Managers();
		for(int i = 0; i < sizeManagers; i++)
		{
			if(managers[i].estado == OCUPADO)
			{
				manager_MostrarUno(managers[i]);
				cantidad++;
			}
		}
		puts("\n------------------------------------------------------");
	}
	if(cantidad > 0)
	{
		retorno = 1;
	}

	return retorno;
}

int cargarManager(sManager managers[], int sizeManagers)
{
	int id;

	manager_MostrarTodos(managers, sizeManagers);
	obtenerEnteroRemastered(&id, "\nIngrese manager mediante ID: ", "\nLa opcion ingresada es incorrecta ", 200, 204);

	return id;
}

sManager crearManager()
{
	sManager representanteAux;

	obtenerCadena(representanteAux.nombre, 50, "\n Ingrese nombre \n ", "¡Dato invalido!",100);
	obtenerCadenaAlfanumerica(representanteAux.descripcion, 1024, "\nIngrese descripción\n ", "¡Dato invalido!");
	return representanteAux;

}

int altaManager(sManager managers[], int sizeManagers)
{
	sManager auxManager;
	int retorno = -1;
	int index;

	index = manager_BuscarIndexLibre(managers, sizeManagers);

	if(index != -1)
	{
		auxManager = crearManager();
		auxManager.idManager = manager_ObtenerIDIncremental();
		auxManager.estado = OCUPADO;
		managers[index] = auxManager;
		retorno = 1;
	}

	return retorno;
}

sManager manager_ModificarNombre(sManager manager)
{
	sManager auxManager;
	auxManager = manager;

	obtenerCadena(auxManager.nombre, 50, "\nIngrese nuevo Nombre: ","¡Dato invalido!",100);
	manager_MostrarUno(auxManager);

	return auxManager;
}


sManager manager_ModificarDescripcion(sManager manager)
{
	sManager aux;

	aux = manager;

	obtenerCadenaAlfanumerica(aux.descripcion, 1024, "\nIngrese nueva descripción(Campo alfanumerico) ", "¡Dato invalido!");
	manager_MostrarUno(aux);

	return aux;
}

int manager_modificacion(sManager managers[], int sizeManagers)
{
	int retorno = -1;
	int opcion;
	int idManager;
	int index;
	int bandera = 0;
	sManager auxManager;

	if(manager_MostrarTodos(managers, sizeManagers) == 1)
	{
		bandera = 1;
	}

	if(bandera == 1)
	{
		obtenerEnteroRemastered(&idManager, "\nIngrese ID del representante a modificar", "\n¡Dato Invalido!", 1, sizeManagers);

		while(manager_BuscarID(managers, sizeManagers, idManager) == -1)
		{
			puts("\nEL ID INGRESADO NO EXISTE!");
			obtenerEnteroRemastered(&idManager, "\nIngrese ID del representante a modificar", "\n¡Dato Invalido!", 1, sizeManagers);
		}

		index = manager_BuscarID(managers, sizeManagers, idManager);
		auxManager = managers[index];

		do
		{
			obtenerEnteroRemastered(&opcion, "\n1.Modificar nombre del representante "
											"\n2.Modificar descripcion del representante "
											"\n3.Salir ", "\n¡Dato Invalido!", 1, 3);
			switch(opcion)
			{
			case 1:
				auxManager = manager_ModificarNombre(auxManager);
				break;

			case 2:
				auxManager = manager_ModificarDescripcion(auxManager);
				break;

			case 3:
				puts("Regresando..");
				break;

			}


		}while(opcion != 3);

		managers[index] = auxManager;
		retorno = 1;

	}
	return retorno;
}

=======
/*
 * Manager.c
 *
 *  Created on: 11 dic 2022
 *      Author: DIEGO
 */

#include "herramientas.h"

static int manager_ObtenerIDIncremental(void);
static int manager_ObtenerIDIncremental(void)
{
	static int idIncrementalRepresentante = 4; //Comienzo en 4 porque tengo 4 hardcodeados
	return idIncrementalRepresentante++;
}

void manager_inicializar(sManager manager[], int size)
{
	if(manager != NULL && size > 0)
	{
		for(int i = 0; i < size; i++)
		{
			manager[i].estado = LIBRE;
		}
	}
}

int manager_validarArrayCargado(sManager managers[], int sizeManagers)
{
	int retorno;
	retorno = 1;
	if(managers != NULL && sizeManagers > 0)
	{
		for(int i = 0; i < sizeManagers; i++)
		{
			if(managers[i].estado == LIBRE)
			{
				retorno = -1;
				break;
			}
		}
	}
	return retorno;
}


int manager_BuscarIndexLibre(sManager managers[], int sizeManagers)
{
	int index;
	index = -1;

	if(managers != NULL && sizeManagers > 0)
	{
		for(int i = 0; i < sizeManagers; i++)
		{
			if(managers[i].estado == LIBRE)
			{
				index = i;
				break;
			}
		}
	}


	return index;
}
int manager_BuscarID(sManager managers[], int sizeManagers, int id)
{
	int index;
	index = -1;
	if(managers != NULL && sizeManagers > 0)
	{
		for(int i = 0; i < sizeManagers; i++)
		{
			if(managers[i].estado == OCUPADO && managers[i].idManager == id)
			{
				index = i;
				break;
			}
		}
	}

	return index;
}

void manager_MostrarUno(sManager manager)
{
	printf("\n| %-3d  %-20s  %-20s |", manager.idManager,manager.nombre,manager.descripcion);
}

int manager_MostrarTodos(sManager managers[], int sizeManagers)
{
	int retorno = -1;
	int cantidad = 0;

	if(managers != NULL && sizeManagers > 0)
	{
		encabezado_Managers();
		for(int i = 0; i < sizeManagers; i++)
		{
			if(managers[i].estado == OCUPADO)
			{
				manager_MostrarUno(managers[i]);
				cantidad++;
			}
		}
		puts("\n------------------------------------------------------");
	}
	if(cantidad > 0)
	{
		retorno = 1;
	}

	return retorno;
}

int cargarManager(sManager managers[], int sizeManagers)
{
	int id;

	manager_MostrarTodos(managers, sizeManagers);
	obtenerEnteroRemastered(&id, "\nIngrese manager mediante ID: ", "\nLa opcion ingresada es incorrecta ", 200, 204);

	return id;
}

sManager crearManager()
{
	sManager representanteAux;

	obtenerCadena(representanteAux.nombre, 50, "\n Ingrese nombre \n ", "¡Dato invalido!",100);
	obtenerCadenaAlfanumerica(representanteAux.descripcion, 1024, "\nIngrese descripción\n ", "¡Dato invalido!");
	return representanteAux;

}

int altaManager(sManager managers[], int sizeManagers)
{
	sManager auxManager;
	int retorno = -1;
	int index;

	index = manager_BuscarIndexLibre(managers, sizeManagers);

	if(index != -1)
	{
		auxManager = crearManager();
		auxManager.idManager = manager_ObtenerIDIncremental();
		auxManager.estado = OCUPADO;
		managers[index] = auxManager;
		retorno = 1;
	}

	return retorno;
}

sManager manager_ModificarNombre(sManager manager)
{
	sManager auxManager;
	auxManager = manager;

	obtenerCadena(auxManager.nombre, 50, "\nIngrese nuevo Nombre: ","¡Dato invalido!",100);
	manager_MostrarUno(auxManager);

	return auxManager;
}


sManager manager_ModificarDescripcion(sManager manager)
{
	sManager aux;

	aux = manager;

	obtenerCadenaAlfanumerica(aux.descripcion, 1024, "\nIngrese nueva descripción(Campo alfanumerico) ", "¡Dato invalido!");
	manager_MostrarUno(aux);

	return aux;
}

int manager_modificacion(sManager managers[], int sizeManagers)
{
	int retorno = -1;
	int opcion;
	int idManager;
	int index;
	int bandera = 0;
	sManager auxManager;

	if(manager_MostrarTodos(managers, sizeManagers) == 1)
	{
		bandera = 1;
	}

	if(bandera == 1)
	{
		obtenerEnteroRemastered(&idManager, "\nIngrese ID del representante a modificar", "\n¡Dato Invalido!", 1, sizeManagers);

		while(manager_BuscarID(managers, sizeManagers, idManager) == -1)
		{
			puts("\nEL ID INGRESADO NO EXISTE!");
			obtenerEnteroRemastered(&idManager, "\nIngrese ID del representante a modificar", "\n¡Dato Invalido!", 1, sizeManagers);
		}

		index = manager_BuscarID(managers, sizeManagers, idManager);
		auxManager = managers[index];

		do
		{
			obtenerEnteroRemastered(&opcion, "\n1.Modificar nombre del representante "
											"\n2.Modificar descripcion del representante "
											"\n3.Salir ", "\n¡Dato Invalido!", 1, 3);
			switch(opcion)
			{
			case 1:
				auxManager = manager_ModificarNombre(auxManager);
				break;

			case 2:
				auxManager = manager_ModificarDescripcion(auxManager);
				break;

			case 3:
				puts("Regresando..");
				break;

			}


		}while(opcion != 3);

		managers[index] = auxManager;
		retorno = 1;

	}
	return retorno;
}

>>>>>>> 8aeee1b24af3eadd99da22d7a0b9a252ee1d16d6
