/**
 * @file graph_view_managment.h
 * @brief      Create a graph into a window
 * @author     Nathanaël SPRIET
 */

#ifndef GRAPH_VIEW_MANAGMENT_H
#define GRAPH_VIEW_MANAGMENT_H

#include "sdl_drawing.h"

/*
 **************************** Global *************************
*/
/**
 * @brief      Main SDL surface shared with the whole application
 */
extern SDL_Surface* screen;

/*
 **************************** Constants *************************
*/
/**
 * @brief      First node X position
 */
#define POS_START_X 5
/**
 * @brief      First Y position
 */
#define POS_START_Y 5
/**
 * @brief      X size of a node
 */
#define SIZE_X 25
/**
 * @brief      Y size of a node
 */
#define SIZE_Y 25
/**
 * @brief      Node X marge
 */
#define OFFSET_X 5
/**
 * @brief      Node Y marge
 */
#define OFFSET_Y 5
/**
 * @brief      First button X position
 */
#define POS_BUTTON_X_BASE 20
/**
 * @brief      Button Y marge
 */
#define BUTTON_Y_MARGE 5
/**
 * @brief      X size of a button
 */
#define SIZE_BUTTON_X 60
/**
 * @brief      Y size of a button
 */
#define SIZE_BUTTON_Y 40

/*
 **************************** Functions *************************
*/

/**
 * @brief      Graphically creates a graph
 *
 * @param[in]      numRow  The row quantity
 * @param[in]      numCol  The col quantity
 * @param[in, out] graph   A pointer to the graph
 */
void createGraph(int numRow, int numCol, char* graph);

/**
 * @brief      Calculates the sdl coordinates from graph position
 *
 * @param[in]  cell  The graph cell
 *
 * @return     The sdl coordinates from graph position.
 */
Coordinates computeSDLCoordinatesFromGraphPosition(Coordinates cell);

/**
 * @brief      Changes the color of a node
 *
 * @param[in]  graphPosition  The graph position
 * @param[in]  numCol         The col quantity
 * @param[in]  r              The red channel of the wanted color
 * @param[in]  g              The green channel of the wanted color
 * @param[in]  b              The blue channel of the wanted color
 */
void changeRectangeColor(Coordinates graphPosition,int numCol, int r,int g,int b);

/**
 * @brief      Draws line between two nodes with a specific color
 *
 * @param[in]  nodeA  The node a
 * @param[in]  nodeB  The node b
 * @param[in]  r      The red channel of the wanted color
 * @param[in]  g      The green channel of the wanted color
 * @param[in]  b      The blue channel of the wanted color
 */
void drawLineBetweenTwoNodes(Coordinates nodeA, Coordinates nodeB,int r,int g,int b);

/**
 * @brief      Calculates the the pointed node coordinates from sdl position
 *
 * @param[in]  numCol  The col quantity
 * @param[in]  x       SDL x position
 * @param[in]  y       SDL y position
 *
 * @return     The pointed node coordinates
 */
Coordinates computeThePointedNodeCoordinatesFromSDL(int numCol, int x, int y);
#endif

