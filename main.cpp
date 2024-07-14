#include "graph.h"
using namespace std;

int main() {
    Graph graph(true);  // Creating a directed graph

    // Adding vertices
    graph.addVertex(1);
    graph.addVertex(2);
    graph.addVertex(3);
    graph.addVertex(4);

    // Adding edges
    graph.addEdge(1, 2);
    graph.addEdge(2, 3);
    graph.addEdge(3, 4);
    graph.addEdge(4, 1);

    // Testing graph properties
    cout << "Is graph empty? " << (graph.isEmpty() ? "Yes" : "No") << ::endl;
    cout << "Is graph directed? " << (graph.isDirected() ? "Yes" : "No") << ::endl;
    cout << "Number of vertices: " << graph.numVertices() << ::endl;
    cout << "Number of edges: " << graph.numEdges() << ::endl;

    // Testing degree functions
    cout << "Indegree of vertex 2: " << graph.indegree(2) << ::endl;
    cout << "Outdegree of vertex 2: " << graph.outdegree(2) << ::endl;
    cout << "Degree of vertex 2: " << graph.degree(2) << ::endl;

    // Testing neighbour functions
    cout << "Neighbours of vertex 2: ";
    for (int neighbour : graph.neighbours(2)) {
        cout << neighbour << " ";
    }
    cout << ::endl;

    cout << "Is vertex 3 a neighbour of vertex 2? " << (graph.neighbour(2, 3) ? "Yes" : "No") << ::endl;

    // Removing an edge and a vertex
    graph.removeEdge(2, 3);
    graph.removeVertex(4);

    cout << "Number of vertices after removal: " << graph.numVertices() << ::endl;
    cout << "Number of edges after removal: " << graph.numEdges() << ::endl;

    cout << "Graph structure:" << ::endl;
    graph.printGraph();

    //Generating a random graph
    graph.generateRandomGraph(5, 6);
    cout << "Randomly generated graph:" << ::endl;
    graph.printGraph();

    return 0;
}