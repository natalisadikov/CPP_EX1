// 206396863
// natalisadikov2318@gmail.com

#include "doctest.h"
#include "Algorithms.hpp"
#include "Graph.hpp"
#include <random>
#include <chrono>

using namespace std;


TEST_CASE("Test isConnected")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isConnected(g) == "true");

    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::isConnected(g) == "false");
}

TEST_CASE("Test shortestPath")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 2) == "0->1->2");

    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::shortestPath(g, 0, 4) == "-1");
}
TEST_CASE("Test isContainsCycle")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isContainsCycle(g) == "true");

    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::isContainsCycle(g) == "true");
}
TEST_CASE("Test isBipartite")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isBipartite(g) == "The graph is bipartite: A={0, 2}, B={1}");

    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph2);
    CHECK(ariel::Algorithms::isBipartite(g) == "0");

    vector<vector<int>> graph3 = {
        {0, 1, 2, 0, 0},
        {1, 0, 3, 0, 0},
        {2, 3, 0, 4, 0},
        {0, 0, 4, 0, 5},
        {0, 0, 0, 5, 0}};
    g.loadGraph(graph3);
    CHECK(ariel::Algorithms::isBipartite(g) == "0");
}
TEST_CASE("Test invalid graph")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 2, 0},
        {1, 0, 3, 0},
        {2, 3, 0, 4},
        {0, 0, 4, 0},
        {0, 0, 0, 5}};
    CHECK_THROWS(g.loadGraph(graph));
}
TEST_CASE("Test isConnected with a complete graph") {
    ariel::Graph g;
    size_t n = 5;
    std::vector<std::vector<int>> graph(n, std::vector<int>(n, 1));
    for (size_t i = 0; i < n; ++i) graph[i][i] = 0;
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isConnected(g) == "true");
}

TEST_CASE("Test isBipartite with a complete graph") {
    ariel::Graph g;
    size_t n = 5;
    std::vector<std::vector<int>> graph(n, std::vector<int>(n, 1));
    for (size_t i = 0; i < n; ++i) graph[i][i] = 0;
    g.loadGraph(graph);
    CHECK(ariel::Algorithms::isBipartite(g) == "0");
}

TEST_CASE("Test all algorithms with a large sparse graph") {
    ariel::Graph g;
    size_t n = 1000;
    std::vector<std::vector<int>> graph(n, std::vector<int>(n, 0));
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = i + 1; j < std::min(n, i + 5); ++j) {
            graph[i][j] = graph[j][i] = 1;
        }
    }
    g.loadGraph(graph);
    CHECK_NOTHROW(ariel::Algorithms::isConnected(g));
    CHECK_NOTHROW(ariel::Algorithms::shortestPath(g, 0, static_cast<int>(n)-1));
    CHECK_NOTHROW(ariel::Algorithms::isContainsCycle(g));
    CHECK_NOTHROW(ariel::Algorithms::isBipartite(g));
    CHECK_NOTHROW(ariel::Algorithms::negativeCycle(g));
}

TEST_CASE("Test all algorithms with a large dense graph") {
    ariel::Graph g;
    size_t n = 500;
    std::vector<std::vector<int>> graph(n, std::vector<int>(n, 1));
    for (size_t i = 0; i < n; ++i) graph[i][i] = 0;
    g.loadGraph(graph);
    CHECK_NOTHROW(ariel::Algorithms::isConnected(g));
    CHECK_NOTHROW(ariel::Algorithms::shortestPath(g, 0, static_cast<int>(n)-1));
    CHECK_NOTHROW(ariel::Algorithms::isContainsCycle(g));
    CHECK_NOTHROW(ariel::Algorithms::isBipartite(g));
    CHECK_NOTHROW(ariel::Algorithms::negativeCycle(g));
}

TEST_CASE("Test the robustness of algorithms with random graphs") {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 1);

    for (int i = 0; i < 100; ++i) {
        ariel::Graph g;
        size_t n = 50;
        std::vector<std::vector<int>> graph(n, std::vector<int>(n));
        for (size_t i = 0; i < n; ++i) {
            for (size_t j = i + 1; j < n; ++j) {
                graph[i][j] = graph[j][i] = dis(gen);
            }
        }
        g.loadGraph(graph);
        
        CHECK_NOTHROW(ariel::Algorithms::isConnected(g));
        CHECK_NOTHROW(ariel::Algorithms::shortestPath(g, 0, static_cast<int>(n)-1));
        CHECK_NOTHROW(ariel::Algorithms::isContainsCycle(g));
        CHECK_NOTHROW(ariel::Algorithms::isBipartite(g));
        CHECK_NOTHROW(ariel::Algorithms::negativeCycle(g));
    }
}