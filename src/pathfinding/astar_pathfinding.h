/**
 * @file astar_pathfinding.h
 * @brief Compute A* or Djikstra algorithm on a char graph
 * @author Nathanaël SPRIET
 */

#include <unistd.h>
#include "../model/node_managment.h"
#include "../view/resolution_view_managment.h"

#ifndef A_STAR_PATHFINDING_H
#define A_STAR_PATHFINDING_H

/**
 * @brief          Lauches the path resolution algorithm for the graph
 *
 * @param[in]      numRow      The row quantity
 * @param[in]      numCol      The col quantity
 * @param[in, out] graph       A pointer to the graph
 * @param[out]     finalPath   The final path to populate
 * @param[in]      time        The time between each step
 * @param[in]      stepByStep  Whether the resolution has to be step by step or
 *                             not
 * @param[in]      djikstra    Whether the resolution has to be realised with
 *                             Djikstra algorithm or not
 *
 * @return         the final path length
 */
int launchPathResolution(int numRow, int numCol, char* graph, Coordinates* finalPath, int time, int stepByStep, int djikstra);
/**
 * @brief         Analyses the 8 neighbour nodes of a given Node
 *
 * @param[in,out] openList       A pointer to the open list
 * @param[in,out] openListHead   A pointer to the open list head
 * @param[in]     closeList      A pointer to the close list
 * @param[in]     closeListHead  The close list head
 * @param[in]     numRow         The row quantity
 * @param[in]     numCol         The col quantity
 * @param[in,out] graph          A pointer to the graph
 * @param[in]     currentNode    A pointer to the parent Node in the close list
 * @param[in]     stepByStep     Whether the resolution has to be step by step
 *                               or not
 * @param[in]     djikstra       Whether the resolution has to be realised with
 *                               Djikstra algorithm or not
 *
 * @return        State of target fond :
 * - 1 if it foud the target
 * - 0 else
 */
int analysingNeighbourNodes(Node* openList, int *openListHead, Node* closeList, int closeListHead, int numRow, int numCol, char* graph, Node* currentNode, int stepByStep, int djikstra);

/**
 * @brief          Determines ability for a Node to go to a given Coordinates.
 *
 * @param[in]      numCol       The col quantity
 * @param[in, out] graph        A pointer to the graph
 * @param[in]      currentNode  The current node
 * @param[in]      deltaX       The delta x
 * @param[in]      deltaY       The delta y
 *
 * @return         1 if able to go to given point, 0 otherwise.
 */
int canGoToThisPoint(int numCol, char* graph, Node* currentNode, int deltaX, int deltaY);

/**
 * @brief      Simply pass the canContinueToNextStep variable to true
 */
void continueToNextStep();

/**
 * @brief      Change the color of a Node and redraw the line between the node
 *             and its parent if needed
 *
 * @param[in]  nodeToChange                  The node to change
 * @param[in]  drawLineBetweenNodeAndParent  Whether to draw the line between
 *                                           node and parent
 * @param[in]  numCol                        The col quantity
 * @param[in]  r                             The red channel of wanted color
 * @param[in]  g                             The green channel of wanted color
 * @param[in]  b                             The blue channel of wanted color
 */
void changeNodeColor(Node nodeToChange, int drawLineBetweenNodeAndParent, int numCol, int r, int g, int b);

#endif /* A_STAR_PATHFINDING_H */