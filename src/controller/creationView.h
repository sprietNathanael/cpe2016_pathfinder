#ifndef CREATION_VIEW_H
#define CREATION_VIEW_H

#include "../view/creation_view_managment.h"
#include "../fileManager/exportGraph.h"

#define HEIGHT_MAX 25
#define WIDTH_MAX 25

int mainCreationLoop(int numRow, int numCol, char* graph);
int launchCreationView(int numRow, int numCol, char* graph);


#endif /* CREATION_VIEW_H */