/*
Dinic's Algorithm
-----------------
Dinic's Algorithm is a strongly polynomial algorithm for computing
the maximum flow in a flow network. It showed that in the 
Ford–Fulkerson Algorithm, if each augmenting path is the shortest 
one, then the length of the augmenting paths is non-decreasing the 
algorithm always terminates.
-----------------
Time Complexity : O(m*(n^2))
Space Complexity : O(n^2)
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct node{
	vector<int> adjacency;
};

struct edge{
	int source;
	int sink;
	int capacity;
	int flow;
};

node graph[10000];
vector<edge> edge_graph;
int distance[10000];
int parent[10000];
int vertices, edges, source, sink;
int idd = 0;

bool bfs(){
	for (int i = 1; i <= vertices; i++){
		distance[i] = -1;
	}
	queue<int> v;
	v.push(source);
	distance[source] = 0;
	while (!v.empty()){
		int temp = v.front();
		v.pop();
		for (int i = 0; i < graph[temp].adjacency.size(); i++){
			int current_id = graph[temp].adjacency[i];
			int local_sink = edge_graph[current_id].sink;
			if (distance[local_sink] == -1 and edge_graph[current_id].flow < edge_graph[current_id].capacity){
				v.push(local_sink);
				distance[local_sink] = distance[temp] + 1;
			}
		}
	}
	return (distance[sink] != -1);
}

int dfs(int temp, int min_capacity){
	if (min_capacity == 0){
		return 0;
	}
	if (temp == sink){
		return min_capacity;
	}
	while (parent[temp] < graph[temp].adjacency.size()){
		int current_id = graph[temp].adjacency[parent[temp]];
		int local_sink = edge_graph[current_id].sink;
		if (distance[local_sink] != distance[temp] + 1){
			parent[temp]++;
			continue;
		}
		int augment = dfs(local_sink, min(min_capacity, edge_graph[current_id].capacity - edge_graph[current_id].flow));
		if (augment > 0){
			edge_graph[current_id].flow += augment;
			if (current_id & 1){
				current_id--;
			} else{
				current_id++;
			}
			edge_graph[current_id].flow -= augment;
			return augment;
		}
		parent[temp]++;
	}
	return 0;
}

int dinic(){
	int flow = 0;
	while (true){
		if (!bfs()){
			break;
		}
		for (int i = 1; i <= vertices; i++){
			parent[i] = 0;
		}
		while (true){
			int current_flow = dfs(source, 999999999);
			if (current_flow == 0){
				break;
			}
			flow += current_flow;
		}
	}
	return flow;
}

void add_edge(int source, int sink, int capacity){
	edge e1, e1;
	
	e1.source = source;
	e1.sink = sink;
	e1.capacity = capacity;
	e1.flow = 0;
	e2.source = sink;
	e2.sink = source;
	e2.capacity = 0;
	e2.flow = 0;

	graph[source].adjacency.push_back(idd++);
	edge_graph.push_back(e1);
	graph[sink].adjacency.push_back(idd++);
	edge_graph.push_back(e2);
}