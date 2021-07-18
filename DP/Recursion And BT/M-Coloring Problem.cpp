// https://www.geeksforgeeks.org/m-coloring-problem-backtracking-5/
// https://practice.geeksforgeeks.org/problems/m-coloring-problem-1587115620/1
// https://youtu.be/wuVwUK25Rfc

/*
Given an undirected graph and an integer M. The task is to determine if the graph can be colored with at most M colors 
such that no two adjacent vertices of the graph are colored with the same color. 
Here coloring of a graph means the assignment of colors to all vertices. 
Print 1 if it is possible to colour vertices and 0 otherwise.
*/


class Solution {
public:
     
    bool isSafe(int node, int color[], bool graph[101][101], int n, int col) {
        for(int i = 0; i < n; i++) {
            if(i != node && graph[node][i] == 1 && color[i] == col)
                return false;
        }
        return true;
    }
    
    int solve(int node, int color[], int m, int n, bool graph[101][101]) {
        if(node == n) return true;
        
        for(int col = 1; col <= m; col++) {
            if(isSafe(node, color, graph, n, col)) {
                color[node] = col;
                if(solve(node + 1, color, m, n, graph)) return true;
                // backtrack
                color[node] = 0;
            }
        }
        
        return false;
    }
    
    // Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with same colour.
    bool graphColoring(bool graph[101][101], int m, int n) {
        int color[n] = {0};
        return solve(0, color, m, n, graph);
    }
};
