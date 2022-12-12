/*
 * figuritas.c
 *
 *  Created on: 27 sept 2022
 *      Author: DIEGO
 */

#include "herramientas.h"

int inicializarFiguritas(sFigurita array[], int size)
{
	int retorno = -1;

	if (array != NULL && size > 0)
	{
		for (int i = 0; i < size; i++)
		{
			array[i].estado = LIBRE;
		}

		retorno = 1;
	}

	return retorno;
}

	/* ========================================= DESARROLLO PERFIL ADMINISTRADOR =========================================*/

static int obtenerID(void);
static int obtenerID(void)
{
	static int idAutoIncremental = 54;
	return idAutoIncremental++;
}

int figuritas_obtenerIndexLibre(sFigurita array[], int size)
{

	int retorno = -1;

	if (array != NULL && size > 0)
	{
		for (int i = 0; i < size; i++)
		{
			if (array[i].estado == LIBRE)
			{
				retorno = i;
				break;
			}
		}
	}

	return retorno;
}

int cargarDatos(sFigurita* figuritas, int size, int idFigurita, char nombreJugador[],char posicion[],int idClub,int idManager,int idSeleccion,float altura,float peso,int anioIngresoSeleccion,int dia,int mes,int anio)
{
	int retorno = -1;
	int index;
	sFigurita aux;

	if(figuritas!=NULL && size >= 0)
	{
		index = figuritas_obtenerIndexLibre(figuritas,size);

		if (index >= 0)
		{
			aux.idFigurita = idFigurita;
			strcpy(aux.nombreJugador, nombreJugador);
			strcpy(aux.posicion,posicion);
			aux.idClub = idClub;
			aux.idManager = idManager;
			aux.idSeleccion = idSeleccion;
			aux.altura = altura;
			aux.peso = peso;
			aux.anioIngresoSeleccion = anioIngresoSeleccion;
			aux.fechaNacimiento.dia = dia;
			aux.fechaNacimiento.mes = mes;
			aux.fechaNacimiento.anio = anio;
			aux.estado = OCUPADO;

			retorno = 1;
			figuritas[index] = aux;
		}

	}

	return retorno;
}

int Alta(sFigurita arrayFiguritas[], int size, sSeleccion selecciones[],int sizeSelecciones,sClub clubes[],int sizeClubes,sManager managers[],int sizeManagers)
{
	int retorno = -1;
	int index;
	sFigurita auxFigurita;
	int auxIdSeleccion;

	index = figuritas_obtenerIndexLibre(arrayFiguritas,size);

	if(index != -1)
	{
		if((arrayFiguritas != NULL && size >= 0))
		{
			auxFigurita.idFigurita = obtenerID();
			obtenerCadena(auxFigurita.nombreJugador, SIZE_CADENA, "\nIngrese nombre del jugador: ", "¡DATO INVALIDO!", 50);
			obtenerCadena(auxFigurita.posicion, SIZE_CADENA, "\nIngrese posicion: ", "¡Dato invalido!", 50);
			mayusculaInicial(auxFigurita.posicion);
			while(stricmp(auxFigurita.posicion,"Arquero") && stricmp(auxFigurita.posicion,"Defensor") && stricmp(auxFigurita.posicion,"MedioCampista") && stricmp(auxFigurita.posicion,"Delantero"))
			{
				obtenerCadena(auxFigurita.posicion, SIZE_CADENA, "\nIngrese posicion: ", "¡Dato invalido!", 50);
				mayusculaInicial(auxFigurita.posicion);
			}

			auxIdSeleccion = cargarSeleccion(selecciones, sizeSelecciones);
			seleccion_validarCantidadJugadores(auxIdSeleccion, selecciones, sizeSelecciones);
			while(seleccion_validarCantidadJugadores(auxIdSeleccion,selecciones, sizeSelecciones) == -1)
			{
				selecciones_MostrarTodas(selecciones, sizeSelecciones);
				obtenerEnteroRemastered(&auxIdSeleccion, "\nIngrese el ID de la seleccion: ", "\n¡Dato invalido!", 100, 104);
			}
			auxFigurita.idSeleccion = auxIdSeleccion;

			auxFigurita.idClub = cargarClub(clubes, sizeClubes);
			auxFigurita.idManager = cargarManager(managers, sizeManagers);
			obtenerNumeroFlotante(&auxFigurita.altura,"\nIngrese altura del jugador(Expresada en metros): " , "¡Dato invalido!", 1.00, 2.10, 50);
			obtenerNumeroFlotante(&auxFigurita.peso,"\nIngrese peso del jugador(Expresado en Kg): " , "Valor invalido, ", 50.00, 80.00, 50);
			obtenerEnteroRemastered(&auxFigurita.anioIngresoSeleccion, "\nIngrese el año de ingreso a la seleccion: ", "¡Dato incorrecto!", 2000, 2022);
			puts("\nIngrese fecha de nacimiento: \n");
			obtenerEnteroRemastered(&auxFigurita.fechaNacimiento.dia, "Dia: ", "Dato incorrecto", 1, 31);
			obtenerEnteroRemastered(&auxFigurita.fechaNacimiento.mes, "Mes: ", "Dato incorrecto", 1, 12);
			obtenerEnteroRemastered(&auxFigurita.fechaNacimiento.anio, "Año: ", "Dato incorrecto", 1980, 2002);

			if(cargarDatos(arrayFiguritas, size, auxFigurita.idFigurita, auxFigurita.nombreJugador,arrayFiguritas->posicion,
				auxFigurita.idClub,auxFigurita.idManager,auxFigurita.idSeleccion,auxFigurita.altura, auxFigurita.peso,
				auxFigurita.anioIngresoSeleccion,auxFigurita.fechaNacimiento.dia,
				auxFigurita.fechaNacimiento.mes,auxFigurita.fechaNacimiento.anio) == 1)
			{
				retorno = 1;
			}else{
				puts("HUBO UN ERROR EN LA CARGA DE DATOS");
			}

		}

	}else{
		puts("SIN ESPACIO PARA ALMACENAR");
	}


	return retorno;
}


