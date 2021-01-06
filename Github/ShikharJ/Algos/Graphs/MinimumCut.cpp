/*
Karger's Mininimum Cut Algorithm
--------------------------------
Karger's algorithm is a randomized algorithm to compute a minimum cut of a connected graph. 
The idea of the algorithm is based on the concept of contraction of an edge (u, v) in an 
undirected graph G = (V, E). Informally speaking, the contraction of an edge merges the 
nodes u and v into one, reducing the total number of nodes of the graph by one.
--------------------------------
Time Complexity : O(n*m) for every pair
Space Complexity : O(n)
*/

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

srand(time(NULL));

struct Edge{
	int source;
	int destination;
};

struct Graph{
	int vertices;
	int edges;
	Edge *edge;
};

struct subset{
	int parent;
	int rank;
};

int find(struct subset subsets[], int i);

int join(struct subset subsets[], int x, int y);

int mincut(Graph *graph){
	int vertices = graph->vertices;
	int edges = graph->edges;
	Edge *edge = graph->edge;
	
	struct subset *subsets = new subset[v];
	
	for (int i = 0; i < vertices; i++){
		subsets[i].parent = i;
		subsets[i].rank = 0;
	}
	
	while (vertices > 2){
		int i = rand() % edges;
		int primary = find(subsets, edge[i].source);
		int secondary = find(subsets, edge[i].destination);
		
		if (primary == secondary){
			continue;
		} else{
			vertices--;
			join(subsets, primary, secondary);
		}
	}

	int edgecuts = 0;
	
	for (int i = 0; i < edges; i++){
		int primary = find(subsets, edge[i].source);
		int secondary = find(subsets, edge[i].destination);
		
		if (primary != secondary){
			edgecuts++;
		}
	}
	
	return edgecuts;
}

int find(struct subset subsets[], int i){
	if (subsets[i].parent != i){
		subsets[i].parent = find(subsets, subsets[i].parent);
	}
	
	return subsets[i].parent;
}

int join(struct subset subsets[], int x, int y){
	int xorigin = find(subsets, x);
	int yorigin = find(subsets, y);
	
	if (subsets[xorigin].rank < subsets[yorigin].rank){
		subsets[xorigin].parent = yorigin;
	} else if (subsets[xorigin].rank > subsets[yorigin].rank){
		subsets[yorigin].parent = xorigin;
	} else{
		subsets[yorigin].parent = xorigin;
		subsets[xorigin].rank++;
	}
}

struct Graph *create(int vertices, int edges){
	Graph *graph = new Graph;
	graph->vertices = vertices;
	graph->edges = edges;
	graph->edge = new Edge[edges];
	
	return graph;
}