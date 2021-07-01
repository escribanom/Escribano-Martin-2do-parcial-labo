/*
 * parser.h
 *
 *  Created on:
 *      Author:
 */

#ifndef PARSER_H_
#define PARSER_H_

/** \brief Parsea los datos los datos de los libros desde el archivo data.csv (modo texto).
 *
 * \param path char*: el path del archivo a cargar
 * \param pArrayListLibro: LinkedList
 * \return -1 en caso de error, o 0 en caso de exito
 *
 */
int parser_LibroFromText(FILE* pFile , LinkedList* pArrayListLibro);

/** \brief Parsea los datos los datos de los libros desde el archivo data.csv (modo binario).
 *
 * \param path char*: el path del archivo a cargar
 * \param pArrayListLibro: LinkedList
 * \return -1 en caso de error, o 0 en caso de exito
 *
 */
int parser_LibroFromBinary(FILE* pFile , LinkedList* pArrayListLibro);

#endif /* PARSER_H_ */
