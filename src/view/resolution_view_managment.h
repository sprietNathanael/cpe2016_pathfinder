/**
 * @file resolution_view_managment.h
 * @brief      Create a resolution window
 * @author     Nathanaël SPRIET
 */

#ifndef CREATION_VIEW_MANAGMENT_H
#define CREATION_VIEW_MANAGMENT_H

#include "graph_view_managment.h"

/*
 **************************** Constants *************************
*/
/**
 * @brief      Find path button Y position
 */
#define POS_FIND_PATH_BUTTON_Y BUTTON_Y_MARGE
/**
 * @brief      Slow find path button Y position
 */
#define POS_SLOW_FIND_PATH_BUTTON_Y POS_FIND_PATH_BUTTON_Y+SIZE_BUTTON_Y+BUTTON_Y_MARGE
/**
 * @brief      Clear button Y position
 */
#define POS_CLEAR_BUTTON_Y POS_SLOW_FIND_PATH_BUTTON_Y+SIZE_BUTTON_Y+BUTTON_Y_MARGE
/**
 * @brief      Next step button Y position
 */
#define POS_NEXT_STEP_BUTTON_Y POS_CLEAR_BUTTON_Y+SIZE_BUTTON_Y+BUTTON_Y_MARGE
/**
 * @brief      Algo selector button Y position
 */
#define POS_ALGO_SELECTOR_Y POS_NEXT_STEP_BUTTON_Y+SIZE_BUTTON_Y+BUTTON_Y_MARGE
/**
 * @brief      Build button Y position
 */
#define POS_BUILD_STEP_BUTTON_Y POS_ALGO_SELECTOR_Y+SIZE_BUTTON_Y+BUTTON_Y_MARGE
/**
 * @brief      Minimum height of the resolution window
 */
#define MIN_RESOLUTION_WINDOW_HEIGHT POS_BUILD_STEP_BUTTON_Y+SIZE_BUTTON_Y+BUTTON_Y_MARGE
/**
 * @brief      Minimum width of the resolution window
 */
#define MIN_RESOLUTION_WINDOW_WIDTH (POS_BUTTON_X_BASE*2)+SIZE_BUTTON_X

/**
 * @brief      Create the screen
 *
 * @param[in]  numRow  The row quantity
 * @param[in]  numCol  The col quantity
 */
void sdlResolvInit(int numRow, int numCol);

/**
 * @brief      Draws the final path.
 *
 * @param[in]  finalPathLength  The final path length
 * @param[in]  numRow           The row quantity
 * @param[in]  numCol           The col quantity
 * @param[in]  finalPath        The final path itself
 */
void drawFinalPath(int finalPathLength, int numRow, int numCol, Coordinates finalPath[numRow*numCol]);

/**
 * @brief      Just exchange the debug icon of debug button for next step icon
 */
void changeDebugButtonIcon();


/**
 * @brief      Just toggles the algo selection button icon between A* and Dj
 *
 * @param[in]  djikstra  Boolean value that represent whether djikstra is
 *                       selected or not
 */
void changeAlgoSelectionButtonIcon(int djikstra);

/**
 * @brief      Check if the given cursor position is in the "find path" button
 *
 * @param[in]  cursorPosition  The cursor position
 *
 * @return     1 if the cursor position is in the button, 0 else
 */
int findPathButtonClicked(Coordinates cursorPosition);

/**
 * @brief      Check if the given cursor position is in the "slow find path"
 *             button
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
 * @brief      Check if the given cursor position is in the "build" button
 *
 * @param[in]  cursorPosition  The cursor position
 *
 * @return     1 if the cursor position is in the button, 0 else
 */
int buildButtonClicked(Coordinates cursorPosition);

/**
 * @brief      Check if the given cursor position is in the "algo selection"
 *             button
 *
 * @param[in]  cursorPosition  The cursor position
 *
 * @return     1 if the cursor position is in the button, 0 else
 */
int algoSelectionButtonClicked(Coordinates cursorPosition);

#endif

