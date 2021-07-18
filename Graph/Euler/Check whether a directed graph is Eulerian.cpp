// https://www.techiedelight.com/eulerian-path-directed-graph/


#include <iostream>
#include <vector>
using namespace std;
 
// Data structure to store a graph edge
struct Edge {
    int src, dest;
};
 
// A class to represent a graph object
class Graph
{
public:
    // vector of vectors to represent an adjacency list
    vector<vector<int>> adjList;
 
    // vector to store in-degree of each vertex in the graph
    vector<int> in;
 
    // Constructor
    Graph(int N)
    {
        // resize both vectors to hold `N` elements each
        adjList.resize(N);
        in.resize(N);
    }
 
    // Utility function to add an edge `u —> v` to the graph
    // and update in-degree for each edge
    void addEdge(int u, int v)
    {
        adjList[u].push_back(v);
        in[v]++;
    }
};
 
// Utility function to perform DFS traversal on the graph
void DFS(Graph const &graph, int u, vector<bool> &visited)
{
    // mark the current node as visited
    visited[u] = true;
 
    // do for every edge `u —> v`
    for (int v: graph.adjList[u])
    {
        // recur if `v` is not visited
        if (!visited[v]) {
            DFS(graph, v, visited);
        }
    }
}
 
// Function to replace all the directed edges of the graph with undirected edges
// and produce an undirected graph
Graph getUndirectedGraph(Graph const &graph, int N)
{
    Graph g(N);
 
    // do for every edge `u —> v`
    for (int u = 0; u < N; u++)
    {
        for (int v: graph.adjList[u])
        {
            g.addEdge(v, u);
            g.addEdge(u, v);
        }
    }
    return g;
}
 
// Function to check if all vertices with a non-zero degree in a graph
// belong to a single connected component
bool isConnected(Graph const &graph, int N)
{
    // keep track of all previously visited vertices in DFS
    vector<bool> visited(N);
 
    // start DFS from the first vertex with a non-zero degree
    for (int i = 0; i < N; i++)
    {
        if (graph.adjList[i].size())
        {
            DFS(graph, i, visited);
            break;
        }
    }
 
    // if a single DFS call couldn't visit all vertices with a non-zero degree,
    // the graph contains more than one connected component
    for (int i = 0; i < N; i++)
    {
        if (!visited[i] && graph.adjList[i].size() > 0) {
            return false;
        }
    }
 
    return true;
}
 
// Function to check if a directed graph has an Eulerian path
bool hasEulerPath(Graph const &graph, int N)
{
    /*
        The following loop checks the following conditions to determine if an
        Eulerian path can exist or not:
            a. At most one vertex in the graph has `out-degree = 1 + in-degree`.
            b. At most one vertex in the graph has `in-degree = 1 + out-degree`.
            c. Rest all vertices have `in-degree == out-degree`.
 
        If either of the above condition fails, the Euler path can't exist.
    */
 
    bool x = false, y = false;
    for (int i = 0; i < N; i++)
    {
        int out_degree = graph.adjList[i].size();
        int in_degree = graph.in[i];
 
        if (out_degree != in_degree)
        {
            if (!x && out_degree - in_degree == 1) {
                x = true;
            }
            else if (!y && in_degree - out_degree == 1) {
                y = true;
            }
            else {
                return false;
            }
        }
    }
 
    // consider given edges as undirected and check if all non-isolated vertices
    // belong to a single connected component
    return isConnected(getUndirectedGraph(graph, N), N);
}
 
int main()
{
    // vector of graph edges as per the above diagram
    vector<Edge> edges = {
        {0, 1}, {1, 2}, {2, 3}, {3, 1}, {1, 4},
        {4, 3}, {3, 0}, {0, 5}, {5, 4}
    };
 
    // total number of nodes in the graph
    int N = 6;
 
    // build a directed graph from the above edges
    Graph graph(N);
 
    // add edges to the directed graph
    for (auto &edge: edges) {
        graph.addEdge(edge.src, edge.dest);
    }
 
    if (hasEulerPath(graph, N)) {
        cout << "The graph has an Eulerian path" << endl;
    }
    else {
        cout << "The Graph doesn't have an Eulerian path" << endl;
    }
 
    return 0;
}
