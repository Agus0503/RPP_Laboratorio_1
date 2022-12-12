/*
 ============================================================================
 Name        : RPP.c
 Author      : Diego Agustin Ostua Larramendia
 Div	     : 1C
 Description : Album Figuritas in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "perfil.h"
#include "figuritas.h"
#include "album.h"
#include "Selecciones.h"
#include "Club.h"
#include "Manager.h"

int main(void) {

	setbuf(stdout,NULL);

	int opcion;
	sFiguritaRepetida repetidas[SIZE_REPETIDAS];

	sFigurita figuritas[CANT_FIGURITAS] = {			    //S  //C  //M
				{1, "Messi", "Delantero",			    100, 1002, 200, 1.69, 70, 2005, {24, 6, 1987}, OCUPADO},
				{2, "Sergio Busquets", "Mediocampista", 101, 1007, 201, 1.78, 73, 2007, {20, 12, 1998}, OCUPADO},
				{3, "De Jong", "Mediocampista", 		102, 1008, 202, 1.55, 76, 2020, {18, 5, 1993}, OCUPADO},
				{4, "Di Maria", "Delantero", 			100, 1010, 203, 1.55, 76, 2002, {12, 2, 1988}, OCUPADO},
				{5, "De Paul", "Delantero", 			100, 1006, 204, 1.80, 70, 2002, {24, 5, 1994}, OCUPADO},
				{6, "Luis Suarez", "Delantero", 		103, 1006, 202, 1.71, 68, 2015, {10, 2, 1991}, OCUPADO},
				{7, "Giovanni", "Mediocampista", 		100, 1001, 200, 1.75, 72, 2004, {5, 8, 1990},  OCUPADO},
				{8, "German", "Defensor", 				100, 1001, 200, 1.64, 77, 2008, {30, 4, 1986}, OCUPADO},
				{9, "Neymar", "Delantero", 				104, 1002, 202, 1.60, 62, 2000, {28, 2, 1992}, OCUPADO},
				{10, "Diego Godin", "Defensor", 		103, 1006, 203, 1.89, 71, 2004, {19, 8, 1985}, OCUPADO},
				{11, "Alisson Becker","Arquero",		104, 1008, 204, 1.66, 62, 2016, {2,10,1990},   OCUPADO},
				{12, "Nicolas Otamendi","Defensor",		100, 1000, 200, 1.67, 66, 2011, {12,6,1986},   OCUPADO},
				{13, "Lucas Paqueta","Mediocampista",	104, 1000, 201, 1.64, 64, 2018, {27,9,1990},   OCUPADO},
				{14, "Julian Alvarez","Delantero",		100, 1004, 201, 1.64, 62, 2021, {10,10,1990},  OCUPADO},
				{15, "Dani Alves","Defensor",			104, 1008, 203, 1.63, 64, 2013, {15,5,1986},   OCUPADO},
				{16, "Leandro Paredes","Mediocampista", 100, 1002, 204, 1.66, 65, 2019, {10,8,1990},  OCUPADO},
				{17, "Philipe Coutinho","Delantero",	104, 1000, 202, 1.63, 61, 2018, {6,3,1989},   OCUPADO},
				{18, "Thiago Silva","Defensor",			104, 1002, 201, 1.64, 66, 2012, {8,11,1988},  OCUPADO},
				{19, "Alejandro Gomez","Mediocampista", 100, 1009, 203, 1.60, 62, 2015, {12,8,1985},  OCUPADO},
				{20, "Raphinha","Mediocampista",	    104, 1006, 204, 1.62, 60, 2017, {9,4,1993},  OCUPADO},
				{21, "Gavi","Mediocampista",			101, 1000, 203, 1.63, 61, 2017, {9,4,1992},  OCUPADO},
				{22, "Memphis Depay","Delantero",		102, 1009, 203, 1.69, 66, 2013, {10,7,1991}, OCUPADO},
				{23, "Vinicius Junior","Delantero",		104, 1008, 201, 1.63, 61, 2019, {19,7,1995}, OCUPADO},
				{24, "Jordi Alba","Defensor",			101, 1007, 204, 1.65, 62, 2011, {29,7,1989}, OCUPADO},
				{25, "Daley Blind","Defensor",			102, 1000, 204, 1.67, 65, 2019, {12,6,1990}, OCUPADO},
				{26, "Marcos Llorente","Mediocampista", 101, 1004, 201, 1.67, 65, 2016, {22,3,1990}, OCUPADO},
				{27, "Federico Valverde","Mediocampista",103,1005, 202, 1.65, 63, 2014, {17,7,1990}, OCUPADO},
				{28, "Marco Asensio","Delantero",		101, 1007, 200, 1.67, 65, 2015, {10,8,1989}, OCUPADO},
				{29, "Sebastian Sosa","Arquero",		103, 1000, 204, 1.65, 64, 2021, {9,8,1991},  OCUPADO},
				{30, "Jurrien Timber","Defensor",		102, 1001, 202, 1.68, 64, 2018, {14,11,1993},OCUPADO},
				{31, "Robben","Delantero",				102, 1008, 204, 1.64, 65, 2016, {24,11,1986},OCUPADO},
				{32, "Dani Carvajal","Defensor",		101, 1003, 203, 1.66, 64, 2012, {1,9,1987},  OCUPADO},
				{33, "Angel Correa","Delantero",		100, 1006, 200, 1.64, 61, 2015, {11,5,1990}, OCUPADO},
				{34, "Luuk De Jong","Delantero",		102, 1001, 203, 1.68, 65, 2018, {11,2,1989}, OCUPADO},
				{35, "Antony","Delantero",				104, 1009, 204, 1.65, 62, 2018, {24,10,1990},OCUPADO},
				{36, "Emiliano Martinez","Arquero",		100, 1008, 201, 1.67, 65, 2019, {21,7,1988}, OCUPADO},
				{37, "Martin Caceres","Defensor",		103, 1010, 201, 1.64, 65, 2013, {21,11,1988},OCUPADO},
				{38, "Nahuel Molina","Defensor",		100, 1005, 202, 1.66, 63, 2021, {21,9,1993}, OCUPADO},
				{39, "Pablo Sarabia","Mediocampista",	101, 1005, 203, 1.64, 62, 2019, {11,4,1990}, OCUPADO},
				{40, "Mac Allister","Mediocampista",	100, 1003, 200, 1.64, 61, 2021, {31,10,1992},OCUPADO},
				{41, "Pedri","Mediocampista",			101, 1010, 202, 1.64, 61, 2015, {11,7,1989}, OCUPADO},
				{42, "Da silva","Defensor",				104, 1000, 202, 1.64, 61, 2015, {21,1,1988}, OCUPADO},
				{43, "Paulo Dybala","Delantero",		100, 1010, 201, 1.64, 61, 2015, {11,7,1989}, OCUPADO},
				{44, "Bentancur","Mediocampista",		103, 1005, 200, 1.64, 63, 2013, {11,2,1990}, OCUPADO},
				{45, "Gonzalo Montiel","Defensor",		100, 1001, 203, 1.64, 62, 2020, {31,5,1990}, OCUPADO},
				{46, "Alvaro Morata","Mediocampista",	101, 1009, 202, 1.67, 65, 2013, {19,3,1989}, OCUPADO},
				{47, "Gabriel Jesus","Delantero",		104, 1004, 203, 1.64, 61, 2016, {1,10,1990}, OCUPADO},
				{48, "Facundo Torres","Mediocampista",	103, 1009, 202, 1.62, 60, 2019, {20,7,1991}, OCUPADO},
				{49, "Noa Lang","Delantero",			102, 1008, 204, 1.68, 67, 2018, {23,4,1992}, OCUPADO},
				{50, "Eder Militao","Defensor",			104, 1000, 201, 1.65, 64, 2017, {4,5,1985}, OCUPADO},
				{51, "Enzo Fernandez","Mediocampista",	100, 1001, 200, 1.65, 63, 2021, {17,7,1993}, OCUPADO},
				{52, "Alex Sandro","Defensor",			104, 1010, 203, 1.66, 64, 2015, {17,8,1988}, OCUPADO},
				{53, "Ederson","Arquero",				104, 1004, 204, 1.65, 63, 2018, {15,3,1989}, OCUPADO},
				{54, "Exequiel Palacios","Mediocampista",100, 1008, 203, 1.64, 62, 2019, {22,6,1992}, OCUPADO},
				{55, "De la Cruz","Mediocampista",		103, 1001, 202, 1.63, 60, 2017, {8,7,1992}, OCUPADO},
				};

	sSeleccion selecciones[CANT_SELECCIONES] = {
											{100, "Argentina", "Lionel Scaloni", OCUPADO},
											{101, "España", "Luis Enrique", OCUPADO},
											{102, "Paises Bajos", "Louis Van Gaal", OCUPADO},
											{103,"Uruguay","Diego Alonso",OCUPADO},
											{104, "Brasil", "Tite", OCUPADO},
											};

	sAlbum album;
	album.estado = LIBRE;

	sClub clubes[SIZE_CLUBES] = {{1000,"Lanus",			"Frank Kudelka",			1915,OCUPADO},
								{1001,"River Plate",	"Marcelo Gallardo",			1903,OCUPADO},
								{1002 ,"Paris Sanit Germain","Mauricio Pochettino ",1900,OCUPADO},
								{1003 ,"Argentinos Juniors" , "Gabriel Milito" ,    1908,OCUPADO},
								{1004 ,"Manchester City" ,	 "Pep Guardiola" , 		1907,OCUPADO},
								{1005 ,"Leeds" ,			"Marcelo Bielsa" ,		1916,OCUPADO},
								{1006 ,"Atletico Madrid",	"Diego Simeone" ,		1948,OCUPADO},
								{1007 ,"Barcelona",			"Xavi Hernandez" ,		1913,OCUPADO},
								{1008 ,"Bayer Munich",		"Jose Mourinho",		1893,OCUPADO},
								{1009 ,"Newell's",			"Gabiel Heinze",		1918,OCUPADO},
								{1010 ,"Juventus","Massimiliano Allegri",			1920,OCUPADO},
								};

	sManager managers[SIZE_MANAGERS] = {{200,"Guillermo Coppola","descripcion",OCUPADO},
										{201,"Diego Latorre","descripcion",OCUPADO},
										{202,"Alfredo Di Stefano","descripcion",OCUPADO},
										{203,"Manuel Pellegrini","descripcion",OCUPADO},
										{204,"Miguel Muñoz","descripcion",OCUPADO}
										};

	int contadorFiguritas = 0;
	//inicializarFiguritas(figuritas, CANT_FIGURITAS);

	puts("---------------------------------");
	puts("  BIENVENIDO A PANGIANINI  ");
	puts("--------------------------------");

	do{

		puts("\n-----------------------------"
			"\n\tMENU PRINCIPAL\n"
			 "-----------------------------");
		obtenerEnteroRemastered(&opcion, "\n1.Ingresar a Perfil Administrador "
										"\n2.Ingresar a Perfil Coleccionista"
										"\n3.EXIT"
										"\nSeleccione su opcion: ", "ERROR,seleccione las opciones disponibles: ", 1, 3);

		switch(opcion)
		{

		case 1:
			perfilAdministrador(figuritas, CANT_FIGURITAS, selecciones, CANT_SELECCIONES, clubes, SIZE_CLUBES, managers, SIZE_MANAGERS);
			break;

		case 2:
			perfilColeccionista(figuritas, CANT_FIGURITAS, album, selecciones, CANT_SELECCIONES, clubes, SIZE_CLUBES, managers, SIZE_MANAGERS,CANT_FIGURITAS, repetidas,&contadorFiguritas);
		break;

		case 3:
			puts("\n---------------------------------");
			puts("\nGracias por utilizar pangiannini");
			puts("\n---------------------------------");
		break;

		}


	}while(opcion != 3);

	return EXIT_SUCCESS;
}

