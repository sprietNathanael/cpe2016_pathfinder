#include <unistd.h>
#include "node_managment.h"
#include "graph_view_managment.h"

#ifndef A_STAR_PATHFINDING_H
#define A_STAR_PATHFINDING_H

/**
 * @brief      Lauches the path resolution algorithm for the graph
 *
 * @param[in]  numRow      The graph's number row
 * @param[in]  numCol      The graph's number col
 * @param      graph       The char graph
 * @param      finalPath   The final path to populate
 * @param      time        The time between each step
 * @param[in]  stepByStep  Whether the resolution has to be step by step or not
 *
 * @return     the final path length
 */
int launchPathResolution(int numRow, int numCol, char* graph, Coordinates* finalPath, int time, int stepByStep);
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
 * @param[in]  stepByStep  Whether the resolution has to be step by step or not
 *
 * @return     1 if it foud the target, 0 else
 */
int analysingNeighbourNodes(Node* openList, int *openListHead, Node* closeList, int closeListHead, int numRow, int numCol, char* graph, Node* currentNode, int stepByStep);

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
int canGoToThisPoint(int numRow, int numCol, char* graph, Node* currentNode, int deltaX, int deltaY);

/**
 * @brief      Simply pass the canContinueToNextStep variable to true
 */
void continueToNextStep();

/**
 * @brief      Change the color of a Node and redraw the line between the node
 *             and its parent if needed
 *
 * @param[in]  nodeToChange                  The node to change
 * @param[in]  drawLineBetweenNodeAndParent  Draw the draw line between node and parent if 1
 * @param[in]  numCol                        The number of colums
 * @param[in]  r                             red
 * @param[in]  g                             green
 * @param[in]  b                             blue
 */
void changeNodeColor(Node nodeToChange, int drawLineBetweenNodeAndParent, int numCol, int r, int g, int b);

#endif /* A_STAR_PATHFINDING_H */