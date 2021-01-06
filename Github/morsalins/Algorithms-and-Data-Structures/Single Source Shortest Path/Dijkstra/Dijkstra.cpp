#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

#define MAX 100
#define pii pair<int, int>
#define INF 0x7f7f7f7f

vector <pii> G[MAX+5];
priority_queue < pii, vector <pii>, greater<pii> > PQ;

int dist[MAX+5];

void dijkstra(int);

int main()
{
	//freopen("in.txt", "r", stdin);

	int nodes, edges, u, v, w, source;

	printf("How many nodes: ");
	cin >> nodes;
	
	printf("How many edges: ");
	cin >> edges;

	printf("Enter edges & cost (u v w):\n");
	
	for(int i=1; i<=edges; i++){	

		cin >> u >> v >> w;

		G[u].push_back( pii(v, w) );
		
		// G[v].push_back( pii(u, w) );   // Only for bi-directional Graph
	}

	printf("Enter Source: ");
	cin >> source;

	memset(dist, INF, sizeof dist);

	dijkstra(source);

	/*** print the output or do what needed ***/

	return 0;
}

void dijkstra(int source){

	PQ.push( pii(0, source) ); // *** first keep cost, second keep node. For a better compare. VERY IMPORTANT *** //
	dist[source]= 0;

	while ( !PQ.empty() ){

		int u = PQ.top().second;
		int w = PQ.top().first;
		PQ.pop();

		//if( w>= dist[u] ) continue;

		for(int i=0; i<G[u].size(); i++){

			int v = G[u][i].first;
			w = G[u][i].second;

			if( dist[v] > dist[u]+w ){
				dist[v] = dist[u]+w;
				PQ.push( pii(dist[v], v) );
			}
		}
	}

	return;
}