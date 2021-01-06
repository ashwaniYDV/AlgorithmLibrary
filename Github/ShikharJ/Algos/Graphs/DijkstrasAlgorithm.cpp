/*
Dijkstra's Algorithm
--------------------
Dijkstra's algorithm is an algorithm for finding the 
shortest paths between nodes in a graph, which may 
represent, for example, road networks. For a given 
source node in the graph, the algorithm finds the 
shortest path between that node and every other. It 
can also be used for finding the shortest paths from
a single node to a single destination node by stopping 
the algorithm once the shortest path to the destination 
node has been determined.
--------------------
Time Complexity : O((m+n)*logn)
Space Complexity : O(n+m)
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

static int n;

struct node{
	int distance;
	vector<int> adjacency;
	vector<int> weight;
};

node graph[10000];
bool discovered[10000];

struct entry{
	int node;
	int distance;
	bool operator <(const entry &a) const{
		if (distance != a.distance)
			return distance > a.distance;
		return node > a.node;
	}
};

void dijkstra(int source){
	priority_queue<entry> v;
	entry p;
	for (int i = 0; i < n; i++){
		if (i == source){
			graph[i].distance = 0;
			p.node = i;
			p.distance = 0;
			v.push(p);
		}
		else{
			graph[i].distance = 999999999;
		}
	}
	while (!v.empty()){
		entry current = v.top();
		v.pop();
		int node = current.node;
		int distance = current.distance;
		for (int i = 0; i < graph[node].adjacency.size(); i++){
			if (!discovered[graph[node].adjacency[i]]){
				int nextnode = graph[node].adjacency[i];
				if (distance + graph[node].weight[i] < graph[nextnode].distance){
					graph[nextnode].distance = distance + graph[node].weight[i];
					p.node = nextnode;
					p.distance = graph[nextnode].distance;
					v.push(p);
				}
			}
		}
		discovered[node] = true;
	}
}
