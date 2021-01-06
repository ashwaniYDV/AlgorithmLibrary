#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include<conio.h>

using namespace std;

#define MAX 200

vector <int> graph[MAX+5];
vector <int> Topological_list;
int indegree[MAX+5];
bool cycle_found = false;

void topological_sort(int, int);

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

		indegree[v]++;
		graph[u].push_back(v);
	}

	topological_sort(edges, nodes);

	if( cycle_found ) printf("ERROR!!! Cycle Found.\n");
	else {
		for(int i=0; i<Topological_list.size(); i++)
			cout << Topological_list[i] << " ";

		cout << endl;
	}

	getch();
	return 0;
}

void topological_sort (int edges, int nodes){

	queue <int> Q;
	int cnt = 0;

	for(int i=1; i<=nodes; i++){
		if(indegree[i]==0)
			Q.push(i);
	}

	while ( !Q.empty() ){

		int u = Q.front();
		Topological_list.push_back(u);
		cnt++;

		for(int i=0; i<graph[u].size(); i++){

			int v = graph[u][i];
			indegree[v]--;

			if( indegree[v]==0 )
				Q.push(v);
		}

		Q.pop();
	}

	if( cnt<nodes ) cycle_found = true;
	else cycle_found = false;

	return;
}
