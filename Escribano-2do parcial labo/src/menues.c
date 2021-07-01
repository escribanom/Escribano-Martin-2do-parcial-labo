/*
 * menues.c
 *
 *
 *
 */
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "menues.h"
#include "utn.h"

int menuOpciones()
{
    int opcion;

    printf("||Menu de opciones Empleados||\n\n");

    printf("1. Leer archivo\n");
    printf("2. Ordenar segun autor del libro.\n");
    printf("3. Listado de libros\n");
    printf("4. Realizar descuentos\n");
    printf("5. Guardar archivo con descuento\n");
    printf("6. Salir\n");

    printf("Indique opcion: ");
    scanf("%d", &opcion);

    return opcion;
}

int menuModifications()
{
    int opcion;

    printf("\n1. Modificar nombre\n");
    printf("2. Modificar horas trabajadas\n");
    printf("3. Modificar sueldo\n");
    printf("4. Volver al menu principal\n\n");

    get_Entero(&opcion, 3, "Ingrese opcion: ", "Error, no es una opcion valida\n", 1, 4);

    return opcion;
}
int menuSort()
{
    int opcion;

    printf("\n1. Ordenar por Autor\n");
    printf("2. (Coming Soon)\n");
    printf("3. Volver al menu principal\n\n");

    get_Entero(&opcion, 3, "Ingrese opcion: ", "Error, no es una opcion valida\n", 1, 3);

    return opcion;
}

