#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

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

#define COORDINATES_SIZE (2*sizeof(int))

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
	Coordinates coordinates; /* The coordinates of Node */
	Coordinates parentCoordinates; /* The parent coordinates */
};
/**
 * A type defined over the Node structure
 */
typedef struct Node Node;

#define NODE_SIZE (3*sizeof(int)+sizeof(char)+COORDINATES_SIZE)

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
 * @brief      Lauches the path resolution for the graph
 *
 * @param[in]  numRow  The graph's number row
 * @param[in]  numCol  The graph's number col
 * @param      graph   The char graph
 */
void launchPathResolution(int numRow, int numCol, char graph[numRow][numCol]);
/**
 * @brief      Displays the graph
 *
 * @param[in]  numRow  The matrix's number of rows
 * @param[in]  numCol  The matrix's number of columns
 * @param      graph   The matrix itself
 */
void displayGraph(int numRow, int numCol, char graph[numRow][numCol]);

/**
 * @brief      Finds the coordinates of a given charater in a Node graph
 *
 * @param[in]  numRow      The matrix's number of rows
 * @param[in]  numCol      The matrix's number of columns
 * @param      graph       The matrix itself
 * @param[in]  charToFind  The character to find
 *
 * @return     The coordinates of the character to find
 */
Coordinates findCoordinatesInCharGraph(int numRow, int numCol, char graph[numRow][numCol], char charToFind);

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


/**
 * @brief      Pull an element from a Node list and re-equals the indexes of the
 *             list
 *
 * @param      listLength           The list length
 * @param      list                 The list
 * @param      indexOfNodeToRemove  The index of node to remove
 */
void removeNodeFromList(int listLength, Node list[listLength], int indexOfNodeToRemove);


/**
 * @brief      Analyses the 8 neighbour nodes of a given Node
 *
 * @param[in]  listLength     The list length
 * @param      openList       The open list
 * @param      openListHead   The open list head
 * @param      closeList      The close list
 * @param[in]  closeListHead  The close list head
 * @param[in]  numRow         The graph number row
 * @param[in]  numCol         The graph number col
 * @param      graph          The graph
 * @param[in]  currentNode    The current node
 */
void analysingNeighbourNodes(int listLength, Node openList[listLength], int *openListHead, Node closeList[listLength], int closeListHead, int numRow, int numCol, char graph[numRow][numCol], Node currentNode);


/**
 * @brief      Compares two nodes by their F parameter
 *
 * @param[in]  a     first node
 * @param[in]  b     second node
 *
 * @return     integer
 * 			   -1 if a < b
 * 			   0 if a == b
 * 			   1 if a > b
 */
int compareNodeByF (Node a, Node b);

/**
 * @brief      Sort the first items (to indexLimitation) of the list increasingly by the nodes' F parameter
 *
 * @param[in]  listLength       The list length
 * @param      list             The list
 * @param[in]  indexLimitation  The index limitation
 */
void sortList(int listLength, Node list[listLength], int indexLimitation);

int getExistingNodeInList(int listLength, Node openList[listLength], int openListHead, Coordinates coordinatesToFind);

#define PATHFINDING_H
#endif