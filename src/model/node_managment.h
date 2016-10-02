/**
 * @file node_managment.h
 * @brief      Tools to manage nodes and node graph
 * @author     Nathanaël SPRIET
 */

#include "graph_managment.h"

#ifndef NODE_MANAGMENT_H
#define NODE_MANAGMENT_H

/*
 ***************************** Structures *************************
*/

/**
 * @brief      A type defined over the Node structure
 */
typedef struct Node Node;
/**
 * @brief      Represents a Node
 */
struct Node
{
	int H; /*!< The simple distance between this node and the target */
	int G; /*!< The distance travaeled to go from the start to this node */
	int F; /*!< The sum of H and G */
	char type; /*!< The type of Node */
	Coordinates coordinates; /*!< The Coordinates of Node */
	Node* parent; /*!< A pointer to the parent Node */
};



/*
 ***************************** Functions *************************
*/

/**
 * @brief         Pulls an element from a Node list and re-equals the indexes of
 *                the list
 *
 * @param[in]     listHead             The list head
 * @param[in,out] list                 The list
 * @param[in]     indexOfNodeToRemove  The index of node to remove
 */
void removeNodeFromList(int listHead, Node* list, int indexOfNodeToRemove);

/**
 * @brief      Compares two nodes by their F parameter
 *
 * @param[in]  a     first node
 * @param[in]  b     second node
 *
 * @return     Result of the operation :
 * - -1 if a < b
 * - 0 if a == b
 * - 1 if a > b
 */
int compareNodeByF (Node a, Node b);

/**
 * @brief         Sort the first items (to indexLimitation) of the list
 *                increasingly by the nodes' F parameter
 *
 * @param[in,out] list             The list
 * @param[in]     indexLimitation  The index limitation
 */
void sortList(Node* list, int indexLimitation);

/**
 * @brief         Gets the index of an existing node in list.
 *
 * @param[in,out] list               The list
 * @param[in]     listHead           The list head
 * @param[in]     coordinatesToFind  The coordinates to find
 *
 * @return        The index of node in list, -1 if not present.
 */
int getExistingNodeInList(Node* list, int listHead, Coordinates coordinatesToFind);

#endif /* NODE_MANAGMENT_H */