#include <cstdio>
#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>

using namespace std;

#define MAX 200

vector <int> graph[MAX+5];
stack <int> S;
bool visited[MAX+5];

void DFS (int);

int main()
{
	int nodes, edges, u, v;

	printf("How many nodes: ");
	cin >> nodes;
	
	printf("How many edges: ");
	cin >> edges;

	printf("Enter edges (u v):\n");
	
	for(int i=1; i<=edges; i++){

		cin >> u >> v;

		graph[u].push_back(v);
	}

	for(int i=1; i<=nodes; i++){
		if( !visited[i] )
			DFS(i);
	}

	while( !S.empty() ){

		cout << S.top() << " ";
		S.pop();
	}

	return 0;
}

void DFS (int u){

	visited[u] = true;

	for(int i=0; i<graph[u].size(); i++){

		int v = graph[u][i];
		if( !visited[v] )
			DFS(v);
	}

	S.push(u);

	return;
}