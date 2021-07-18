// https://www.techiedelight.com/eulerian-path-undirected-graph/


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
 
    // a vector of vectors to represent an adjacency list
    vector<vector<int>> adjList;
 
    // Graph Constructor
    Graph(vector<Edge> const &edges, int N)
    {
        // resize the vector to hold `N` elements of type `vector<int>`
        adjList.resize(N);
 
        // add edges to the undirected graph
        for (auto &edge: edges)
        {
            adjList[edge.src].push_back(edge.dest);
            adjList[edge.dest].push_back(edge.src);
        }
    }
};
 
// Utility function to perform DFS traversal on the graph on a graph
void DFS(Graph const &graph, int v, vector<bool> &visited)
{
    // mark the current node as visited
    visited[v] = true;
 
    // do for every edge `(v —> u)`
    for (int u: graph.adjList[v])
    {
        // if `u` is not visited
        if (!visited[u]) {
            DFS(graph, u, visited);
        }
    }
}
 
// Function to check if all vertices with a non-zero degree in a graph
// belong to a single connected component
bool isConnected(Graph const &graph, int N)
{
    // to keep track of whether a vertex is visited or not
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
 
// Utility function to return the total number of vertices with an odd degree
// in a graph
int countOddVertices(Graph const &graph)
{
    int count = 0;
    for (vector<int> list: graph.adjList)
    {
        if (list.size() & 1) {
            count++;
        }
    }
    return count;
}
 
int main()
{
    // vector of graph edges as per the above diagram
    vector<Edge> edges = {
        {0, 1}, {0, 3}, {1, 2}, {1, 3}, {1, 4}, {2, 3}, {3, 4}
    };
 
    // total number of nodes in the graph
    int N = 5;
 
    // create an undirected graph from the given edges
    Graph graph(edges, N);
 
    // check if all vertices with a non-zero degree belong to a single
    // connected component
    bool is_connected = isConnected(graph, N);
 
    // find the total number of vertices with an odd degree
    int odd = countOddVertices(graph);
 
    // An Eulerian path exists if all non-zero degree vertices are connected,
    // and zero or two vertices have an odd degree
 
    if (is_connected && (odd == 0 || odd == 2))
    {
        cout << "The graph has an Eulerian path" << endl;
 
        // A connected graph has an Eulerian cycle if every vertex has an
        // even degree
        if (odd == 0) {
            cout << "The graph has an Eulerian cycle" << endl;
        }
        // The graph has an Eulerian path but not an Eulerian cycle
        else {
            cout << "The Graph is Semi–Eulerian" << endl;
        }
    }
    else {
        cout << "The Graph is not Eulerian" << endl;
    }
 
    return 0;
}
