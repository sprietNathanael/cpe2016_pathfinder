#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#ifndef PATHFINDING_H

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
 ***************************** Functions *************************
*/

/**
 * @brief      Represents a coordinate tuple with x and y
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
 * @brief      Represents a Node (if you do not understand that, you would
 *             better read the Readme file)
 */
struct Node
{
	int H; /* The simple distance between this node and the target */
	int G; /* The distance between this node and the current node */
	int F; /* The sum of H and G */
	char type; /* The type of Node */
};
/**
 * A type defined over the Node structure
 */
typedef struct Node Node;

/**
 * @brief      Generates a graph from a char matrix The function
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
 * @brief      Displays the graph
 *
 * @param[in]  numRow  The matrix's number of rows
 * @param[in]  numCol  The matrix's number of columns
 * @param      graph   The matrix itself
 */
void displayGraph(int numRow, int numCol, Node graph[numRow][numCol]);

/**
 * @brief      Finds the coordinates of a given charater
 *
 * @param[in]  numRow      The matrix's number of rows
 * @param[in]  numCol      The matrix's number of columns
 * @param      graph       The matrix itself
 * @param[in]  charToFind  The character to find
 *
 * @return     The coordinates of the character to find
 */
Coordinates findCoordinates(int numRow, int numCol, char graph[numRow][numCol], char charToFind);

/**
 * @brief      Calculates the "simple distance" between two coordinates.
 *             "Simple distance" is distance without diagonal pathes. It
 *             multiplies it by the simple distance factor to get the H value of
 *             the node.
 *
 * @param[in]  firstCoordinates   The first point's coordinates
 * @param[in]  secondCoordinates  The second point's coordinates
 *
 * @return     The simple distance between the coordinates.
 */
int computeSimpleDistanceBetweenCoordinates(Coordinates firstCoordinates, Coordinates secondCoordinates);


#define PATHFINDING_H
#endif