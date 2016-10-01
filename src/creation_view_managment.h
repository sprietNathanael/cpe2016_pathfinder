#ifndef CREATION_VIEW_MANAGMENT_H
#define CREATION_VIEW_MANAGMENT_H

#include "graph_view_managment.h"

#ifndef CREATION_VIEW_MANAGMENT_C
#define PUBLIC extern
#else
#define PUBLIC
#endif

#define START_BUTTON_CHOICE_Y BUTTON_Y_MARGE
#define TARGET_BUTTON_CHOICE_Y START_BUTTON_CHOICE_Y+SIZE_BUTTON_Y+BUTTON_Y_MARGE
#define WALL_BUTTON_CHOICE_Y TARGET_BUTTON_CHOICE_Y+SIZE_BUTTON_Y+BUTTON_Y_MARGE
#define BLANK_BUTTON_CHOICE_Y WALL_BUTTON_CHOICE_Y+SIZE_BUTTON_Y+BUTTON_Y_MARGE
#define CHOICE_INDICATOR_Y BLANK_BUTTON_CHOICE_Y+SIZE_BUTTON_Y+BUTTON_Y_MARGE

#define MIN_CREATION_WINDOW_HEIGHT CHOICE_INDICATOR_Y+SIZE_BUTTON_Y+BUTTON_Y_MARGE
#define MIN_CREATION_WINDOW_WIDTH (POS_BUTTON_X_BASE*2)+SIZE_BUTTON_X


PUBLIC void sdlCreationInit(int numRow, int numCol);

/**
 * @brief      Change the color of the color indicator according to the given
 *             type
 *
 * @param[in]  type  The type
 */
PUBLIC void changeColorIndicator(char type);

/**
 * @brief      Check if the given cursor position is in the "chooseStartButton" button
 *
 * @param[in]  cursorPosition  The cursor position
 *
 * @return     1 if the cursor position is in the button, 0 else
 */
PUBLIC int chooseStartButtonClicked(Coordinates cursorPosition);

/**
 * @brief      Check if the given cursor position is in the "chooseTargetButton" button
 *
 * @param[in]  cursorPosition  The cursor position
 *
 * @return     1 if the cursor position is in the button, 0 else
 */
PUBLIC int chooseTargetButtonClicked(Coordinates cursorPosition);

/**
 * @brief      Check if the given cursor position is in the "chooseWallButton" button
 *
 * @param[in]  cursorPosition  The cursor position
 *
 * @return     1 if the cursor position is in the button, 0 else
 */
PUBLIC int chooseWallButtonClicked(Coordinates cursorPosition);

/**
 * @brief      Check if the given cursor position is in the "chooseBlankButton" button
 *
 * @param[in]  cursorPosition  The cursor position
 *
 * @return     1 if the cursor position is in the button, 0 else
 */
PUBLIC int chooseBlankButtonClicked(Coordinates cursorPosition);

/**
 * @brief      Change the color of a given node according to the given type
 *
 * @param[in]  node    The node
 * @param[in]  type    The type
 * @param[in]  numCol  The number col
 */
PUBLIC void changeTypeColorOfGivenNode(Coordinates node, char type, int numCol);

#undef PUBLIC
#endif
