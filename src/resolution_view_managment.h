#ifndef CREATION_VIEW_MANAGMENT_H
#define CREATION_VIEW_MANAGMENT_H

#include "graph_view_managment.h"

#ifndef CREATION_VIEW_MANAGMENT_C
#define PUBLIC extern
#else
#define PUBLIC
#endif

#define POS_FIND_PATH_BUTTON_Y BUTTON_Y_MARGE
#define POS_SLOW_FIND_PATH_BUTTON_Y POS_FIND_PATH_BUTTON_Y+SIZE_BUTTON_Y+BUTTON_Y_MARGE
#define POS_CLEAR_BUTTON_Y POS_SLOW_FIND_PATH_BUTTON_Y+SIZE_BUTTON_Y+BUTTON_Y_MARGE
#define POS_NEXT_STEP_BUTTON_Y POS_CLEAR_BUTTON_Y+SIZE_BUTTON_Y+BUTTON_Y_MARGE
#define POS_BUILD_STEP_BUTTON_Y POS_NEXT_STEP_BUTTON_Y+SIZE_BUTTON_Y+BUTTON_Y_MARGE

#define MIN_RESOLUTION_WINDOW_HEIGHT POS_BUILD_STEP_BUTTON_Y+SIZE_BUTTON_Y+BUTTON_Y_MARGE
#define MIN_RESOLUTION_WINDOW_WIDTH (POS_BUTTON_X_BASE*2)+SIZE_BUTTON_X

/**
 * @brief      Create the screen
 *
 * @param[in]  numRow  The number row
 * @param[in]  numCol  The number col
 */
PUBLIC void sdlResolvInit(int numRow, int numCol);

/**
 * @brief      Draws the final path.
 *
 * @param[in]  finalPathLength  The final path length
 * @param[in]  numRow           The graph number of row
 * @param[in]  numCol           The graph number of col
 * @param      finalPath        The final path itself
 */
PUBLIC void drawFinalPath(int finalPathLength, int numRow, int numCol, Coordinates finalPath[numRow*numCol]);

/**
 * @brief      Just exchange the debug icon of debug button for next step icon
 */
PUBLIC void changeDebugButtonIcon();

/**
 * @brief      Check if the given cursor position is in the "find path" button
 *
 * @param[in]  cursorPosition  The cursor position
 *
 * @return     1 if the cursor position is in the button, 0 else
 */
PUBLIC int findPathButtonClicked(Coordinates cursorPosition);

/**
 * @brief      Check if the given cursor position is in the "slow find path" button
 *
 * @param[in]  cursorPosition  The cursor position
 *
 * @return     1 if the cursor position is in the button, 0 else
 */
PUBLIC int slow_findPathButtonClicked(Coordinates cursorPosition);

/**
 * @brief      Check if the given cursor position is in the "clear" button
 *
 * @param[in]  cursorPosition  The cursor position
 *
 * @return     1 if the cursor position is in the button, 0 else
 */
PUBLIC int clearButtonClicked(Coordinates cursorPosition);

/**
 * @brief      Check if the given cursor position is in the "next step" button
 *
 * @param[in]  cursorPosition  The cursor position
 *
 * @return     1 if the cursor position is in the button, 0 else
 */
PUBLIC int nextStepButtonClicked(Coordinates cursorPosition);

/**
 * @brief      Check if the given cursor position is in the "build" button
 *
 * @param[in]  cursorPosition  The cursor position
 *
 * @return     1 if the cursor position is in the button, 0 else
 */
PUBLIC int buildButtonClicked(Coordinates cursorPosition);

#undef PUBLIC
#endif

