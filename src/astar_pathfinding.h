#include "node_managment.h"

#ifndef A_STAR_PATHFINDING_H
#define A_STAR_PATHFINDING_H

/**
 * @brief      Lauches the path resolution algorithm for the graph
 *
 * @param[in]  numRow  The graph's number row
 * @param[in]  numCol  The graph's number col
 * @param      graph   The char graph
 */
void launchPathResolution(int numRow, int numCol, char graph[numRow][numCol]);

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
 * @param[in]  currentNode    Pointer to the parent Node in the close list
 *
 * @return     1 if it foud the target, 0 else
 */
int analysingNeighbourNodes(int listLength, Node openList[listLength], int *openListHead, Node closeList[listLength], int closeListHead, int numRow, int numCol, char graph[numRow][numCol], Node* currentNode);

/**
 * @brief      Determines ability to go to a given point.
 *
 * @param[in]  numRow       The graph number of row
 * @param[in]  numCol       The graph number of col
 * @param      graph        The graph
 * @param      currentNode  The current node
 * @param[in]  deltaX       The delta x
 * @param[in]  deltaY       The delta y
 *
 * @return     True if able to go to given point, False otherwise.
 */
int canGoToThisPoint(int numRow, int numCol, char graph[numRow][numCol], Node* currentNode, int deltaX, int deltaY);

#endif /* A_STAR_PATHFINDING_H */