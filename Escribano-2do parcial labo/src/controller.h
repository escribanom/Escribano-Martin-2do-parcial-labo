/*
 * controller.h
 *
 *  Created on:
 *      Author:
 */

#ifndef CONTROLLER_H_
#define CONTROLLER_H_
/**
 * \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 * \param path char*: path al archivo a cargar
 * \param pArrayListLibro LinkedList*: linkedlist
 * \return -1 en caso de error, o 0 en caso de exito
 */
int controller_loadFromText(char* path , LinkedList* pArrayListLibro);

/**
 * \brief Carga los datos de los empleados desde el archivo data.bin (modo binario).
 * \param path char*: path al archivo a cargar
 * \param pArrayListLibro LinkedList*: linkedlist
 * \return -1 en caso de error, o 0 en caso de exito
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListLibro);

/**
 * \brief Aniade un empleado a la linkedlist
 * \param pArrayListLibro LinkedList*: linkedlist
 * \return -1 en caso de error, o 0 en caso de exito
 */
int controller_addLibro(LinkedList* pArrayListLibro);

/**
 * \brief Edita un empleado de la linkedlist
 * \param pArrayListLibro LinkedList*: linkedlist
 * \return -1 en caso de error, o 0 en caso de exito
 */
int controller_editLibro(LinkedList* pArrayListLibro);

/**
 * \brief Elimina un empleado de la linkedlist
 * \param pArrayListLibro LinkedList*: linkedlist
 * \return -1 en caso de error, o 0 en caso de exito
 */
int controller_removeLibro(LinkedList* pArrayListLibro);

/**
 * \brief Lista los empleados de la linkedlist
 * \param pArrayListLibro LinkedList*: linkedlist
 * \return -1 en caso de error, o 0 en caso de exito
 */
int controller_ListLibro(LinkedList* pArrayListLibro);

/**
 * \brief Ordena los empleados de la linkedlist
 * \param pArrayListLibro LinkedList*: linkedlist
 * \return -1 en caso de error, o 0 en caso de exito
 */
int controller_sortLibro(LinkedList* pArrayListLibro);

/**
 * \brief Guarda los datos en el archivo data.csv (modo texto).
 * \param path char*: path al archivo a guardar
 * \param pArrayListLibro LinkedList*: linkedlist
 * \return -1 en caso de error, o 0 en caso de exito
 */
int controller_saveAsText(char* path , LinkedList* pArrayListLibro);

/**
 * \brief Guarda los datos en el archivo data.bin (modo binario).
 * \param path char*: path al archivo a guardar
 * \param pArrayListLibro LinkedList*: linkedlist
 * \return -1 en caso de error, o 0 en caso de exito
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListLibro);

/**
 * \brief mapea los libros
 * \param pArrayListLibro LinkedList*: linkedlist
 * \return -1 en caso de error, o 0 en caso de exito
 */
int controller_mapLibro(LinkedList* pArrayListLibro);
int controller_ElegirPath(char* path,int formatoArchivo);
#endif /* CONTROLLER_H_ */
