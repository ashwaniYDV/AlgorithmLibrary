/*
Breadth First Search Algorithm
------------------------------
Breadth-first search (BFS) is an algorithm for traversing or 
searching tree or graph data structures. It starts at the tree 
root (or some arbitrary node of a graph, sometimes referred to
as a 'search key') and explores the neighbor nodes first, 
before moving to the next level neighbors.
------------------------------
Time Complexity : O(n+m)
Space Complexity : O(n)
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct node{
	vector<int> adjacency;
};

struct node graph[10000];
bool discovered[10000] = {};

void bfs(int source){
	queue<int> v;
	v.push(source);
	while(!v.empty()){
		int temp = v.front();
		v.pop();
		discovered[temp] = true;
		for (int i = 0; i < graph[temp].adjacency.size(); i++){
			if (!discovered[graph[temp].adjacency[i]]){
				v.push(graph[temp].adjacency[i]);
				discovered[graph[temp].adjacency[i]] = true;
			}
		}
	}
}
