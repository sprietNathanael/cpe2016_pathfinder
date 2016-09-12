#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#ifndef PATHFINDING_H

/**
 * @brief      A structure that represents a coordinate tuple with x and y
 */
struct Coordinates
{
    int x;
    int y;
};
/**
 * A type defined over the Coordinates structure
 */
typedef struct Coordinates Coordinates;


/**
 * @brief      A function that generates a graph from a char matrix The function
 *             calculates the distance between each node and the target An
 *             obstacle is represented in the matrix by a 'W' The start point is
 *             represented by a 'S' The target point is represented by a 'T' The
 *             other nodes are represented by a '0'
 *
 * @param[in]  numRow  The matrix's number of rows
 * @param[in]  numCol  The matrix's number of columns
 * @param      graph   The matrix itself
 */
void generateGraph(int numRow, int numCol, char graph[numRow][numCol]);

/**
 * @brief      { function_description }
 */
void launchPathResolution(void);

/**
 * @brief      A function that displays the graph
 *
 * @param[in]  numRow  The matrix's number of rows
 * @param[in]  numCol  The matrix's number of columns
 * @param      graph   The matrix itself
 */
void displayGraph(int numRow, int numCol, char graph[numRow][numCol]);

/**
 * @brief      A function that find the coordinates of a given charater
 *
 * @param[in]  numRow      The matrix's number of rows
 * @param[in]  numCol      The matrix's number of columns
 * @param      graph       The matrix itself
 * @param[in]  charToFind  The character to find
 *
 * @return     The coordinates of the character to find
 */
Coordinates findCoordinates(int numRow, int numCol, char graph[numRow][numCol], char charToFind);

#define PATHFINDING_H
#endif