/*
Prim's MST Algorithm
--------------------
Prim's algorithm is a greedy algorithm that finds a minimum spanning 
tree for a weighted undirected graph. This means it finds a subset of 
the edges that forms a tree that includes every vertex, where the total 
weight of all the edges in the tree is minimized. The algorithm operates 
by building this tree one vertex at a time, from an arbitrary starting 
vertex, at each step adding the cheapest possible connection from the 
tree to another vertex.
--------------------
Time Complexity : O((m+n)*logn)
Space Complexity : O(n)
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n;

struct node{
	vector<int> adjacency;
	vector<int> weights;
};

struct node graph[100];
bool discovered[100];

struct edge{
	int start, end;
	double weight;
	bool operator <(const edge &a) const{
		return (weight > a.weight);
	}
};

priority_queue<edge> subgraph;

int prim(){
	int external = 0, returned = 0, count = 0;
	while (count < n - 1){
		discovered[external] = true;
		for (int i = 0; i < graph[external].adjacency.size(); i++){
			if (not discovered[graph[external].adjacency[i]]){
				edge e;
				e.start = external;
				e.end = graph[external].adjacency[i];
				e.weight = graph[external].weights[i];
				subgraph.push(e);
			}
		}
		while (not subgraph.empty()){
			edge e = subgraph.top();
			subgraph.pop();
			if (not discovered[e.end]){
				returned += e.weight;
				external = e.end;
				count++;
				break;
			}
		}
	}
	return returned;
}