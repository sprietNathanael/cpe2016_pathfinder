# cpe2016_pathfinder
## Goal

The goal of this project is to implements a pathfinding algorithm resolution and to visualise this resolution into a mere gui. The algorithm used in the project is A* (A Star) and it can be used as Djikstra algorithm to compare results.

## Compatibility

The project has been tested only on a Linux based system (Ubuntu 16.4). Since it uses threading system, it is likely to produce errors at a build attempt on a non-unix based system.
Furthermore, it uses SDL1.2, so make sure to have this version installed on your system.

## Compilation

Simply go to the src directory and issue the command ```make``` to compile the binary.
To get rid of generated files, issue the command ```make clean```.

## Launching

When compiled, just execute the ```pathfinder``` binary, and that's all !
If you want to load a graph, just pass it as parameter to your executable like : ```./pathfinder myawesomegraph```
