// https://www.geeksforgeeks.org/graph-coloring-applications/
// https://www.geeksforgeeks.org/graph-coloring-set-2-greedy-algorithm/

/*
Graph coloring is widely used. Unfortunately, there is no efficient algorithm available 
for coloring a graph with minimum number of colors as the problem is a known NP Complete problem. 

There are approximate algorithms to solve the problem though. 
Following is the basic Greedy Algorithm to assign colors. 
It doesn’t guarantee to use minimum colors, but it guarantees an upper bound on the number of colors. 

The basic algorithm never uses more than d+1 colors where d is the maximum degree of a vertex in the given graph.
*/


#include<bits/stdc++.h>
using namespace std;

class Graph {
    int V;
    vector<int> *adj;
public:
    Graph(int V) { 
        this->V = V;
        adj = new vector<int>[V];
    }
    ~Graph() {
        delete [] adj;
    }
 
    void addEdge(int u, int v);
 
    void greedyColoring();
};

void Graph::addEdge(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

// Assigns colors (starting from 0) to all vertices and prints the assignment of colors
void Graph::greedyColoring() {
    int result[V];
 
    // Assign the first color to first vertex
    result[0]  = 0;
 
    // Initialize remaining V-1 vertices as unassigned
    for (int u = 1; u < V; u++) {
        result[u] = -1;  // no color is assigned to u
    }
 
    // A temporary array to store the available colors. 
    // False value of available[cr] would mean that the color cr is
    // assigned to one of its adjacent vertices
    bool availableColor[V];
    for (int color = 0; color < V; color++) {
        availableColor[color] = true;
    }
 
    // Assign colors to remaining V-1 vertices
    for (int u = 1; u < V; u++) {
        // Process all adjacent vertices and flag their colors as unavailable
        for (int i: adj[u]) {
            if (result[i] != -1) {
                availableColor[result[i]] = false;
            }
        }
 
        // Find the first available color
        for (int color = 0; color < V; color++) {
            if (availableColor[color] == true) {
                result[u] = color; // Assign the found color
                break;
            }
        }
 
        // Reset the values back to true for the next iteration
        for (int i: adj[u]) {
            if (result[i] != -1) {
                availableColor[result[i]] = true;
            }
        }
    }
 
    // print the result
    for (int u = 0; u < V; u++) {
        cout << "Vertex " << u << " --->  Color " << result[u] << endl;
    }
}

int main() {
    Graph g1(5);
    g1.addEdge(0, 1);
    g1.addEdge(0, 2);
    g1.addEdge(1, 2);
    g1.addEdge(1, 3);
    g1.addEdge(2, 3);
    g1.addEdge(3, 4);
    cout << "=== Coloring of graph 1 ===\n";
    g1.greedyColoring();
 
    Graph g2(5);
    g2.addEdge(0, 1);
    g2.addEdge(0, 2);
    g2.addEdge(1, 2);
    g2.addEdge(1, 4);
    g2.addEdge(2, 4);
    g2.addEdge(4, 3);
    cout << "\n=== Coloring of graph 2 ===\n";
    g2.greedyColoring();
    return 0;
}
