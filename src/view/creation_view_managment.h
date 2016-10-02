#ifndef CREATION_VIEW_MANAGMENT_H
#define CREATION_VIEW_MANAGMENT_H

#include "graph_view_managment.h"

#define SECOND_COL_BUTTONS_X (POS_BUTTON_X_BASE*2)+SIZE_BUTTON_X
#define START_BUTTON_CHOICE_Y BUTTON_Y_MARGE
#define TARGET_BUTTON_CHOICE_Y START_BUTTON_CHOICE_Y+SIZE_BUTTON_Y+BUTTON_Y_MARGE
#define WALL_BUTTON_CHOICE_Y TARGET_BUTTON_CHOICE_Y+SIZE_BUTTON_Y+BUTTON_Y_MARGE
#define BLANK_BUTTON_CHOICE_Y WALL_BUTTON_CHOICE_Y+SIZE_BUTTON_Y+BUTTON_Y_MARGE
#define CHOICE_INDICATOR_Y BLANK_BUTTON_CHOICE_Y+SIZE_BUTTON_Y+BUTTON_Y_MARGE
#define VALIDATE_BUTTON_Y BUTTON_Y_MARGE
#define SAVE_BUTTON_Y VALIDATE_BUTTON_Y+SIZE_BUTTON_Y+BUTTON_Y_MARGE
#define CLOSE_BUTTON_Y SAVE_BUTTON_Y+SIZE_BUTTON_Y+BUTTON_Y_MARGE



#define MIN_CREATION_WINDOW_HEIGHT CHOICE_INDICATOR_Y+SIZE_BUTTON_Y+BUTTON_Y_MARGE
#define MIN_CREATION_WINDOW_WIDTH (POS_BUTTON_X_BASE*3)+(SIZE_BUTTON_X*2)


void sdlCreationInit(int numRow, int numCol);

/**
 * @brief      Change the color of the color indicator according to the given
 *             type
 *
 * @param[in]  type  The type
 */
void changeColorIndicator(char type);

/**
 * @brief      Check if the given cursor position is in the "chooseStartButton" button
 *
 * @param[in]  cursorPosition  The cursor position
 *
 * @return     1 if the cursor position is in the button, 0 else
 */
int chooseStartButtonClicked(Coordinates cursorPosition);

/**
 * @brief      Check if the given cursor position is in the "chooseTargetButton" button
 *
 * @param[in]  cursorPosition  The cursor position
 *
 * @return     1 if the cursor position is in the button, 0 else
 */
int chooseTargetButtonClicked(Coordinates cursorPosition);

/**
 * @brief      Check if the given cursor position is in the "chooseWallButton" button
 *
 * @param[in]  cursorPosition  The cursor position
 *
 * @return     1 if the cursor position is in the button, 0 else
 */
int chooseWallButtonClicked(Coordinates cursorPosition);

/**
 * @brief      Check if the given cursor position is in the "chooseBlankButton" button
 *
 * @param[in]  cursorPosition  The cursor position
 *
 * @return     1 if the cursor position is in the button, 0 else
 */
int chooseBlankButtonClicked(Coordinates cursorPosition);

/**
 * @brief      Check if the given cursor position is in the "validateBlankButton" button
 *
 * @param[in]  cursorPosition  The cursor position
 *
 * @return     1 if the cursor position is in the button, 0 else
 */
int validateButtonClicked(Coordinates cursorPosition);

/**
 * @brief      Check if the given cursor position is in the "saveButton" button
 *
 * @param[in]  cursorPosition  The cursor position
 *
 * @return     1 if the cursor position is in the button, 0 else
 */
int saveButtonClicked(Coordinates cursorPosition);

/**
 * @brief      Check if the given cursor position is in the "closeButton" button
 *
 * @param[in]  cursorPosition  The cursor position
 *
 * @return     1 if the cursor position is in the button, 0 else
 */
int closeButtonClicked(Coordinates cursorPosition);

/**
 * @brief      Change the color of a given node according to the given type
 *
 * @param[in]  node    The node
 * @param[in]  type    The type
 * @param[in]  numCol  The number col
 */
void changeTypeColorOfGivenNode(Coordinates node, char type, int numCol);
#endif

