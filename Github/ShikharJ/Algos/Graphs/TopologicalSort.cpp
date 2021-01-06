/*
Topological Sort Algorithm
----------------------------
A topological sort is a linear ordering of its vertices such that 
for every directed edge uv from vertex u to vertex v, u comes 
before v in the ordering. A topological ordering is possible if 
and only if the graph is a directed acyclic graph (DAG).
----------------------------
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

node graph[10000];
bool discovered[10000];
int indegree[10000];
int toposort[10000];

static int n;

int topological(){
	queue<int> v;
	for (int i = 0; i < n; i++){
		if (indegree[i]	== 0){
			v.push(i);
		}
	}
	int id = 0;
	while (!v.empty()){
		int temp = v.front();
		v.pop();
		toposort[id++] = temp;
		for (int i = 0; i < graph[temp].adjacency.size(); i++){
			if (--indegree[graph[temp].adjacency[i]] == 0){
				v.push(graph[temp].adjacency[i]);
			}
		}
	}
	if (id < n){
		return -1;
	} else{
		return 0;
	}
}