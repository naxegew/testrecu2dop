/*
 * parser.c
 *
 *  Created on: 11 dic. 2019
 *      Author: igna
 */
#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "entidad.h"

int parser_EntidadFromText(FILE* pFile, LinkedList *pArrayEntidad)
{
	int retorno=-1,r;
	char idStr[128],intStr[128],floatStr[128],StringStr[128],charStr[128],header[500];
	Entidad* entidad;

	fscanf(pFile,"%[^\n]\n", header);
	printf("\n%s",header);

	    while(!feof(pFile))
	    {
	        r = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",idStr,intStr,floatStr,charStr,StringStr);
	        entidad=entidad_newParametros(idStr,StringStr,floatStr,intStr,charStr);
	       printf("\n%s %s %s %s %s",idStr,StringStr,floatStr,intStr,charStr);
	        if(r==5)
	        {
	            if(entidad!=NULL)
	            {
	                ll_add(pArrayEntidad,entidad);
	                retorno=0;
	            }
	        }
	    }


	/*
	do
	{
	r=fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n"); //agergar %[^,] por cada dato que falte
		if(r==5) //5 o el numero de datos a parsear
		{
		printf("%s %s %s %s %s \n",idStr, intStr, floatStr,charStr,StringStr);
			entidad = entidad_newParametros(idStr,StringStr,floatStr,intStr,charStr);
			ll_add(pArrayEntidad,entidad);
			retorno = 1;
		}
	}while(!feof(pFile));
*/
	return retorno;
}
int parser_EntidadFromBinary(FILE* pFile, LinkedList *pArrayListEntidad)
{
	int retorno =-1;
	int len;
	int i;
	//int id,cInt;
	//char cChar, cString[128];
	//float cfloat;
	Entidad* entidad;

	do
	{
	entidad = entidad_new();
	fread(entidad,sizeof(Entidad),1,pFile);
	ll_add(pArrayListEntidad,entidad);

	}while(!feof(pFile));

	len = ll_len(pArrayListEntidad);
	for(i=0;i<len;i++)
	{
		entidad = ll_get(pArrayListEntidad,i);
		printf("\n|%d |%d||%.2f||%c||%s|",entidad->id,entidad->cInt,entidad->cFloat,entidad->cChar,entidad->cString);
	}

	return retorno;
}
int parser_saveAsText(FILE *pFile,LinkedList *pArrayListEntidad)
{

	Entidad* entidad;
	int retorno=-1,i;
	int len = ll_len(pArrayListEntidad);
	fprintf(pFile,"id,int,float,char,string\n");
	for(i=0;i<=len;i++)
	{

		entidad =ll_get(pArrayListEntidad,i);
		fprintf(pFile,"%d,%d,%.2f,%c,%s\n",entidad->id,entidad->cInt,entidad->cFloat,entidad->cChar,entidad->cString);
	}
	return retorno;
}
