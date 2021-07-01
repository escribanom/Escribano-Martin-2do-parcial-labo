#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "libro.h"
#include "menues.h"


int main()
{
	setbuf(stdout,NULL);
	char seguir = 's';
    char salir;
    int flagTxt = 1;
    int flagSave = 0;
    int flagMap=1;
    char* path = NULL;
    path =(char*)calloc(20,sizeof(char));
    LinkedList* listaLibros = ll_newLinkedList();

    if(listaLibros == NULL)
    {
        printf("No se pudo conseguir espacio en memoria\n\n");
        exit(EXIT_FAILURE);
    }


    do
    {
        switch(menuOpciones())
        {
        case 1://leer
            if(flagTxt == 1)
            {
            	if(controller_ElegirPath(path,2) == 0)
            	{
                if(controller_loadFromText(path,listaLibros) == 0)
                {

                	flagTxt = 0;
                }
            	}
            }
            else
            {
                printf("El archivo ya fue cargado.\n");
            }
            break;

        case 2:
        	//sort x autor
        	if(flagTxt == 0 )
        	            {
        				controller_sortLibro(listaLibros);
        	            }
        	            else
        	            {
        	                printf("No hay empleados que listar\n\n");
        	            }
        	            break;
        case 3://listar
            if(flagTxt == 0 )
            {
            	controller_ListLibro(listaLibros);
            }
            else
            {
            	printf("No hay empleados que listar\n\n");
            }
            break;

        case 4://hacer descuentos con map
        	if(flagTxt==0)
        	{
        		controller_mapLibro(listaLibros);
        		controller_ListLibro(listaLibros);
        		flagMap=0;
        	}
        	else
        	{
        		printf("No hay empleados que listar\n\n");
        	}

            break;

        case 5://guardar nuevo archivo
            if(flagTxt == 0 && flagMap==0)
            {
                controller_saveAsText("mapeado.csv", listaLibros);
                flagSave = 0;
            }
            else
            {
                printf("No hay archivos cargados para guardar\n\n");
            }
            break;


        case 6:
            if(flagSave > 0)
            {
                do
                {
                    fflush(stdin);
                    printf("\nDesea salir del programa sin guardar los cambios? s/n: ");
                    scanf("%c", &salir);
                }
                while(salir != 's' && salir != 'n');
            }
            else if(flagSave == 0)
            {
                do
                {
                    fflush(stdin);
                    printf("\nDesea salir del programa? s/n: ");
                    scanf("%c", &salir);
                }
                while(salir != 's' && salir != 'n');
            }
            if(salir == 's')
            {
                ll_deleteLinkedList(listaLibros);
                seguir = 'n';
            }
            break;

        default:
            printf("No es una opcion valida\n\n");
            fflush(stdin);
            break;
        }
        fflush(stdin);

    }
    while(seguir == 's');

    return 0;

}
