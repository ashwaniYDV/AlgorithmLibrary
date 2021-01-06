/*
Edmonds-Karp Algorithm
----------------------
The Edmonds–Karp algorithm is an implementation of the Ford–Fulkerson
method for computing the maximum flow in a flow network. The algorithm 
is identical to the Ford–Fulkerson algorithm, except that the search 
order when finding the augmenting path is defined. This can be found 
by a breadth-first search, as we let edges have unit length.
----------------------
Time Complexity : O((m^2)*n)
Space Complexity : O(n^2)
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
int residual_graph[10000][10000];
int parent[10000];
int vertices, edges, source, sink;

int bfs(){
	int local_flow = 0;
	queue<int> v;
	queue<int> min_capacity;
	for (int i = 1; i <= vertices; i++){
		parent[i] = 0;
	}
	parent[source] = -1;
	v.push(source);
	min_capacity.push(999999999);
	while(!v.empty()){
		int temp = v.front();
		int capacity = min_capacity.front();
		v.pop();
		min_capacity.pop();
		discovered[temp] = true;
		for (int i = 0; i < graph[temp].adjacency.size(); i++){
			if (residual_graph[temp][graph[temp].adjacency[i]] > 0 and parent[graph[temp].adjacency[i]] == 0){
				v.push(graph[temp].adjacency[i]);
				min_capacity.push(min(capacity, residual_graph[temp][graph[temp].adjacency[i]]));
				parent[graph[temp].adjacency[i]] = temp;
				if (graph[temp].adjacency[i] == sink){
					local_flow = min(capacity, residual_graph[temp][graph[temp].adjacency[i]]);
					break;
				}
			}
		}
	}
	if (local_flow > 0){
		int current_node = sink;
		while (current_node != source){
			residual_graph[parent[current_node]][current_node] -= local_flow;
			residual_graph[current_node][parent[current_node]] += local_flow;
			current_node = parent[current_node];
		}
	}
	return local_flow;
}

int edmondskarp(){
	int flow = 0;
	while (true){
		int current_flow = bfs();
		if (current_flow == 0){
			break;
		} else{
			flow += current_flow;
		}
	}
	return flow;
}