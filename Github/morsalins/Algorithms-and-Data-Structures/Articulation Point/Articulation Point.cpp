#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define MAX 1000

void DFS (int, int);  // paremeter: node, parent of node.

vector <int> G[MAX];
int visit_time[MAX], low_time[MAX];
bool isCut[MAX];
int timer;

int main()
{
	int nodes, edges, u, v;

	printf("How many nodes: "); scanf("%d", &nodes);
	printf("How manu edges: "); scanf("%d", &edges);

	printf("Enter edges (u v): \n");

	for(int i=1; i<=edges; i++){
		scanf("%d %d", &u, &v);
		G[u].push_back(v);
		G[v].push_back(u);
	}

	memset( visit_time, 0, sizeof visit_time );
	memset( low_time, 0, sizeof low_time );
	memset( isCut, false, sizeof isCut );
	timer = 1;

	DFS(1, -1); // paremeter: source, parent of source.

	return 0;
}

void DFS (int u, int par){

	int cnt = 0;
	visit_time[u] = low_time[u] = timer++;

	for(int i=0; i<G[u].size(); i++){

		int v = G[u][i];
		if( v==par ) continue; 
		
		if( visit_time[v] ) low_time[u] = min( low_time[u], visit_time[v] ); 
		// If v is already visited then update the low_time of u.
		else{
			DFS(v, u);     // if v is not visited then call DFS with it and it's parent u.
			low_time[u] = min( low_time[u], low_time[v] );     // After return update the low_time of u.
			if( par!=-1 && low_time[v]>=visit_time[u] ) isCut[u] = true;
			// if u is not root then check wheather it is Articulation point or not. if it is then mark it true.
			cnt++;
		}
	}

	if( par==-1 && cnt>1 ) isCut[u] = true; // if u is root and Articulation point then mark it as true;

	return;
}