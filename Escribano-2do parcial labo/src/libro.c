#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "utn.h"
#include "controller.h"
#include "libro.h"
#include "menues.h"

#define TAMN 128

Libro* Libro_new()
{
	Libro* aux=NULL;
	aux= (Libro*) malloc(sizeof(Libro));
    return aux;
}

Libro* Libro_newParametros(char* idStr,char* titulo,char* autor, char* precioStr, char* editorialStr)
{
    Libro* newLibro= Libro_new();

    int auxId;
    if(newLibro != NULL && idStr != NULL && titulo != NULL && autor != NULL && precioStr != NULL)
    {

        if(Libro_setId(newLibro,atoi(idStr))==-1||
               Libro_setTitulo(newLibro, titulo)==-1 ||
               Libro_setAutor(newLibro, autor)==-1 ||
               Libro_setPrecio(newLibro, atof(precioStr))==-1||
				Libro_EditorialAId(&auxId,editorialStr)==-1||
				Libro_setEditorial(newLibro,auxId)==-1)
        	{
        	Libro_delete(newLibro);
        	newLibro = NULL;
        	}

    }

    return newLibro;
}

void Libro_delete(Libro* this)
{
        free(this);
}


int Libro_setId(Libro* this,int id)
{
    int retorno = -1;

    if(this != NULL && id >= 0)
    {
        this->id = id;
        retorno = 0;
    }

    return retorno;
}
int Libro_getId(Libro* this,int* id)
{
    int retorno = -1;

    if(this != NULL && id != NULL)
    {
        *id = this->id;
        retorno = 0;
    }

    return retorno;
}


int Libro_setTitulo(Libro* this,char* titulo)
{
    int retorno = -1;

    if(this != NULL && titulo!=NULL)
    {

            strcpy(this->titulo, titulo);
            retorno = 0;

    }

    return retorno;
}
int Libro_getTitulo(Libro* this,char* titulo)
{
    int retorno = -1;

    if(this != NULL && titulo!=NULL)
    {
        strcpy(titulo, this->titulo);
        retorno = 0;
    }

    return retorno;
}
int Libro_setAutor(Libro* this,char* autor)
{
    int retorno = -1;

    if(this != NULL && autor != NULL)
        {

                strcpy(this->autor, autor);
                retorno = 0;

        }

    return retorno;
}
int Libro_getAutor(Libro* this,char* autor)
{
    int retorno = -1;

    if(this != NULL && autor != NULL)
    {
        strcpy(autor, this->autor);
        retorno = 0;
    }

    return retorno;
}

int Libro_setPrecio(Libro* this,float price)
{
    int retorno = -1;

    if(this != NULL && price >= 0)
    {
        this->precio = price;
        retorno = 0;
    }

    return retorno;
}
int Libro_getPrecio(Libro* this,float* price)
{
    int retorno = -1;

    if(this != NULL && price != NULL)
    {
        *price = this->precio;
        retorno = 0;
    }

    return retorno;
}


int Libro_setEditorial(Libro* this,int editorial)
{
    int retorno = -1;
    if(this != NULL&& editorial>=1 && editorial<=6)
       {
           this->editorialId = editorial;
           retorno = 0;
       }

    return retorno;
}
int Libro_getEditorial(Libro* this,int* editorial)
{
	int retorno = -1;
	if(this != NULL && editorial != NULL)
	    {
	        *editorial = this->editorialId;
	        retorno = 0;
	    }
	    return retorno;
}

int Libro_searchForId(LinkedList* pArrayListLibro, int id)
{
    int retorno = -1;
    int idAux;
    Libro* pLibro;

    for(int index = 0; index < ll_len(pArrayListLibro); index++)
    {
        pLibro = ll_get(pArrayListLibro, index);

        if(Libro_getId(pLibro, &idAux) == 0 &&
                idAux == id)
        {
            retorno = index;
            break;
        }
    }
    return retorno;
}

int Libro_lastId(LinkedList* pArrayListLibro)
{
    Libro* pLibro;
    int len = ll_len(pArrayListLibro);
    int auxId;
    int lastId = 0;
    int flag = 0;

    if(pArrayListLibro != NULL)
    {
        for(int i = 0; i < len; i++)
        {
            pLibro = (Libro*) ll_get(pArrayListLibro,i);
            Libro_getId(pLibro, &auxId);

            if(auxId > lastId || flag == 0)
            {
                lastId = auxId;
                flag = 1;
            }
        }
    }
    return lastId;
}
int Libro_sort(LinkedList* pArrayListLibro)
{
	 int retorno = -1;
	    int orden=1;

	    if(pArrayListLibro != NULL)
	    {
	        system("cls");
	        printf("||Menu ordenar||\n");
	        switch(menuSort())
	        {
	        case 1:
	        	ll_sort(pArrayListLibro, Libro_sortByAutor, orden);

	        	            retorno = 0;

	            break;
	        case 2:
	          //  get_Entero(&orden, 2, "\nIngrese orden, 1 ascendente, 0 descendente: ", "\nError, ingrese un orden valido", 0, 1);
	            //printf("\nOrdenando...\n\n\n");
	           // ll_sort(pArrayListEmployee, employee_sortByName, orden);
	           // controller_ListEmployee(pArrayListEmployee);
	          //  retorno = 0;
	            break;

	        default:
	            printf("\nNo es una opcion valida\n\n");
	            break;
	        }

	    }

	    return retorno;
	}



