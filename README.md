# Graph Algorithms Project

This project implements a set of graph algorithms using C++. It has a `Graph` class for representing graphs and an `Algorithms` class that contains methods for graph operations.

## Project Structure

The project is divided into several files:

1. `Graph.hpp` and `Graph.cpp`: Define and implement the `Graph` class.
2. `Algorithms.hpp` and `Algorithms.cpp`: Define and implement the `Algorithms` class.
3. `Test.cpp`: Contains the test cases.

## Graph Class

The `Graph` class is defined in `Graph.hpp` and implemented in `Graph.cpp`. It represents a graph using an adjacency matrix.

### Main methods:
- `loadGraph`: Loads a graph from a given adjacency matrix
- `printGraph`: Prints the graph's adjacency matrix
- Getter methods for various graph properties

## Algorithms Class

The `Algorithms` class is defined in `Algorithms.hpp` and implemented in `Algorithms.cpp`. It contains methods for graph algorithms.

### Implemented algorithms:
1. `isConnected`: Checks if the graph is connected
2. `shortestPath`: Finds the shortest path between two vertices
3. `isContainsCycle`: Detects if the graph contains a cycle
4. `isBipartite`: Determines if the graph is bipartite
5. `negativeCycle`: Checks for the presence of a negative cycle

### Implementation details:
- `isConnected` and `shortestPath` use BFS algorithm.
- `isContainsCycle` uses DFS algorithm.
- `isBipartite` uses a modified BFS.
- `negativeCycle` uses the Bellman-Ford algorithm.


## Testing

The `Test.cpp` file contains test cases for all the implemented algorithms. It uses the Doctest framework for C++ unit testing.
