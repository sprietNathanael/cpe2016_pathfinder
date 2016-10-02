#ifndef GRAPH_VIEW_MANAGMENT_H
#define GRAPH_VIEW_MANAGMENT_H

#include "sdl_drawing.h"

extern SDL_Surface* ecran;

#define POS_START_X 5
#define POS_START_Y 5
#define SIZE_X 25
#define SIZE_Y 25
#define OFFSET_X 5
#define OFFSET_Y 5
#define POS_BUTTON_X_BASE 20
#define BUTTON_Y_MARGE 5
#define SIZE_BUTTON_X 60
#define SIZE_BUTTON_Y 40

/**
 * @brief      Creates a graph.
 *
 * @param[in]  numRow  The graph number of row
 * @param[in]  numCol  The graph number of column
 * @param      graph   The graph itself
 */
void createGraph(int numRow, int numCol, char* graph);

/**
 * @brief      Calculates the sdl coordinates from graph position.
 *
 * @param[in]  cell  The graph cell
 *
 * @return     The sdl coordinates from graph position.
 */
Coordinates computeSDLCoordinatesFromGraphPosition(Coordinates cell);

void changeRectangeColor(Coordinates graphPosition,int numCol, int r,int g,int b);

/**
 * @brief      Draws line between two nodes.
 *
 * @param[in]  nodeA    The node a
 * @param[in]  nodeB    The node b
 */
void drawLineBetweenTwoNodes(Coordinates nodeA, Coordinates nodeB,int r,int g,int b);

Coordinates computeThePointedNodeCoordinatesFromSDL(int numCol, int x, int y);
#endif

