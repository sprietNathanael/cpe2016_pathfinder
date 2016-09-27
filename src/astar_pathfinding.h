#include <unistd.h>
#include "node_managment.h"
#include "graph_view_managment.h"

#ifndef A_STAR_PATHFINDING_H
#define A_STAR_PATHFINDING_H

/**
 * @brief      Structure that helps in thread creation
 */
typedef struct {
    int numRow;
    int numCol;
    char* graph;
    Coordinates* finalPath;
    int time;
} launchPathResolution_args;

/**
 * @brief      Lauches the path resolution algorithm for the graph (param)
 *
 * @param      args  pointer to a lauchPathResolution_args structure
 *
 * @return     the final path length
 */
void* launchPathResolution(void* args);

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
int analysingNeighbourNodes(Node* openList, int *openListHead, Node* closeList, int closeListHead, int numRow, int numCol, char* graph, Node* currentNode);

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

#endif /* A_STAR_PATHFINDING_H */