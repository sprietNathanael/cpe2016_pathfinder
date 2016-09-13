#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#ifndef GRAPH_MANAGMENT_H
#define GRAPH_MANAGMENT_H

/*
 **************************** Constants *************************
*/

#define SIMPLE_DISTANCE_FACTOR 10
#define DIAGONAL_DISTANCE_FACTOR 14
#define TYPE_WALL 'W'
#define TYPE_START 'S'
#define TYPE_TARGET 'T'
#define TYPE_NORMAL '0'

/*
 ***************************** Structures *************************
*/

/**
 * A type defined over the Coordinates structure
 */
typedef struct Coordinates Coordinates;
/**
 * @brief      Represents a coordinate tuple with x and y
 */
struct Coordinates
{
    int x;
    int y;
};

#define COORDINATES_SIZE (2*sizeof(int))

/*
 ***************************** Functions *************************
*/

/**
 * @brief      Displays the graph in console mode
 *
 * @param[in]  numRow  The graph's number of rows
 * @param[in]  numCol  The graph's number of columns
 * @param      graph   The graph itself
 */
void displayGraph(int numRow, int numCol, char graph[numRow][numCol]);

/**
 * @brief      Finds the coordinates of a given charater in a char graph
 *
 * @param[in]  numRow      The graph's number of rows
 * @param[in]  numCol      The graph's number of columns
 * @param      graph       The graph itself
 * @param[in]  charToFind  The character to find
 *
 * @return     The coordinates of the character to find
 */
Coordinates findCoordinatesInCharGraph(int numRow, int numCol, char graph[numRow][numCol], char charToFind);

/**
 * @brief      Calculates the "simple distance" between two coordinates.
 *             "Simple distance" is distance without diagonal pathes omitting
 *             the walls. It multiplies it by the simple distance factor to get
 *             the H value of the node.
 *
 * @param[in]  firstCoordinates   The first point's coordinates
 * @param[in]  secondCoordinates  The second point's coordinates
 *
 * @return     The simple distance between the coordinates.
 */
int computeSimpleDistanceBetweenCoordinates(Coordinates firstCoordinates, Coordinates secondCoordinates);

#endif /* GRAPH_MANAGMENT_H */