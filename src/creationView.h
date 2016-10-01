#ifndef CREATION_VIEW_H
#define CREATION_VIEW_H

#include "creation_view_managment.h"

#ifndef CREATION_VIEW_C
#define PUBLIC extern
#else
#define PUBLIC
#endif

#define HEIGHT_MAX 25
#define WIDTH_MAX 25

PUBLIC void mainCreationLoop(int numRow, int numCol, char* graph);
PUBLIC void launchCreationView(int numRow, int numCol, char* graph);

#undef PUBLIC
#endif /* CREATION_VIEW_H */
