#ifndef LIBRO_H_
#define LIBRO_H_

#include "LinkedList.h"

typedef struct
{
    int id;
    char titulo[128];
    char autor[128];
    int precio;
    int editorialId;
}Libro;

/**
 * \brief Pide memoria con malloc
 * \param
 * \return Retorna un puntero a empleado
 */
Libro* Libro_new();

/**
 * \brief Llama a los setters que cargan los campos del libro
 * \param idStr id del empleado como string, nombreStr nombre del empleado como string, horasTrabajadasStr cantidad de hs trabajadas como string, sueldoStr sueldo del empleado como string
 * \return Retorna un puntero a empleado
 */
Libro* Libro_newParametros(char* idStr,char* titulo,char* autor, char* precioStr, char* editorialInt);
int Libro_PrintLibro(LinkedList* pArrayListLibro, int index);
/**
 * \brief Elimina un libro
 * \param this: puntero a libro
 */
void Libro_delete(Libro* this);
/**
 * \brief Valida y carga el titulo en el campo del libro
 * \param this: puntero a libro, titulo: titulo a validar y cargar
 * \return -1 en caso de error, o 0 en caso de exito
 */
int Libro_setTitulo(Libro* this,char* titulo);

/**
 * \brief Carga el nombre del libro en el puntero que pasemos por parametros
 * \param this: puntero a libro, titulo: cadena de caracteres en la que la funcion cargara el titulo
 * \return -1 en caso de error, o 0 en caso de exito
 */
int Libro_getTitulo(Libro* this,char* titulo);
/**
 * \brief Valida y carga el autor en el campo del libro
 * \param this: puntero a libro, autor: autor a validar y cargar
 * \return -1 en caso de error, o 0 en caso de exito
 */
int Libro_setAutor(Libro* this,char* autor);

/**
 * \brief Carga el autor del libro en el puntero que pasemos por parametros
 * \param this: puntero a libro, autor: cadena de caracteres en la que la funcion cargara el autor
 * \return -1 en caso de error, o 0 en caso de exito
 */
int Libro_getAutor(Libro* this,char* autor);

/**
 * \brief Valida y carga el precio del libro
 * \param this: puntero a libro, price: precio a validar y cargar
 * \return -1 en caso de error, o 0 en caso de exito
 */
int Libro_setPrecio(Libro* this,float price);

/**
 * \brief Carga el precio del libro en el puntero que pasemos por parametros
 * \param this: puntero a libro, price: puntero a la variable en la que la funcion cargara el precio
 * \return -1 en caso de error, o 0 en caso de exito
 */
int Libro_getPrecio(Libro* this,float* price);


/**
 * \brief Valida y carga el sueldo en el campo del empleado
 * \param this: puntero a empleado, sueldo: sueldo a validar y cargar
 * \return -1 en caso de error, o 0 en caso de exito
 */
int Libro_setEditorial(Libro* this,int editorial);

/**
 * \brief Carga el sueldo del empleado en el puntero que pasemos por parametros
 * \param this: puntero a empleado, sueldo: puntero a la variable en la que la funcion cargara el sueldo
 * \return -1 en caso de error, o 0 en caso de exito
 */
int Libro_getEditorial(Libro* this,int* editorial);
/**
 * \brief Carga el sueldo del empleado en el puntero que pasemos por parametros
 * \param this: puntero a empleado, sueldo: puntero a la variable en la que la funcion cargara el sueldo
 * \return -1 en caso de error, o 0 en caso de exito
 */
int Libro_IdAEditorial(int idEditorial, char* editorialStr);
/**
 * \brief Carga el sueldo del empleado en el puntero que pasemos por parametros
 * \param this: puntero a empleado, sueldo: puntero a la variable en la que la funcion cargara el sueldo
 * \return -1 en caso de error, o 0 en caso de exito
 */
int Libro_EditorialAId(int* idEditorial, char* editorialStr);
// FIN setters y getters ------------------------------------------------------------------------------------

