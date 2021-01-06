/*
Kosaraju's Algorithm
--------------------
Kosaraju's algorithm is a linear time algorithm to find the 
strongly connected components of a directed graph. It makes 
use of the fact that the transpose graph (the same graph with
the direction of every edge reversed) has exactly the same 
strongly connected components as the original graph.
--------------------
Time Complexity : O(n+m)
Space Complexity : O(n)
*/

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

static int n, m;

struct node{
	vector<int> adjacency;
	vector<int> reverse;
};

node graph[10000];
bool discovered[10000];
stack<int> s;
int component[10000];
vector<int> components[10000];
int num_components;

void dfs1(int x){
	discovered[x] = true;
	for (int i = 0; i < graph[x].adjacency.size(); i++){
		if (!discovered[graph[x].adjacency[i]])
			dfs1(graph[x].adjacency[i]);
	}
	s.push(x);
}

void dfs2(int x){
	cout << x;
	component[x] = num_components;
	components[num_components].push_back(x);
	discovered[x] = true;
	for (int i = 0; i < graph[x].reverse.size(); i++){
		if (!discovered[graph[x].reverse[i]])
			dfs2(graph[x].reverse[i]);
	}
}

void kosaraju(){
	for (int i = 0; i < n; i++){
		if (!discovered[i])
			dfs1(i);
	}
	for (int i = 0; i < n; i++){
		discovered[i] = false;
	}
	while (!s.empty()){
		int v = s.top();
		s.pop();
		if (!discovered[v]){
			cout << "Component " << num_components << ": ";
			dfs2(v);
			num_components++;
			cout << endl;
		}
	}
}