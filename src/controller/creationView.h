/**
 * @file creationView.h
 * @brief      Create a creation window
 * @author     Nathanaël SPRIET
 */

#ifndef CREATION_VIEW_H
#define CREATION_VIEW_H

#include "../view/creation_view_managment.h"
#include "../fileManager/exportGraph.h"

/*
 **************************** Constants *************************
*/
/**
 * @brief      Maximum window height
 */
#define HEIGHT_MAX 25
/**
 * @brief      Maximum window width
 */
#define WIDTH_MAX 25

/*
 ***************************** Functions *************************
*/

/**
 * @brief          Main loop of the creation window
 *
 * @param[in]      numRow  The row quantity
 * @param[in]      numCol  The col quantity
 * @param[in, out] graph   A pointer to the graph
 *
 * @return         Exit state of the loop :
 * - 1 if the created graph is to be used
 * - 0 if not
 * - -1 if the program has to quit
 */
int mainCreationLoop(int numRow, int numCol, char* graph);


/**
 * @brief          Loop that creates SDL window
 *
 * @param[in]      numRow  The row quantity
 * @param[in]      numCol  The col quantity
 * @param[in, out] graph   A pointer to the graph
 *
 * @return         Exit state of the loop :
 * - 1 if the created graph is to be used
 * - 0 if not
 * - -1 if the program has to quit
 */
int launchCreationView(int numRow, int numCol, char* graph);


#endif /* CREATION_VIEW_H */