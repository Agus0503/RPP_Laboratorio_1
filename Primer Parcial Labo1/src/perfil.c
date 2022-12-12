<<<<<<< HEAD
/*
 * perfil.c
 *
 *  Created on: 2 dic 2022
 *      Author: DIEGO
 */

#include "perfil.h"
#include "herramientas.h"
		/*-------------------------------------------------------- PERFIL ADMINISTRADOR --------------------------------------------------------*/


void perfilAdministrador(sFigurita* figuritas, int size, sSeleccion* selecciones, int sizeSeleccion,sClub* clubes, int sizeClubes,sManager* managers, int sizeManagers)
{
	int opcion;

	do{
		puts("\n-----------------------------------------");
		puts("\tPERFIL ADMINISTRADOR");
		puts("-----------------------------------------");
		obtenerEnteroRemastered(&opcion, "\n1. Alta"
										 "\n2. Modificacion"
										 "\n3. Acceder a listas"
										 "\n4. VOLVER AL INICIO"
										 "\nINGRESE UNA OPCION: ", "ERROR,seleccione las opciones disponibles", 1, 4);

		switch(opcion)
		{

		case 1:

			if(Alta(figuritas, CANT_FIGURITAS ,selecciones,CANT_SELECCIONES,clubes,sizeClubes,managers,sizeManagers) == 1)
			{
				puts("DADO DE ALTA EXITOSAMENTE");
			}
		break;

		case 2:
			if(modificacion(figuritas, size, selecciones, sizeSeleccion,clubes,sizeClubes,managers,sizeManagers))
			{
				puts("\nMODIFICACION EXITOSA\n");
			}else{
				puts("\nMODIFICACION CANCELADA");
			}

		break;

		case 3:

				puts("-------------MENU DE LISTAS---------------");

			do{

			obtenerEnteroRemastered(&opcion,"\n1.Lista de figuritas"
											"\n2.Lista de Clubes"
											"\n3.Lista de Selecciones"
											"\n4.Lista de Managers"
											"\n5.Filtrar"
											"\n6.Salir"
											"\nIngrese una opcion: ", "\nLa opcion ingresada es incorrecta!,vuelva a intentarlo: ", 1, 6);

				switch(opcion)
				{
					case 1:
						if(figurita_MostrarTodas(figuritas, size, clubes, sizeClubes, selecciones, sizeSeleccion, managers, sizeManagers))
						{
							system("pause");
						}else{
							puts("No hay nada para mostrar");
						}
						break;

					case 2:
						if(club_listarClubes(clubes, sizeClubes) == 1)
						{
							system("pause");

						}else{
							puts("No hay clubes para mostrar");
						}
						break;

					case 3:
						if(selecciones_MostrarTodas(selecciones, sizeSeleccion) == 1)
						{
							system("pause");

						}else{
							puts("No hay selecciones para mostrar");
						}
						break;

					case 4:
						if(manager_MostrarTodos(managers, sizeManagers) == 1)
						{
							system("pause");

						}else{
							puts("No hay managers para mostrar");
						}
						break;

					case 5://Filtros

						do{
							obtenerEnteroRemastered(&opcion, "\n1.Filtrar jugadores por Club"
															"\n2.Filtrar jugadores por Selecciones"
															"\n3.Filtrar por Managers"
															"\n4.Salir"
															"\nIngrese una opcion: ", "\nLa opcion ingresada es incorrecta!", 1, 4);

							switch(opcion)
							{
								case 1:
									clubes_filtro(figuritas, size, clubes, sizeClubes, selecciones, sizeSeleccion, managers, sizeManagers);
									system("pause");
									break;

								case 2:
									selecciones_filtro(figuritas, size, clubes, sizeClubes, selecciones, sizeSeleccion, managers, sizeManagers);
									system("pause");

									break;

								case 3:
									managers_filtro(figuritas, size, clubes, sizeClubes, selecciones, sizeSeleccion, managers, sizeManagers);
									break;

								case 4:
									puts("Regresando..");

									break;

							}

						}while(opcion != 4);

						break;

					case 6:
						puts("Regresando..");
						break;
				}

			}while(opcion != 6);

		break;

		case 4:
			puts("Regresando..");
			break;

		}

	}while(opcion != 4);
}


