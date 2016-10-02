/**
 * @file importGraph.h
 * @brief      Tools to import a char graph from a file
 * @author     Nathanaël SPRIET
 */

#ifndef IMPORT_GRAPH
#define IMPORT_GRAPH

#include <stdio.h>
#include <stdlib.h>

/**
 * @brief      Import a char graph from a given file
 *
 * @param[in]  fileName  The file name
 * @param[out] height    The height of the new graph
 * @param[out] width     The width of the new graph
 *
 * @return     A pointer to a created char graph
 */
char* importGraphFromFile(const char* fileName, int *height, int *width);

#endif