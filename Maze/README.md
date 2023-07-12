# Maze

This project implements a maze-solving algorithm using C++. It allows you to create and solve mazes represented by 3D arrays. The maze-solving algorithm utilizes recursive backtracking.

## Project Files

- `main.cpp`: The main entry point of the program. It reads instructions from input files and performs maze-related operations.
- `Pathfinder.h` and `Pathfinder.cpp`: The header and implementation files for the `Pathfinder` class, which handles maze-related operations.
- `Makefile`: The Makefile for compiling the project.

## Usage

To compile and run the project, follow these steps:

1. Make sure you have a C++ compiler installed on your system.
2. Clone the repository to your local machine.
3. Navigate to the "Maze" project directory in your terminal or command prompt.

### Using Makefile

4. Run the `make` command to compile the project:

make

5. Execute the compiled program:

./maze


### Without Makefile

4. Compile the source files using the appropriate command for your compiler. For example:

g++ -std=c++11 -g -o maze main.cpp Pathfinder.cpp

5. Run the compiled program:

./maze


## Instructions

The program reads instructions from input files and performs various operations on mazes. The supported instructions include:

- `importMaze`: Import a maze from a file.
- `toString`: Get a string representation of the maze.
- `createRandomMaze`: Create a random maze.
- `solveMaze`: Solve the maze using a recursive backtracking algorithm.

Please refer to the source code (`main.cpp`) for more details on the instructions and their usage.