/**
 * \brief Busca un empleado por id
 * \param pArrayListLibro: LinkedList, id: id a buscar en la lista
 * \return -1 en caso de error, o el index del empleado en caso de exito
 */
int Libro_searchForId(LinkedList* pArrayListLibro, int id);


/**
 * \brief Devuelve el id mas alto de la lista
 * \param pArrayListLibro: LinkedList
 * \return -1 en caso de error, o el id mas alto en caso de exito
 */
int Libro_lastId(LinkedList* pArrayListLibro);

//funciones editar --------------------------------------------------------------------------------

/**
 * \brief Cambia el nombre de un empleado
 * \param pArrayListLibro: LinkedList, index: indice donde se encuentra el empleado
 * \return -1 en caso de error, o 0 en caso de exito
 */
int Libro_changeName(LinkedList* pArrayListLibro, int index);

/**
 * \brief Actualiza las horas trabajadas de un empleado
 * \param pArrayListLibro: LinkedList, index: indice donde se encuentra el empleado
 * \return -1 en caso de error, o 0 en caso de exito
 */
int Libro_changeHours(LinkedList* pArrayListLibro, int index);

/**
 * \brief Cambia el salario de un empleado
 * \param pArrayListLibro: LinkedList, index: indice donde se encuentra el empleado
 * \return -1 en caso de error, o 0 en caso de exito
 */
int Libro_changeSalary(LinkedList* pArrayListLibro, int index);

//FIN funciones editar --------------------------------------------------------------------------------

//funciones ordenar --------------------------------------------------------------------------------

/**
 * \brief Switchea entre los cases de ordenamiento
 * \param pArrayListLibro: LinkedList
 * \return -1 en caso de error, o 0 en caso de exito
 */
int Libro_sort(LinkedList* pArrayListLibro);

/**
 * \brief Compara los ids de dos empleados
 * \param firstLibro: puntero a primer empleado a comprar, secondLibro: puntero a segundo empleado a comprar
 * \return 1 si el id del primer empleado es mas alto, -1 si es mas bajo y 0 si son iguales
 */
int Libro_sortById(void* firstLibro, void* secondLibro);

/**
 * \brief Compara los nombres de dos empleados
 * \param firstLibro: puntero a primer empleado a comprar, secondLibro: puntero a segundo empleado a comprar
 * \return 1 si el nombre del primer empleado esta antes en el alfabeto, -1 si esta despues y 0 si son iguales
 */
int Libro_sortByAutor(void* firstLibro, void* secondLibro);

/**
 * \brief Compara las horas trabajadas de dos empleados
 * \param firstLibro: puntero a primer empleado a comprar, secondLibro: puntero a segundo empleado a comprar
 * \return 1 si las horas trabajadas del primer empleado son mas, -1 si son menos y 0 si son iguales
 */
int Libro_sortByHours(void* firstLibro, void* secondLibro);

/**
 * \brief Compara los sueldos de dos empleados
 * \param firstLibro: puntero a primer empleado a comprar, secondLibro: puntero a segundo empleado a comprar
 * \return 1 si el sueldo del primer empleado es mas alto, -1 si es mas bajo y 0 si son iguales
 */
int Libro_sortBySalary(void* firstLibro, void* secondLibro);
/**
 * \brief Compara los sueldos de dos empleados
 * \param this
 * \return 1 si el sueldo del primer empleado es mas alto, -1 si es mas bajo y 0 si son iguales
 */
void Libro_item4(void* this);

// setters y getters ------------------------------------------------------------------------------------

/**
 * \brief Valida y carga el id en el campo del empleado
 * \param this: puntero a empleado, id: id a validar y cargar
 * \return -1 en caso de error, o 0 en caso de exito
 */
int Libro_setId(Libro* this,int id);

/**
 * \brief Carga el id del empleado en el puntero que pasemos por parametros
 * \param this: puntero a empleado, id: puntero a la variable en la que la funcion cargara el id
 * \return -1 en caso de error, o 0 en caso de exito
 */
int Libro_getId(Libro* this,int* id);

#endif /* LIBRO_H_ */
