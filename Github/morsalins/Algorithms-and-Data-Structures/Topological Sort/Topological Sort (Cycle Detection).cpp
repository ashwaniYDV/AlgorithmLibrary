#include <cstdio>
#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>

using namespace std;

#define MAX 200

vector <int> graph[MAX+5];
int Start[MAX+5], End[MAX+5];
int time = 1;

bool find_cycle(int);

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

	int node = 1; // start from the 1st node. suppose here 1st node is 1 

	memset( Start, -1, sizeof Start); 
	memset( End, -1, sizeof End);

	if( find_cycle(node) )
		cout << "Error!!! Cycle Found.\n" ;
	else 
		cout << "No Cycle Found.\n";

	return 0;
}

bool find_cycle (int u){

	Start[u] = time++;

	for(int i=0; i<graph[u].size(); i++){
		
		int v = graph[u][i];

		if( Start[v] != -1 && End[v] == -1 ) // if cycle found return true
			return true;

		if( End[v]==-1 )
			if( find_cycle(v) )
				return true;
	}

	End[u] = time++;

	return false;
}