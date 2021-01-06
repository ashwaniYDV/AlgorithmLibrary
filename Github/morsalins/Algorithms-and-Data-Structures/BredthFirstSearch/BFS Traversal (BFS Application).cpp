/* This is a simple code of BFS traversal.
 * To find the travers sequence we use a simple BFS implement
 * Here vector graph is used to store the graph (from input)
 * array visited just mark the nodes wheather it is already visited or not.
 * And vector travers is used to store the output.... that means it is storing the travesal sequence..
*/

#include<cstdio>
#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
#include<algorithm>

using namespace std;

#define MAX 1000
#define SET(a, b) memset( a, b, sizeof a )

void BFS (int, int);

vector <int> graph[MAX];
vector <int> travers;
bool visited[MAX];

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

	SET(visited, false);

	BFS(nodes, source);

	printf("\n\nBFS Traversal:\n");
	for(int i=0; i<travers.size(); i++)
		cout << travers[i] << " ";

	printf("\nPress any key to quit.....");
	getchar();
	return 0;
}

void BFS (int nodes, int source){

	queue <int> Q;
	
	Q.push(source);
	visited[source] = true;
	travers.push_back(source);

	while( !Q.empty() ){

		int u = Q.front();
		int len = graph[u].size();

		for(int i=0; i<len; i++){
			
			int v = graph[u][i];

			if( !visited[v] ){

				visited[v] = true;
				travers.push_back(v);
				Q.push(v);
			}
		}

		Q.pop();
	}

	return;
}