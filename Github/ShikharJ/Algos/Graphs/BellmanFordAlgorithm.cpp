/*
Bellman-Ford Algorithm
----------------------
The Bellman–Ford algorithm is an algorithm that computes shortest
paths from a single source vertex to all of the other vertices in
a weighted digraph. It is slower than Dijkstra's algorithm for the
same problem, but more versatile, as it is capable of handling
graphs in which some of the edge weights are negative numbers.
----------------------
Time Complexity : O(m*n)
Space Complexity : O(n)
*/

#include <iostream>

using namespace std;

int vertices, edges;

int cost[1000];

struct Edge{
    int x;
    int y;
    int weight;
};

Edge E[1000];

int bellmanford(int source){
    for (int i = 0; i < vertices; i++){
        if (i == source){
            cost[i] = 0;
        } else{
            cost[i] == 1000000000;
        }
    }
    bool discovered = false;
    for (int i = 0; i < vertices and not discovered; i++){
        discovered = true;
        for (int j = 0; j < edges; j++){
            int src = E[j].x;
            int dest = E[j].y;
            if (cost[src] + E[j].weight < cost[dest]){
                cost[dest] = cost[src] + E[j].weight;
                discovered = false;
            }
        }
    }
    if (not discovered){
        return -1;
    }
    return 0;
}
