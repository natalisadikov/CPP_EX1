// 206396863
// natalisadikov2318@gmail.com

#include "Graph.hpp"
#include <stdexcept>
#include <iostream>

namespace ariel {

    void Graph::loadGraph(const std::vector<std::vector<int>>& matrix) {
        if (matrix.empty() || matrix.size() != matrix[0].size()) {
            throw std::invalid_argument("Invalid graph: The graph is not a square matrix.");
        }
        adjMatrix = matrix;
        numVertices = matrix.size();
        numEdges = 0;
        isDirected = false;

        for (size_t i = 0; i < numVertices; ++i) {
            for (size_t j = i + 1; j < numVertices; ++j) {
                if (adjMatrix[i][j] != 0) {
                    numEdges++;
                    if (adjMatrix[i][j] != adjMatrix[j][i]) {
                        isDirected = true;
                    }
                }
            }
        }

        if (isDirected) {
            // Count edges again for directed graph
            numEdges = 0;
            for (size_t i = 0; i < numVertices; ++i) {
                for (size_t j = 0; j < numVertices; ++j) {
                    if (adjMatrix[i][j] != 0) {
                        numEdges++;
                    }
                }
            }
        }
    }

    void Graph::printGraph() const {
        std::cout << "Graph with " << numVertices << " vertices and " << numEdges << " edges." << std::endl;
        std::cout << "Adjacency Matrix:" << std::endl;
        for (const auto& row : adjMatrix) {
            for (int val : row) {
                std::cout << val << " ";
            }
            std::cout << std::endl;
        }
    }

    const std::vector<std::vector<int>>& Graph::getAdjMatrix() const {
        return adjMatrix;
    }

    size_t Graph::getNumVertices() const {
        return numVertices;
    }

    int Graph::getNumEdges() const {
        return numEdges;
    }

    bool Graph::isDirectedGraph() const {
        return isDirected;
    }

}