int buscarID(sFigurita array[], int size, int ID)
{
	int retorno = -1;

	if (array != NULL && size > 0)
	{
		for (int i = 0; i < size; i++)
		{
			if (array[i].idFigurita == ID && array[i].estado == OCUPADO)
			{
				retorno = i;
				break;
			}
		}
	}

	return retorno;
}

sFigurita modificar(sFigurita unaFigurita, sSeleccion selecciones[], int sizeSeleccion,sClub clubes[],int sizeClubes,sManager managers[],int sizeManagers)
{
	int opcion;
	int dia;
	int mes;
	int anio;
	int auxIdSeleccion;

	do{

		puts("\nQue dato desea modificar?"
					"\n1.Nombre del Jugador"
					"\n2.Posicion"
					"\n3.Seleccion"
					"\n4.Club"
					"\n5.Manager"
					"\n6.Altura"
					"\n7.Peso"
					"\n8.Año de ingreso a la seleccion"
					"\n9.Fecha de nacimiento"
					"\n10.VOLVER ATRAS");

			obtenerEnteroRemastered(&opcion, "Seleccione dato: ", "La opcion ingresada es incorrecta!", 1, 10);

		switch (opcion)
		{
			case 1:
				obtenerCadena(unaFigurita.nombreJugador, SIZE_CADENA, "\nIngrese nombre del jugador: ", "¡Dato invalido!", 50);
				break;

			case 2:
				obtenerCadena(unaFigurita.posicion, SIZE_CADENA, "\nIngrese nueva posicion: ", "¡Dato invalido!", 50);
				mayusculaInicial(unaFigurita.posicion);
				while(stricmp(unaFigurita.posicion,"Arquero") && stricmp(unaFigurita.posicion,"Defensor") && stricmp(unaFigurita.posicion,"MedioCampista") && stricmp(unaFigurita.posicion,"Delantero"))
				{
					obtenerCadena(unaFigurita.posicion, SIZE_CADENA, "\nIngrese posicion: ", "¡Dato invalido!", 50);
					mayusculaInicial(unaFigurita.posicion);
				}
				break;

			case 3:
				auxIdSeleccion = cargarSeleccion(selecciones, sizeSeleccion);
				seleccion_validarCantidadJugadores(auxIdSeleccion, selecciones, sizeSeleccion);
				while(seleccion_validarCantidadJugadores(auxIdSeleccion,selecciones, sizeSeleccion) == -1)
				{
					selecciones_MostrarTodas(selecciones, sizeSeleccion);
					obtenerEnteroRemastered(&auxIdSeleccion, "\nIngrese el ID de la seleccion "
																"\nPara cancelar ingrese el numero '105': ", "\n¡Dato invalido!", 100, 105);
					if(auxIdSeleccion == 105)
					{
						break;
					}

				}
				unaFigurita.idSeleccion = auxIdSeleccion;
				break;

			case 4:
				unaFigurita.idClub = cargarClub(clubes, sizeClubes);
				break;

			case 5:
				unaFigurita.idManager = cargarManager(managers, sizeManagers);
				break;

			case 6:
				obtenerNumeroFlotante(&unaFigurita.altura,"\nIngrese altura del jugador(Expresada en metros): " , "¡Dato invalido!", 1.00, 2.20, 0);
				break;

			case 7:
				obtenerNumeroFlotante(&unaFigurita.peso,"\nIngrese peso del jugador(Expresado en Kg): " , "Valor invalido, ", 50.00, 80.00, 0);
				break;

			case 8:
				obtenerEnteroRemastered(&unaFigurita.anioIngresoSeleccion,"\nIngrese el año de ingreso a la seleccion: ", "¡Dato incorrecto!", 2000, 2022);
				break;

			case 9:
				puts("\nIngrese nueva fecha de nacimiento: \n");
				obtenerEnteroRemastered(&dia, "Dia: ", "Dato incorrecto", 1, 31);
				obtenerEnteroRemastered(&mes, "Mes: ", "Dato incorrecto", 1, 12);
				obtenerEnteroRemastered(&anio, "Año: ", "Dato incorrecto", 1980, 2002);
				unaFigurita.fechaNacimiento.dia = dia;
				unaFigurita.fechaNacimiento.mes = mes;
				unaFigurita.fechaNacimiento.anio = anio;
				break;

			case 10:
				puts("Regresando..");
				break;

			default:
				puts("La opcion ingresada es incorrecta!");
				break;

		}

	} while(opcion != 10);

	return unaFigurita;
}

