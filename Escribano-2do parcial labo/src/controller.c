
/*
 * controller.c
 *
 *
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "controller.h"
#include "libro.h"
#include "menues.h"
#include "parser.h"
#include "utn.h"
int controller_loadFromText(char* path, LinkedList* pArrayListLibro)
{
	int retorno = -1;
	    FILE* pFile;



	    if(path != NULL && pArrayListLibro!=NULL)
	    {
	    	pFile = fopen(path, "r");
	    	if(pFile==NULL)
	    	{
	    	}else{
	    		if(ll_isEmpty(pArrayListLibro)==1)
	    		{
	    			if(parser_LibroFromText(pFile, pArrayListLibro)==0)
	    				    		{
	    				    			printf("carga exitosa\n");
	    				    			retorno = 0;
	    				    		}
	    			else{
	    				printf("no se parseo el csv\n");
	    			}
	    		}


	    	}
	    }
	    fclose(pFile);

	    return retorno;
}
int controller_ListLibro(LinkedList* pArrayListLibro)
{
	int retorno = -1;

	    if(pArrayListLibro != NULL)
	    {
	        printf("   Id  ||   Titulo   ||   Autor   ||  Precio || Editorial\n\n");
	        for(int i=0; i<ll_len(pArrayListLibro); i++)
	        {
	            Libro_PrintLibro(pArrayListLibro, i);
	        }
	        retorno = 0;
	    }
	    else
	    {
	        printf("No hay empleados cargados para mostrar\n");
	    }

	    return retorno;
	}
/*
int controller_loadFromBinary(char* path, LinkedList* pArrayListLibro)
{
    int retorno = -1;
    FILE* pFile;

    pFile = fopen(path, "rb");

    if(pFile != NULL)
    {
        if(parser_LibroFromBinary(pFile, pArrayListLibro) == 0)
        {
            printf("Datos cargados con exito\n");
            retorno = 0;
        }
        else
        {
            printf("No ha sido posible cargar los datos\n\n");
        }
    }
    else
    {
        printf("Error NULL\n");
    }
    fclose(pFile);
    return retorno;
}
int controller_addLibro(LinkedList* pArrayListLibro)
{
    int retorno = -1;
    Libro* pLibro = Libro_new();

    int nextId;
    char auxNombre[TAMN];
    int auxHorasTrabajadas;
    int auxSueldo;

    if(pArrayListLibro != NULL && pLibro != NULL)
    {
        printf("||Alta Empleados||\n\n");

        if(get_Cadena(auxNombre,TAMN, 3, "Ingrese nombre del nuevo empleado: ", "Error, reingrese nombre: \n") == 0 &&
                get_Entero(&auxHorasTrabajadas, 3, "Ingrese horas trabajadas: ", "Error, reingrese horas: \n", 0, 5000) == 0 &&
                get_Entero(&auxSueldo, 3, "Ingrese sueldo: ", "Error, reingrese sueldo: \n", 12000, 300000) == 0)
        {
            normalizeStr(auxNombre);

            nextId = Libro_lastId(pArrayListLibro) + 1;

            if(Libro_setId(pLibro, nextId) == 0 &&
                    Libro_setNombre(pLibro, auxNombre) == 0 &&
                    Libro_setHorasTrabajadas(pLibro, auxHorasTrabajadas) == 0 &&
                    Libro_setSueldo(pLibro, auxSueldo) == 0)
            {
                ll_add(pArrayListLibro, pLibro);
                retorno = 0;
            }
            else
            {
                free(pLibro);
            }
        }
        else
        {
            free(pLibro);
        }
    }

    return retorno;
}

int controller_editLibro(LinkedList* pArrayListLibro)
{
    int retorno = -1;
    Libro* auxLibro;
    int auxId;
    int lastId;
    int index;
    int quitMenu = 1;

    if(pArrayListLibro != NULL)
    {
        controller_ListLibro(pArrayListLibro);

        for(int i = 0; i < ll_len(pArrayListLibro); i++)
        {
            auxLibro = ll_get(pArrayListLibro, i);

            Libro_getId(auxLibro, &auxId);
            if(auxId >= lastId)
            {
                lastId = auxId;
            }
        }
        if(get_Entero(&auxId, 3, "\nIngrese ID del empleado a modificar: ", "Error, reingrese un ID valido: \n", 0, lastId) == 0)
        {
            index = Libro_searchForId(pArrayListLibro, auxId);

            if(index >= 0)
            {
                printf("||Modificar Empleados||\n\n");
                printf("Usted eligio el siguiente empleado para modificar:\n\n");
                printf("   Id  ||   Nombre   ||   Horas trabajadas   ||  Sueldo\n");
                Libro_printLibro(pArrayListLibro, index);

                printf("\nQue desea modificar?\n");

                do
                {
                    switch(menuModifications())
                    {
                    case 1:
                        if(Libro_changeName(pArrayListLibro, index) == 0)
                        {
                            printf("   Id  ||   Nombre   ||   Horas trabajadas   ||  Sueldo\n");
                            Libro_printLibro(pArrayListLibro, index);
                            printf("\nNombre modificado con exito! Se regresara al menu principal\n\n");
                            quitMenu = 0;
                        }
                        else
                        {
                            printf("No se pudo realizar la modificacion del nombre, se regresara al menu principal\n\n");
                            quitMenu = 0;
                        }
                        break;
                    case 2:
                        if(Libro_changeHours(pArrayListLibro, index) == 0)
                        {
                            printf("   Id  ||   Nombre   ||   Horas trabajadas   ||  Sueldo\n");
                            Libro_printLibro(pArrayListLibro, index);
                            printf("\nHoras trabajadas modificadas con exito! Se regresara al menu principal\n\n");
                            quitMenu = 0;
                        }
                        else
                        {
                            printf("No se pudo realizar la modificacion de las horas trabajadas, se regresara al menu principal\n\n");
                            quitMenu = 0;
                        }
                        break;
                    case 3:
                        if(Libro_changeSalary(pArrayListLibro, index) == 0)
                        {
                            printf("   Id  ||   Nombre   ||   Horas trabajadas   ||  Sueldo\n");
                            Libro_printLibro(pArrayListLibro, index);
                            printf("Sueldo modificado con exito. Se regresara al menu principal\n\n");
                            quitMenu = 0;
                        }
                        else
                        {
                            system("cls");
                            printf("No se pudo realizar la modificacion del sueldo, se regresara al menu principal\n\n");
                            quitMenu = 0;
                        }
                        break;
                    case 4:
                        quitMenu = 0;
                        break;
                    default:
                        system("cls");
                        printf("No es una opcion valida\n\n");
                        break;
                    }
                }
                while(quitMenu == 1);

            }

        }

    }

    return retorno;
}

int controller_removeLibro(LinkedList* pArrayListLibro)
{
    int retorno = -1;
    Libro* auxLibro;

    int auxId;
    int lastId;

    int index;
    char confirmDelete;

    if(pArrayListLibro != NULL)
    {
        controller_ListLibro(pArrayListLibro);

        for(int i = 0; i < ll_len(pArrayListLibro); i++)
        {
            auxLibro = ll_get(pArrayListLibro, i);

            Libro_getId(auxLibro, &auxId);
            if(auxId >= lastId)
            {
                lastId = auxId;
            }
        }
        if(get_Entero(&auxId, 3, "\nIngrese ID del empleado a eliminar: ", "Error, reingrese un ID valido: \n", 0, lastId) == 0)
        {
            index = Libro_searchForId(pArrayListLibro, auxId);

            if(index >= 0)
            {
                printf("||Baja Empleados||\n\n");
                printf("Usted eligio el siguiente empleado para dar de baja:\n\n");
                auxLibro = ll_get(pArrayListLibro, index);
                printf("   Id  ||   Nombre   ||   Horas trabajadas   ||  Sueldo\n");
                Libro_printLibro(pArrayListLibro, index);

                printf("\nDesea eliminar al empleado? s/n: ");
                fflush(stdin);
                scanf("%c", &confirmDelete);

                if(confirmDelete == 's')
                {
                    ll_remove(pArrayListLibro, index);
                    if(Libro_delete(auxLibro) == 0)
                    {
                        printf("Baja realizada con exito!\n\n");
                        retorno = 0;
                    }
                }
                else
                {
                    printf("No se ha realizado la baja\n");
                }
            }
        }
    }
    return retorno;
}
*/