/*-------------------------------------------------------- PERFIL COLECCIONISTA --------------------------------------------------------*/

void perfilColeccionista(sFigurita* figuritas, int sizeFiguritas,sAlbum album, sSeleccion selecciones[],int sizeSelecciones, sClub clubes[], int sizeClubes, sManager managers[], int sizeManagers,int cantidadFiguritas,sFiguritaRepetida repetidas[],int* pContadorFiguritas)
{
	int opcion;
	int paquetesComprados = 0;
	int cantTotalPaquetes;
	int precio_por_unidad = 170;
	int dineroGastadoActual;
	float dineroTotalGatado;

	inicializarRepetidas(repetidas, figuritas, sizeFiguritas);
	album = inicializarAlbum(album, sizeFiguritas);

	do{

		if((VerificarAlbumLleno(album, cantidadFiguritas) == 1) && album.estado == LIBRE)
		{
			dineroTotalGatado = (float)precio_por_unidad * paquetesComprados;
			printf("\nEl album esta completo,buen trabajo!");
			album.estado = OCUPADO;
			printf("\nDinero total gastado: %.2f",dineroTotalGatado);
		}

		puts("\n-----------------------------------------");
		puts("\tPERFIL COLECCIONISTA");
		puts("-----------------------------------------");
		puts("\n1. Comprar paquete de figuritas"
			 "\n2. Intercambiar figuritas"
			 "\n3. Ver figuritas repetidas"
			 "\n4. Ver figuritas pegadas"
			 "\n5. Ver DORADAS"
			 "\n6. Cantidad Sobres Comprados"
			 "\n7. Cantidad de sobres comprados para llenar el album"
			 "\n8. Cantidad de dinero que lleva gastando el coleccionista"
			 "\n9. VOLVER AL INICIO");

	obtenerNumero(&opcion, "\nSeleccione su opcion: ", "ERROR,seleccione las opciones disponibles", 1, 9, 0);

	switch(opcion)
	{

	case 1:
		album = comprarPaquete(album, repetidas, pContadorFiguritas, figuritas, cantidadFiguritas, selecciones,sizeSelecciones,clubes,sizeClubes,managers,sizeManagers);
			cantTotalPaquetes = paquetesComprados++;
			dineroGastadoActual = (float)precio_por_unidad * paquetesComprados;
		break;

	case 2:
		if(BuscarRepetidas(repetidas, cantidadFiguritas) == 1)
		{
			album = intercambio(album, cantidadFiguritas, figuritas, selecciones, sizeSelecciones, clubes, sizeClubes, managers, sizeManagers, repetidas);
			system("pause");
		}

		break;

	case 3:
		figurita_MostrarRepetida(repetidas, figuritas, sizeFiguritas, clubes, sizeClubes, selecciones, sizeSelecciones, managers, sizeManagers);
		system("pause");
		break;

	case 4:
		figuritas_mostrarPegadas(album, figuritas, cantidadFiguritas, clubes, sizeClubes, selecciones, sizeSelecciones, managers, sizeManagers);
		system("pause");
		break;

	case 5:
		figuritas_MostrarDoradas(album, figuritas, sizeFiguritas, clubes, sizeClubes, selecciones, sizeSelecciones, managers, sizeManagers);
		system("pause");
		break;

	case 6:
			printf("\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -"
					"\nCantidad de sobres comprados hasta el momento: %d"
					"\n - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -",paquetesComprados);
		break;

	case 7:
		mostrarPaquetesLleno(cantTotalPaquetes, album);
		break;

	case 8:
		printf("\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -"
				"\nDinero gastado hasta el momento: %d"
				"\n - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -",dineroGastadoActual);
		break;
	}

	}while(opcion != 9);

}
=======
/*
 * perfil.c
 *
 *  Created on: 2 dic 2022
 *      Author: DIEGO
 */

