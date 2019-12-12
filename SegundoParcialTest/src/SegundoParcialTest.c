/*
 ============================================================================
 Name        : SegundoParcialTest.c
 Author      : Ignacio Martin Canay
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>
#include "utn_lib.h"
#include "LinkedList.h"
#include "entidad.h"
#include "parser.h"
#include "Controller.h"

int main(void) {
int option;

LinkedList* listaEntidad = ll_newLinkedList();
LinkedList* ListaEntidadFiltrada = ll_newLinkedList();
do
{
mainMenu(&option);

	switch(option)
	{
	case 1:
		controller_loadFromText("test.csv", listaEntidad);
		break;
	case 2:
		controller_loadFromBinary("cachorros.bin", listaEntidad);
		break;
	case 3:
		controller_addEntidad(listaEntidad);
		break;
	case 4:
		controller_saveAsText("test.txt" ,listaEntidad);
		break;
	case 5:
		controller_ListEntidad(listaEntidad);
		break;
	case 6:
		ListaEntidadFiltrada = ll_filter(listaEntidad,fnCriterio_Filtrar);
		controller_saveAsText("Entidad filtrada.txt",ListaEntidadFiltrada);

		break;
	case 7:
		controller_sortEntidad(listaEntidad);
		break;
	case 8:

		break;

	}
}while(option!=8);


	return EXIT_SUCCESS;
}
