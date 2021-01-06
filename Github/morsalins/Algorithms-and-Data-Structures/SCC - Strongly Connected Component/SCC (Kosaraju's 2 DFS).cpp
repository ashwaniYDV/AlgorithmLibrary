#include <cstdio>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

#define MAX 100

vector <int> G[MAX+5];
vector <int> T[MAX+5];
stack <int> S;

int SCC[MAX+5];
int cntSCC=1;
bool visited[MAX+5];

void DFS_Visit(int);
void DFS_getSCC(int);

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

		G[u].push_back(v);
		T[v].push_back(u);
	}

	memset( visited, false, sizeof visited );
	memset( SCC, 0, sizeof SCC );

	for(int i=1; i<=nodes; i++)
		if( !visited[i] )
			DFS_Visit(i);
	
	memset( visited, false, sizeof visited );

	while( !S.empty() ){
		
		int u = S.top();
		S.pop();

		if( !visited[u] ){
			DFS_getSCC(u);
			cntSCC++;
		}
	}

	return 0;
}

void DFS_Visit(int u){

	visited[u] = true;

	for(int i=0; i<G[u].size(); i++){
		int v = G[u][i];
		if( !visited[v] )
			DFS_Visit(v);
	}

	S.push(u);

	return;
}

void DFS_getSCC(int u){

	visited[u] = true;
	
	SCC[u] = cntSCC; // storing the SCC of each nodes. this could be used as ans. 

	//**** Sotre the desired ans in a output container here. ****//

	for(int i=0; i<T[u].size(); i++){

		int v = T[u][i];
		if( !visited[v] )
			DFS_getSCC(v);
	}

	return;
}
