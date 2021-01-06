/*
Floyd-Warshall Algorithm
------------------------
the Floyd–Warshall algorithm is an algorithm for finding
shortest paths in a weighted graph with positive or negative
edge weights (but with no negative cycles). A single
execution of the algorithm will find the lengths (summed
weights) of the shortest paths between all pairs of vertices.
Although it does not return details of the paths themselves,
it is possible to reconstruct the paths with simple modifications
to the algorithm.
------------------------
Time Complexity : O(n^3)
Space Complexity : O(n^2)
*/

#include <iostream>

using namespace std;

int vertices;

int distance[1000][1000];
int floyd[1000][1000];

void floydwarshall(){
	for (int i = 1; i <= vertices; i++){
		for (int j = 1; j <= vertices; j++){
			floyd[i][j] = distance[i][j];
		}
		floyd[i][i] = 0;
	}
	for (int k = 1; k <= vertices; k++){
		for (int i = 1; i <= vertices; i++){
			for (int j = 1; j <= vertices; j++){
				if (floyd[i][k] + floyd[k][j] < floyd[i][j]){
					floyd[i][j] = floyd[i][k] + floyd[k][j];
				}
			}
		}
	}
}