int controller_sortLibro(LinkedList* pArrayListLibro)
{
    int retorno = -1;

    if(pArrayListLibro != NULL)
    {
        if(Libro_sort(pArrayListLibro) == 0)
        {
            printf("\nEmpleados ordenados exitosamente.\n\n");
        }
    }
    else
    {
        printf("Error\n");
    }

    return retorno;
}


int controller_saveAsText(char* path, LinkedList* pArrayListLibro)
{
    int retorno = -1;

    FILE* pFile;
    Libro* pLibro;

    int auxId;
    char auxTitulo[128];
    char auxAutor[128];
    float auxPrecio;
    char auxEditorial[128];
    int auxIdEditorial;

    if(pArrayListLibro != NULL && path != NULL)
    {
        pFile = fopen(path, "w");
        if(pFile != NULL)
        {

            for(int i = 0; i < ll_len(pArrayListLibro); i++)
            {
                pLibro = ll_get(pArrayListLibro, i);
                if(Libro_getId(pLibro, &auxId)==0 &&
                        Libro_getTitulo(pLibro, auxTitulo)==0 &&
                        Libro_getAutor(pLibro, auxAutor)==0 &&
                        Libro_getPrecio(pLibro, &auxPrecio)==0&&
						Libro_getEditorial(pLibro, &auxIdEditorial)==0&&
						Libro_IdAEditorial(auxIdEditorial,auxEditorial)==0)
                {
                    fprintf(pFile, "%d,%s,%s,%.2f,%s\n", auxId, auxTitulo, auxAutor, auxPrecio, auxEditorial);
                }
            }
            fclose(pFile);
            printf("Datos guardados como texto de forma exitosa\n\n");
            retorno = 0;
        }else{
        	printf("No se pudo escribir el archivo\n");
        }
    }

    return retorno;
}

