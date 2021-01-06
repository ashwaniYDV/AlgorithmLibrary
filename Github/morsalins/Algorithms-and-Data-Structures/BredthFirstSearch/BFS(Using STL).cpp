#include<cstdio>
#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
#include<algorithm>

using namespace std;

#define MAX 1000
#define SET(a, b) memset( a, b, sizeof(a) )

void BFS(int, int);

vector <int> graph[MAX];
bool visited[MAX];
int Distance[MAX];

int main()
{
	int nodes, edges, source;

	printf("How many nodes: ");
	cin >> nodes;

	printf("How many edges: ");
	cin >> edges;

	printf("Enter the edges (u & v): \n");

	for(int i=1; i<=edges; i++){

		int u, v;
		printf("Edge %d: ", i);
		cin >> u >> v;

		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	printf("Enter the source: ");
	cin >> source;

	SET(Distance, 0);
	SET(visited, false);

	BFS(nodes, source);

	printf("\nSo distance from source nodes %d to other nodes: \n", source);
	for(int i=1; i<=nodes; i++){
        printf("%d -> %d: %d\n", source, i, Distance[i]);
	}

	getchar();
	return 0;
}

void BFS (int nodes, int source){

	queue <int> Q;

	Q.push(source);
	Distance[source] = 0;
	visited[source] = true;

	while( !Q.empty() ){

		int u = Q.front();
		int len = graph[u].size();

		for(int i=0; i<len; i++){

			int v = graph[u][i];

			if( !(visited[v]) ){

				Distance[v] = Distance[u]+1;
				visited[v] = true;
				Q.push(v);
			}
		}

		Q.pop();
	}

	return;
}
