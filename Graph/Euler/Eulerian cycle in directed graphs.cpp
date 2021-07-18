// https://www.techiedelight.com/eulerian-cycle-directed-graph/



#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
// Data structure to store a graph edge
struct Edge {
    int src, dest;
};
 
// A class to represent a graph object
class Graph
{
public:
 
    // A vector of vectors to represent an adjacency list
    vector<vector<int>> adjList;
 
    // A vector to store in-degree of each vertex in the graph
    vector<int> in;
 
    // Graph Constructor
    Graph(int N, vector<Edge> const &edges = {})
    {
        // resize both vectors to hold `N` elements each
        adjList.resize(N);
        in.resize(N);
 
        // add edges to the directed graph, and update in-degree for each edge
        for (auto &edge: edges) {
            addEdge(edge.src, edge.dest);
        }
    }
 
    // Utility function to add an edge `u —> v` to the graph
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
 
// Function to create transpose of a graph, i.e., the same graph
// with the direction of every edge reversed
Graph buildTranspose(Graph const &graph, int N)
{
    Graph g(N);
 
    for (int u = 0; u < N; u++)
    {
        // for every edge `u —> v`, create a reverse edge `v —> u`
        // in the transpose graph
        for (int v: graph.adjList[u]) {
            g.addEdge(v, u);
        }
    }
    return g;
}
 
// Function to check if all vertices of a graph with a non-zero degree are visited
bool isVisited(Graph const &graph, const vector<bool> &visited)
{
    for (int i = 0; i < visited.size(); i++)
    {
        if (graph.adjList[i].size() && !visited[i]) {
            return false;
        }
    }
    return true;
}
 
// Function to check if all vertices with a non-zero degree in a graph belong to a
// single strongly connected component using Kosaraju’s algorithm
bool isSC(Graph const &graph, int N)
{
    // keep track of all previously visited vertices
    vector<bool> visited(N);
 
    // find the first vertex `i` with a non-zero degree, and start DFS from it
    int i;
    for (i = 0; i < N; i++)
    {
        if (graph.adjList[i].size())
        {
            DFS(graph, i, visited);
            break;
        }
    }
 
    // return false if DFS couldn't visit all vertices with a non-zero degree
    if (!isVisited(graph, visited)) {
        return false;
    }
 
    // reset the visited array
    fill(visited.begin(), visited.end(), false);
 
    // create a transpose of the graph
    Graph g = buildTranspose(graph, N);
 
    // perform DFS on the transpose graph using the same starting vertex as
    // used in the previous DFS call
    DFS(g, i, visited);
 
    // return true if second DFS also explored all vertices with a non-zero degree;
    // false otherwise
    return isVisited(g, visited);
}
 
// Function to check if a directed graph has an Eulerian cycle
bool hasEulerianCycle(Graph const &graph, int N)
{
    // check if every vertex has the same in-degree and out-degree
    for (int i = 0; i < N; i++)
    {
        if (graph.adjList[i].size() != graph.in[i]) {
            return false;
        }
    }
 
    // check if all vertices with a non-zero degree belong to a single
    // strongly connected component
    return isSC(graph, N);
}
 
int main()
{
    // vector of graph edges as per the above diagram
    vector<Edge> edges = {
        {0, 1}, {1, 2}, {2, 3}, {3, 1}, {1, 4}, {4, 3}, {3, 0}
    };
 
    // total number of nodes in the graph
    int N = 5;
 
    // build a directed graph from the above edges
    Graph graph(N, edges);
 
    if (hasEulerianCycle(graph, N)) {
        cout << "The graph has an Eulerian cycle" << endl;
    }
    else {
        cout << "The Graph does not contain Eulerian cycle" << endl;
    }
 
    return 0;
}
