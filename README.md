# CityGrid Pathfinding Visualizer

## Overview

CityGrid Pathfinding Visualizer is a C++ application that computes the shortest route between two locations on a city grid while avoiding blocked areas. The project simulates route planning in urban infrastructure and construction-site logistics using graph traversal algorithms.

## Problem Statement

In large construction sites and urban layouts, certain regions may be inaccessible due to ongoing work or obstacles. The objective is to determine the shortest feasible route between a source location and a destination while avoiding restricted zones.

## Features

* Shortest path computation using Breadth-First Search (BFS)
* Dynamic obstacle handling
* Path reconstruction from source to destination
* Grid-based visualization of routes
* Distance calculation between locations

## Technologies Used

* C++
* STL (Queue, Vector)
* Graph Algorithms
* Breadth-First Search (BFS)

## Project Structure

```text
CityGrid-Pathfinding-Visualizer/
│
├── main.cpp
├── README.md
├── sample_input.txt
└── sample_output.txt
```

## Sample Grid

```text
S . # . .
. . # . .
. . . . #
# # . . .
. . . # E
```

## Future Enhancements

* Dijkstra's Algorithm for weighted roads
* Interactive grid creation
* Multiple destination support
* Graphical visualization of routes
* Real-time traffic simulation

## Learning Outcomes

* Graph representation using grids
* BFS traversal and shortest path computation
* Queue-based algorithm design
* Time and space complexity analysis

## Author

Aniket Raval
B.Tech Civil Engineering, IIT Madras
