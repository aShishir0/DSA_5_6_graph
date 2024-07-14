#include "graph.h"
using namespace std;

Graph::Graph(bool isDirected) : directed(isDirected) {}

bool Graph::isEmpty() {
    return adjacencyList.empty();
}

bool Graph::isDirected() {
    return directed;
}

void Graph::addVertex(int newVertex) {
    adjacencyList[newVertex];  // This will create an entry for the new vertex if it doesn't exist
}

void Graph::addEdge(int vertex1, int vertex2) {
    adjacencyList[vertex1].insert(vertex2);
    if (!directed) {
        adjacencyList[vertex2].insert(vertex1);
    }
}

void Graph::removeVertex(int vertexToRemove) {
    for (auto it = adjacencyList.begin(); it != adjacencyList.end(); ++it) {
        it->second.erase(vertexToRemove);
    }
    adjacencyList.erase(vertexToRemove);
}

void Graph::removeEdge(int vertex1, int vertex2) {
    adjacencyList[vertex1].erase(vertex2);
    if (!directed) {
        adjacencyList[vertex2].erase(vertex1);
    }
}

int Graph::numVertices() {
    return adjacencyList.size();
}

int Graph::numEdges() {
    int count = 0;
    for (auto it = adjacencyList.begin(); it != adjacencyList.end(); ++it) {
        count += it->second.size();
    }
    return directed ? count : count / 2;
}

int Graph::indegree(int vertex) {
    int count = 0;
    for (auto it = adjacencyList.begin(); it != adjacencyList.end(); ++it) {
        if (it->second.count(vertex)) {
            count++;
        }
    }
    return count;
}

int Graph::outdegree(int vertex) {
    return adjacencyList[vertex].size();
}

int Graph::degree(int vertex) {
    return directed ? indegree(vertex) + outdegree(vertex) : outdegree(vertex);
}

::vector<int> Graph::neighbours(int vertex) {
    return ::vector<int>(adjacencyList[vertex].begin(), adjacencyList[vertex].end());
}

bool Graph::neighbour(int vertex1, int vertex2) {
    return adjacencyList[vertex1].count(vertex2) > 0;
}

void Graph::printGraph() {
    for (auto it = adjacencyList.begin(); it != adjacencyList.end(); ++it) {
        cout << it->first << ": ";
        for (const int neighbor : it->second) {
            cout << neighbor << " ";
        }
        cout << ::endl;
    }
}

void Graph::generateRandomGraph(int numVertices, int numEdges) {
    adjacencyList.clear();
    for (int i = 0; i < numVertices; ++i) {
        addVertex(i);
    }

    // Add random edges
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> vertexDist(0, numVertices - 1);

    for (int i = 0; i < numEdges; ++i) {
        int vertex1 = vertexDist(gen);
        int vertex2 = vertexDist(gen);
        addEdge(vertex1, vertex2);
    }
}