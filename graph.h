#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <random>

class Graph {
private:
    std::unordered_map<int, std::unordered_set<int>> adjacencyList;
    bool directed;

public:
    Graph(bool isDirected = false);

    bool isEmpty();
    bool isDirected();
    void addVertex(int newVertex);
    void addEdge(int vertex1, int vertex2);
    void removeVertex(int vertexToRemove);
    void removeEdge(int vertex1, int vertex2);
    int numVertices();
    int numEdges();
    int indegree(int vertex);
    int outdegree(int vertex);
    int degree(int vertex);
    std::vector<int> neighbours(int vertex);
    bool neighbour(int vertex1, int vertex2);
    void printGraph();
    void generateRandomGraph(int numVertices, int numEdges);
};

#endif 