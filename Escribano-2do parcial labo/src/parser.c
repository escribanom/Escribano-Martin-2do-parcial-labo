/*
 * parser.c
 *
 *
 *
 */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "parser.h"
#include "libro.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListLibro LinkedList*
 * \return int
 *
 */
int parser_LibroFromText(FILE* pFile, LinkedList* pArrayListLibro)
{
	int retorno = -1; //retorno error

	    Libro* pLibro;

	    int cant = 4; //guarda la cantidad que devuelve fscanf
	    char id[128];
	    char titulo[128];
	    char autor[128];
	    char precio[128];
	    char editorial[128];

	    if(pFile != NULL && pArrayListLibro != NULL)
	    {
	        cant = fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n", id, titulo, autor, precio,editorial);

	        do
	        {
	            if(fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n", id, titulo, autor, precio,editorial) == cant)
	            {
	            	pLibro = Libro_newParametros(id, titulo, autor, precio,editorial);

	                if(pLibro != NULL)
	                {
	                    ll_add(pArrayListLibro, pLibro);
	                    retorno = 0;
	                }
	            }
	            else
	            {
	            	printf("error fscanf=cant\n");
	                break;
	            }

	        }
	        while(feof(pFile) == 0);

	    }

	    return retorno;
}

int parser_LibroFromBinary(FILE* pFile, LinkedList* pArrayListLibro)
{
    int retorno = -1;
    Libro* pLibro;

    if(pFile != NULL)
    {
        do
        {
            pLibro = Libro_new();
            if(fread(pLibro, sizeof(Libro), 1, pFile) == 1)
            {
                ll_add(pArrayListLibro, pLibro);
                retorno = 0;
            }
        }
        while(!feof(pFile));
    }

    return retorno;
}
