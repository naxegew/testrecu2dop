/*
 * parser.h
 *
 *  Created on: 11 dic. 2019
 *      Author: igna
 */

#ifndef PARSER_H_
#define PARSER_H_
int parser_EntidadFromBinary(FILE* pFile, LinkedList *pArrayListEntidad);
int parser_EntidadFromText(FILE* pFile, LinkedList *pArrayEntidad);
int parser_saveAsText(FILE* pFile, LinkedList *pArrayListEntidad);


#endif /* PARSER_H_ */