#include "perfil.h"
#include "herramientas.h"
		/*-------------------------------------------------------- PERFIL ADMINISTRADOR --------------------------------------------------------*/


void perfilAdministrador(sFigurita* figuritas, int size, sSeleccion* selecciones, int sizeSeleccion,sClub* clubes, int sizeClubes,sManager* managers, int sizeManagers)
{
	int opcion;

	do{
		puts("\n-----------------------------------------");
		puts("\tPERFIL ADMINISTRADOR");
		puts("-----------------------------------------");
		obtenerEnteroRemastered(&opcion, "\n1. Alta"
										 "\n2. Modificacion"
										 "\n3. Acceder a listas"
										 "\n4. VOLVER AL INICIO"
										 "\nINGRESE UNA OPCION: ", "ERROR,seleccione las opciones disponibles", 1, 4);

		switch(opcion)
		{

		case 1:

			if(Alta(figuritas, CANT_FIGURITAS ,selecciones,CANT_SELECCIONES,clubes,sizeClubes,managers,sizeManagers) == 1)
			{
				puts("DADO DE ALTA EXITOSAMENTE");
			}
		break;

		case 2:
			if(modificacion(figuritas, size, selecciones, sizeSeleccion,clubes,sizeClubes,managers,sizeManagers))
			{
				puts("\nMODIFICACION EXITOSA\n");
			}else{
				puts("\nMODIFICACION CANCELADA");
			}

		break;

		case 3:

				puts("-------------MENU DE LISTAS---------------");

			do{

			obtenerEnteroRemastered(&opcion,"\n1.Lista de figuritas"
											"\n2.Lista de Clubes"
											"\n3.Lista de Selecciones"
											"\n4.Lista de Managers"
											"\n5.Filtrar"
											"\n6.Salir"
											"\nIngrese una opcion: ", "\nLa opcion ingresada es incorrecta!,vuelva a intentarlo: ", 1, 6);

				switch(opcion)
				{
					case 1:
						if(figurita_MostrarTodas(figuritas, size, clubes, sizeClubes, selecciones, sizeSeleccion, managers, sizeManagers))
						{
							system("pause");
						}else{
							puts("No hay nada para mostrar");
						}
						break;

					case 2:
						if(club_listarClubes(clubes, sizeClubes) == 1)
						{
							system("pause");

						}else{
							puts("No hay clubes para mostrar");
						}
						break;

					case 3:
						if(selecciones_MostrarTodas(selecciones, sizeSeleccion) == 1)
						{
							system("pause");

						}else{
							puts("No hay selecciones para mostrar");
						}
						break;

					case 4:
						if(manager_MostrarTodos(managers, sizeManagers) == 1)
						{
							system("pause");

						}else{
							puts("No hay managers para mostrar");
						}
						break;

					case 5://Filtros

						do{
							obtenerEnteroRemastered(&opcion, "\n1.Filtrar jugadores por Club"
															"\n2.Filtrar jugadores por Selecciones"
															"\n3.Filtrar por Managers"
															"\n4.Salir"
															"\nIngrese una opcion: ", "\nLa opcion ingresada es incorrecta!", 1, 4);

							switch(opcion)
							{
								case 1:
									clubes_filtro(figuritas, size, clubes, sizeClubes, selecciones, sizeSeleccion, managers, sizeManagers);
									system("pause");
									break;

								case 2:
									selecciones_filtro(figuritas, size, clubes, sizeClubes, selecciones, sizeSeleccion, managers, sizeManagers);
									system("pause");

									break;

								case 3:
									managers_filtro(figuritas, size, clubes, sizeClubes, selecciones, sizeSeleccion, managers, sizeManagers);
									break;

								case 4:
									puts("Regresando..");

									break;

							}

						}while(opcion != 4);

						break;

					case 6:
						puts("Regresando..");
						break;
				}

			}while(opcion != 6);

		break;

		case 4:
			puts("Regresando..");
			break;

		}

	}while(opcion != 4);
}


