// https://www.geeksforgeeks.org/detecting-negative-cycle-using-floyd-warshall/

/*
We are given a directed graph. We need compute whether the graph has negative cycle or not. 
A negative cycle is one in which the overall sum of the cycle comes negative.

In this post, Floyd Warshall Algorithm based solution is discussed that works for both connected and disconnected graphs.

Distance of any node from itself is always zero. 
But in some cases, as in this example, when we traverse further from 4 to 1, the distance comes out to be -2, i.e. distance of 1 from 1 will become -2. 
This is our catch, we just have to check the nodes distance from itself and if it comes out to be negative, 
we will detect the required negative cycle.
*/

#include <bits/stdc++.h>
using namespace std;

// Number of vertices in the graph
#define V 4

#define INF 99999


// Returns true if graph has negative weight cycle else false.
bool negCyclefloydWarshall(int graph[][V]) {
    /* dist[][] will be the output matrix that will
    finally have the shortest
    distances between every pair of vertices */
    int dist[V][V], i, j, k;

    /* Initialize the solution matrix same as input
    graph matrix. Or we can say the initial values
    of shortest distances are based on shortest
    paths considering no intermediate vertex. */
    for (i = 0; i < V; i++)
        for (j = 0; j < V; j++)
            dist[i][j] = graph[i][j];

    /* Add all vertices one by one to the set of
    intermediate vertices.
    ---> Before start of a iteration, we have shortest
        distances between all pairs of vertices such
        that the shortest distances consider only the
        vertices in set {0, 1, 2, .. k-1} as intermediate
        vertices.
    ----> After the end of a iteration, vertex no. k is
        added to the set of intermediate vertices and
        the set becomes {0, 1, 2, .. k} */
    for (k = 0; k < V; k++) {
        // Pick all vertices as source one by one
        for (i = 0; i < V; i++) {
            // Pick all vertices as destination for the above picked source
            for (j = 0; j < V; j++) {
                // If vertex k is on the shortest path from i to j, then update the value of dist[i][j]
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    // If distance of any verex from itself becomes negative, then there is a negative weight cycle.
    for (int i = 0; i < V; i++) {
        if (dist[i][i] < 0) {
            return true;
        }
    }
    return false;
}

// driver program
int main() {
    /* Let us create the following weighted graph
            1
    (0)----------->(1)
    /|\          |
    |            |
-1 |             | -1
    |            \|/
    (3)<-----------(2)
        -1   */
        
    int graph[V][V] = { {0 , 1 , INF , INF},
                        {INF , 0 , -1 , INF},
                        {INF , INF , 0 , -1},
                        {-1 , INF , INF , 0}};
    
    if (negCyclefloydWarshall(graph))
        cout << "Yes graph contains negative weight cycle";
    else
        cout << "No";

    return 0;
}