int controller_saveAsBinary(char* path, LinkedList* pArrayListLibro)
{
    int retorno = -1;
	FILE* pFile;
	Libro* pLibro;

	if(pArrayListLibro != NULL && path != NULL)
	{
		pFile = fopen(path, "wb");

		for(int i = 1; i < ll_len(pArrayListLibro); i++)
		{
			pLibro = (Libro*) ll_get(pArrayListLibro, i);
			fwrite(pLibro, sizeof(Libro), 1, pFile);
		}
		fclose(pFile);
		system("cls");
		printf("Datos guardados como binario de forma exitosa!\n");
		retorno = 0;
	}

    return retorno;
}
int controller_mapLibro(LinkedList* pArrayListLibro)
{
	int ret=-1;
	void (*pFunc)(void* element);
	if(pArrayListLibro!=NULL)
	{
		pFunc=Libro_item4;
		ll_map(pArrayListLibro,pFunc);
	}
	return ret;
}
int controller_ElegirPath(char* path,int formatoArchivo)
{
	int ret = -1;
	int destino;
	fflush(stdin);
	if(get_Entero(&destino,1, "Elija el archivo destino donde guardara el listado de libros:\n"
					"1)Datos.csv\n"
					,
					"Error,ingrese sólo las siguientes opciones:\n"
							"1)Datos.csv\n"
							, 1, 1) == 0)
	{
		switch (destino)
		{
		case 1:
			printf("Usted a elegido cargar el archivo en el Datos.csv\n");
			strcpy(path,"Datos.csv");
			ret = 0;
			break;
		case 2:
			printf("Usted ha elegido cargar el archivo en el test1.csv\n");
			strcpy(path,"test1.csv");
			ret = 0;
			break;
		case 3:
			if(get_FileName(path,formatoArchivo,20) == 0)
			{
				ret = 0;
			}
			break;
		default:
			break;
		}

	}
	return ret;
}
