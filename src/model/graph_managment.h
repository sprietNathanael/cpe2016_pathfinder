/**
 * @file graph_managment.h
 * @brief      Tools to manage a char graph
 * @author     Nathanaël SPRIET
 */


#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#ifndef GRAPH_MANAGMENT_H
#define GRAPH_MANAGMENT_H

/*
 **************************** Constants *************************
*/

/**
 * @brief      Distance factor for straight pathes (not diagonals)
 */
#define SIMPLE_DISTANCE_FACTOR 10
/**
 * @brief      Distance factor for diagonal pathes
 */
#define DIAGONAL_DISTANCE_FACTOR 14
/**
 * @brief      Char representation of an obstacle
 */
#define TYPE_WALL 'W'
/**
 * @brief      Char representation of a start
 */
#define TYPE_START 'S'
/**
 * @brief      Char representation of a target
 */
#define TYPE_TARGET 'T'
/**
 * @brief      Char representation of a normal cell
 */
#define TYPE_NORMAL '0'

/*
 ***************************** Structures *************************
*/

/**
 * @brief      A type defined over the Coordinates structure
 */
typedef struct Coordinates Coordinates;
/**
 * @brief      Represents a coordinate tuple with x and y
 */
struct Coordinates
{
    int x; /*!< X componant of the coordinate */
    int y; /*!< Y componant of the coordinate */
};

/*
 ***************************** Functions *************************
*/

/**
 * @brief          Finds the coordinates of a given charater in a char graph
 *
 * @param[in]      numRow      The row quantity
 * @param[in]      numCol      The col quantity
 * @param[in, out] graph       A pointer to the graph
 * @param[in]      charToFind  The character to find
 *
 * @return         The coordinates of the character to find
 */
Coordinates findCoordinatesInCharGraph(int numRow, int numCol, char* graph, char charToFind);

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