#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

#define MAX 3
#define I64 long long int
#define INF 0x7f7f7f7f

vector <int> G[MAX+5];
I64 Dist[MAX+5][MAX+5];
int Path[MAX+5][MAX+5];

int main()
{
	freopen("in.txt", "r", stdin);
	int nodes, edges, u, v, w, source;

	printf("How many nodes: ");
	cin >> nodes;
	
	printf("How many edges: ");
	cin >> edges;

	memset(Dist, 126, sizeof Dist);
	memset(Path, -1, sizeof Path);

	printf("Enter edges & cost (u v w):\n");

	for(int i=1; i<=edges; i++){
		cin >> u >> v >> w;
		Dist[u][v] = w;
		Path[u][v] = u;
		//Dist[v][u] = w; // For Bi-directional Graph
	}

	for(int k=0; k<nodes; k++){
		for(int i=0; i<nodes; i++){
			for(int j=0; j<nodes; j++){
				if( i!=j && (Dist[i][k]<INF && Dist[k][j]<INF) ){
					if( Dist[i][j] > Dist[i][k]+Dist[k][j] ){
						Dist[i][j] = Dist[i][k]+Dist[k][j];
						Path[i][j] = Path[k][j];
					}
				}
			}
		}
	}
	
	return 0;
}