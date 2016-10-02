/**
 * @file exportGraph.h
 * @brief      Tools to export a char graph to a file
 * @author     Nathanaël SPRIET
 */

#ifndef EXPORT_GRAPH
#define EXPORT_GRAPH

#include <stdio.h>
#include <stdlib.h>

/**
 * @brief      Export a char graph to a given file If the file exists, the
 *             function will overwrite it. The first line of file will be the
 *             numRow, the second the numCol, and the last will be the graph
 *             itself
 *
 * @param[in]  numRow    The row quantity
 * @param[in]  numCol    The col quantity
 * @param[in]  graph     A pointer to the graph
 * @param[in]  fileName  The file name
 */
void exportGraphToFile(int numRow, int numCol, char* graph, char* fileName);

#endif