int modificacion(sFigurita array[], int size,sSeleccion selecciones[],int sizeSeleccion,sClub clubes[],int sizeClub,sManager managers[],int sizeManagers)
{
	int retorno = -1;
	int id;
	int index;
	int bandera = 0;
	sFigurita aux;


	if(figurita_MostrarTodas(array, size, clubes, sizeClub, selecciones, sizeSeleccion, managers, sizeManagers))
	{
		bandera = 1;
	}

	if (bandera)
	{
		obtenerEnteroRemastered(&id, "INGRESE ID A MODIFICAR: ", "ID INCORRECTO", 1, CANT_FIGURITAS);

		while (buscarID(array, size, id) == -1)
		{
			obtenerEnteroRemastered(&id, "INGRESE ID A MODIFICAR: ", "ID INCORRECTO", 1, CANT_FIGURITAS);
		}

		index = buscarID(array, size, id);

		aux = modificar(array[index], selecciones, sizeSeleccion,clubes,sizeClub,managers,sizeManagers);

		array[index] = aux;

		retorno = 1;
	}

	return retorno;
}

int figurita_MostrarRepetida(sFiguritaRepetida arrayRepetidas[],sFigurita figuritas[], int cantFiguritas, sClub clubes[], int sizeClub,sSeleccion selecciones[], int sizeSeleccion,sManager managers[], int sizeManagers)
{
	int retorno = -1;
	int hayRepetidas = 0;

	if(arrayRepetidas != NULL && figuritas != NULL && cantFiguritas > 0 && clubes != NULL && sizeClub > 0 && selecciones != NULL && sizeSeleccion > 0 && managers != NULL && sizeManagers > 0 )
	{
		encabezado_figuritas();
		for(int i = 0; i < cantFiguritas; i ++)
		{
			if(arrayRepetidas[i].cantidadRepetidas > 0)
			{
				hayRepetidas = 1;
				figurita_MostrarUna(figuritas[i + 1], clubes, sizeClub, selecciones, sizeSeleccion, managers, sizeManagers);
				printf("Veces repetida -> %-3d\n",arrayRepetidas[i].cantidadRepetidas);
			}
		}

		retorno = 1;
		if(hayRepetidas == 0)
		{
			puts("No hay figuritas repetidas");
			retorno = -1;
		}
	}

	return retorno;
}


/*------------------------------------------------------------------------------------------------------------*/

void figurita_MostrarUna(sFigurita unaFigurita,sClub clubes[],int sizeClubes,sSeleccion selecciones[], int sizeSelecciones,sManager managers[], int sizeManagers)
{
	char auxManager[SIZE_CADENA];
	char auxSeleccion[SIZE_CADENA];
	char auxClub[SIZE_CADENA];

	if((manager_getNombre(unaFigurita, managers, sizeManagers, auxManager) != -1) && (selecciones_getNombre(unaFigurita, selecciones, sizeSelecciones, auxSeleccion) != -1) && (clubes_getNombre(unaFigurita, clubes, sizeClubes, auxClub) != -1) )
	{
		printf("| %-3d | %-20s | %-20s | %-20s | %-20s | %-20s |%-8.2f | %-8.2f | %-15d | %-3d / %-3d / %-3d |", unaFigurita.idFigurita, unaFigurita.nombreJugador, unaFigurita.posicion,auxSeleccion,auxClub,auxManager,unaFigurita.altura,unaFigurita.peso,unaFigurita.anioIngresoSeleccion,unaFigurita.fechaNacimiento.dia,unaFigurita.fechaNacimiento.mes,unaFigurita.fechaNacimiento.anio);
		puts("\n----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------");

	}else{

		puts("ERROR DE NUESTREO");
	}

}

int figurita_MostrarTodas(sFigurita figuritas[],int cantFiguritas,sClub clubes[],int sizeClub,sSeleccion selecciones[], int sizeSelecciones,sManager managers[], int sizeManagers)
{
	int retorno = -1;
	int cantidad = 0;

	if(figuritas != NULL && cantFiguritas > 0)
	{
		encabezado_figuritas();
		for(int i = 0; i < cantFiguritas; i++)
		{
			if(figuritas[i].estado == OCUPADO)
			{
				figurita_MostrarUna(figuritas[i],clubes,sizeClub,selecciones,sizeSelecciones,managers,sizeManagers);
				cantidad++;
			}
		}
	}

	if(cantidad > 0)
	{
		retorno = 1;
	}

	return retorno;
}
