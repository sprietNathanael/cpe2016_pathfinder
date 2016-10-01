#include "graph_managment.h"

#ifndef NODE_MANAGMENT_H
#define NODE_MANAGMENT_H

/*
 ***************************** Structures *************************
*/

/**
 * A type defined over the Node structure
 */
typedef struct Node Node;
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
	Node* parent; /* A pointer to the parent */
};


#define NODE_SIZE (3*sizeof(int)+sizeof(char)+COORDINATES_SIZE)

/*
 ***************************** Functions *************************
*/

/**
 * @brief      Pulls an element from a Node list and re-equals the indexes of
 *             the list
 *
 * @param[in]  listHead             The list head
 * @param      list                 The list
 * @param      indexOfNodeToRemove  The index of node to remove
 */
void removeNodeFromList(int listHead, Node* list, int indexOfNodeToRemove);

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
 * @param      list             The list
 * @param[in]  indexLimitation  The index limitation
 */
void sortList(Node* list, int indexLimitation);

/**
 * @brief      Gets the index of existing node in list.
 *
 * @param      list           The list
 * @param[in]  listHead       The list head
 * @param[in]  coordinatesToFind  The coordinates to find
 *
 * @return     The index of node in list, -1 if not present.
 */
int getExistingNodeInList(Node* list, int listHead, Coordinates coordinatesToFind);

#endif /* NODE_MANAGMENT_H */