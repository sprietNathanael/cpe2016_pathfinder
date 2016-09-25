#ifndef GRAPH_VIEW_MANAGMENT_H
#define GRAPH_VIEW_MANAGMENT_H

#include "sdl_drawing.h"


#define POS_START_X 5
#define POS_START_Y 5
#define SIZE_X 25
#define SIZE_Y 25
#define OFFSET_X 5
#define OFFSET_Y 5
#define POS_BUTTON_X 300
#define POS_BUTTON_Y 300
#define SIZE_BUTTON_X 80
#define SIZE_BUTTON_Y 40


/**
 * @brief      Create the screen
 */
void sdlInit();

/**
 * @brief      Creates a graph.
 *
 * @param[in]  numRow  The graph number of row
 * @param[in]  numCol  The graph number of column
 * @param      graph   The graph itself
 */
void createGraph(int numRow, int numCol, char* graph);

/**
 * @brief      Draws the final path.
 *
 * @param[in]  finalPathLength  The final path length
 * @param[in]  numRow           The graph number of row
 * @param[in]  numCol           The graph number of col
 * @param      finalPath        The final path itself
 */
void drawFinalPath(int finalPathLength, int numRow, int numCol, Coordinates finalPath[numRow*numCol]);


/**
 * @brief      Check if the given cursor position is in the "find path" button
 *
 * @param[in]  cursorPosition  The cursor position
 *
 * @return     1 if the cursor position is in the button, 0 else
 */
int findPathButtonClicked(Coordinates cursorPosition);


/**
 * @brief      Calculates the sdl coordinates from graph position.
 *
 * @param[in]  cell  The graph cell
 *
 * @return     The sdl coordinates from graph position.
 */
Coordinates computeSDLCoordinatesFromGraphPosition(Coordinates cell);
#endif

