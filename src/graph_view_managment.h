#ifndef GRAPH_VIEW_MANAGMENT_H
#define GRAPH_VIEW_MANAGMENT_H

#include "sdl_drawing.h"


#define POS_START_X 5
#define POS_START_Y 5
#define SIZE_X 25
#define SIZE_Y 25
#define OFFSET_X 5
#define OFFSET_Y 5
#define POS_FIND_PATH_BUTTON_X 300
#define POS_FIND_PATH_BUTTON_Y 50
#define POS_SLOW_FIND_PATH_BUTTON_X 300
#define POS_SLOW_FIND_PATH_BUTTON_Y 120
#define POS_CLEAR_BUTTON_X 300
#define POS_CLEAR_BUTTON_Y 190
#define POS_NEXT_STEP_BUTTON_X 300
#define POS_NEXT_STEP_BUTTON_Y 260
#define SIZE_BUTTON_X 60
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
 * @brief      Just exchange the debug icon of debug button for next step icon
 */
void changeDebuButtonIcon();

/**
 * @brief      Check if the given cursor position is in the "find path" button
 *
 * @param[in]  cursorPosition  The cursor position
 *
 * @return     1 if the cursor position is in the button, 0 else
 */
int findPathButtonClicked(Coordinates cursorPosition);

/**
 * @brief      Check if the given cursor position is in the "slow find path" button
 *
 * @param[in]  cursorPosition  The cursor position
 *
 * @return     1 if the cursor position is in the button, 0 else
 */
int slow_findPathButtonClicked(Coordinates cursorPosition);

/**
 * @brief      Check if the given cursor position is in the "clear" button
 *
 * @param[in]  cursorPosition  The cursor position
 *
 * @return     1 if the cursor position is in the button, 0 else
 */
int clearButtonClicked(Coordinates cursorPosition);

/**
 * @brief      Check if the given cursor position is in the "next step" button
 *
 * @param[in]  cursorPosition  The cursor position
 *
 * @return     1 if the cursor position is in the button, 0 else
 */
int nextStepButtonClicked(Coordinates cursorPosition);


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
#endif