/*-------------------------------------------------------- PERFIL COLECCIONISTA --------------------------------------------------------*/

void perfilColeccionista(sFigurita* figuritas, int sizeFiguritas,sAlbum album, sSeleccion selecciones[],int sizeSelecciones, sClub clubes[], int sizeClubes, sManager managers[], int sizeManagers,int cantidadFiguritas,sFiguritaRepetida repetidas[],int* pContadorFiguritas)
{
	int opcion;
	int paquetesComprados = 0;
	int cantTotalPaquetes;
	int precio_por_unidad = 170;
	int dineroGastadoActual;
	float dineroTotalGatado;

	inicializarRepetidas(repetidas, figuritas, sizeFiguritas);
	album = inicializarAlbum(album, sizeFiguritas);

	do{

		if((VerificarAlbumLleno(album, cantidadFiguritas) == 1) && album.estado == LIBRE)
		{
			dineroTotalGatado = (float)precio_por_unidad * paquetesComprados;
			printf("\nEl album esta completo,buen trabajo!");
			album.estado = OCUPADO;
			printf("\nDinero total gastado: %.2f",dineroTotalGatado);
		}

		puts("\n-----------------------------------------");
		puts("\tPERFIL COLECCIONISTA");
		puts("-----------------------------------------");
		puts("\n1. Comprar paquete de figuritas"
			 "\n2. Intercambiar figuritas"
			 "\n3. Ver figuritas repetidas"
			 "\n4. Ver figuritas pegadas"
			 "\n5. Ver DORADAS"
			 "\n6. Cantidad Sobres Comprados"
			 "\n7. Cantidad de sobres comprados para llenar el album"
			 "\n8. Cantidad de dinero que lleva gastando el coleccionista"
			 "\n9. VOLVER AL INICIO");

	obtenerNumero(&opcion, "\nSeleccione su opcion: ", "ERROR,seleccione las opciones disponibles", 1, 9, 0);

	switch(opcion)
	{

	case 1:
		album = comprarPaquete(album, repetidas, pContadorFiguritas, figuritas, cantidadFiguritas, selecciones,sizeSelecciones,clubes,sizeClubes,managers,sizeManagers);
			cantTotalPaquetes = paquetesComprados++;
			dineroGastadoActual = (float)precio_por_unidad * paquetesComprados;
		break;

	case 2:
		if(BuscarRepetidas(repetidas, cantidadFiguritas) == 1)
		{
			album = intercambio(album, cantidadFiguritas, figuritas, selecciones, sizeSelecciones, clubes, sizeClubes, managers, sizeManagers, repetidas);
			system("pause");
		}

		break;

	case 3:
		figurita_MostrarRepetida(repetidas, figuritas, sizeFiguritas, clubes, sizeClubes, selecciones, sizeSelecciones, managers, sizeManagers);
		system("pause");
		break;

	case 4:
		figuritas_mostrarPegadas(album, figuritas, cantidadFiguritas, clubes, sizeClubes, selecciones, sizeSelecciones, managers, sizeManagers);
		system("pause");
		break;

	case 5:
		figuritas_MostrarDoradas(album, figuritas, sizeFiguritas, clubes, sizeClubes, selecciones, sizeSelecciones, managers, sizeManagers);
		system("pause");
		break;

	case 6:
			printf("\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -"
					"\nCantidad de sobres comprados hasta el momento: %d"
					"\n - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -",paquetesComprados);
		break;

	case 7:
		mostrarPaquetesLleno(cantTotalPaquetes, album);
		break;

	case 8:
		printf("\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -"
				"\nDinero gastado hasta el momento: %d"
				"\n - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -",dineroGastadoActual);
		break;
	}

	}while(opcion != 9);

}
>>>>>>> 8aeee1b24af3eadd99da22d7a0b9a252ee1d16d6