/*
int Libro_sortById(void* firstLibro, void* secondLibro)
{
    int retorno = 0;

    int firstId;
    int secondId;

    Libro_getId(firstLibro, &firstId);
    Libro_getId(secondLibro, &secondId);

    if(firstId > secondId)
    {
        retorno = 1;
    }
    else if(secondId > firstId)
    {
        retorno = -1;
    }

    return retorno;
}*/

int Libro_sortByAutor(void* firstAutor, void* secondAutor)
{
    int retorno = 0;

    char firstName[TAMN];
    char secondName[TAMN];

    Libro_getAutor(firstAutor, firstName);
    Libro_getAutor(secondAutor, secondName);

    if(strcmp(firstName, secondName) > 0)
    {
        retorno = 1;
    }
    else if(strcmp(secondName, firstName) < 0)
    {
        retorno = -1;
    }

    return retorno;
}

int Libro_EditorialAId(int* idEditorial, char* editorialStr)
{
	int retorno=-1;
	if(editorialStr !=NULL && idEditorial!=NULL)
	{
		retorno=0;
		if(stricmp(editorialStr,"PLANETA")==0)
		{
			*idEditorial=1;
		}
		if(stricmp(editorialStr,"SIGLO XXI EDITORES")==0)
		{
			*idEditorial=2;
		}
		if(stricmp(editorialStr,"PEARSON")==0)
		{
			*idEditorial=3;
		}
		if(stricmp(editorialStr,"MINOTAURO")==0)
		{
			*idEditorial=4;
		}
		if(stricmp(editorialStr,"SALAMANDRA")==0)
		{
			*idEditorial=5;
		}
		if(stricmp(editorialStr,"PENGUIN BOOKS")==0)
		{
			*idEditorial=6;
		}
	}
	return retorno;
}

int Libro_IdAEditorial(int idEditorial, char* editorialStr)
{
	int retorno=-1;
	if(editorialStr!=NULL && idEditorial>0 && idEditorial<7)
	{
		retorno=0;
		switch(idEditorial)
		{
		case 1:
			strcpy(editorialStr,"PLANETA");
			break;
		case 2:
			strcpy(editorialStr,"SIGLO XXI EDITORES");
			break;
		case 3:
			strcpy(editorialStr,"PEARSON");
			break;
		case 4:
			strcpy(editorialStr,"MINOTAURO");
			break;
		case 5:
			strcpy(editorialStr,"SALAMANDRA");
			break;
		case 6:
			strcpy(editorialStr,"PENGUIN BOOKS");
			break;
		}
	}
	return retorno;
}
void Libro_item4(void* this)
{
	int auxId;
	float auxPrecio;
	if(Libro_getEditorial((Libro*)this,&auxId)== 0 && Libro_getPrecio((Libro*)this,&auxPrecio)==0)
	{
		switch(auxId)
		{
		case 1:
			if(auxPrecio>=300)
			{
				auxPrecio=auxPrecio*0.80;
				Libro_setPrecio(this,auxPrecio);
			}
			break;
		case 2:
			if(auxPrecio<=200)
			{
				auxPrecio=auxPrecio*0.90;
				Libro_setPrecio(this,auxPrecio);

			}
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			break;
		}
	}

}
int Libro_PrintLibro(LinkedList* pArrayListLibro, int index)
{
	int ret =-1;
	int auxId;
	char auxTitulo[128];
	char auxAutor[128];
	float auxPrecio;
	int auxEditorialId;
	char descripcionEditorial[30];
	Libro* auxLib;
	if(pArrayListLibro != NULL && index>=0)
	{
		auxLib=ll_get(pArrayListLibro,index);
		if(Libro_getId(auxLib,&auxId)==0&&
		Libro_getTitulo(auxLib, auxTitulo)==0&&
		Libro_getAutor(auxLib, auxAutor)==0&&
		Libro_getPrecio(auxLib, &auxPrecio)==0&&
		Libro_getEditorial(auxLib, &auxEditorialId)==0&&
		Libro_IdAEditorial(auxEditorialId,descripcionEditorial) == 0)
		{
			printf("\n %d  %50s %15s  %.2f  %s",
					auxId,
					auxTitulo,
					auxAutor,
					auxPrecio,
					descripcionEditorial);
			ret = 0;
		}
		else
		{
			printf("error en el print libro\n");
		}
	}
	return ret;
}//FIN pelicula_PrintElement()
