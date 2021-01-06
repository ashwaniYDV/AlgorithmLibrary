/* 
 
 * This is a simple implementation of BFS.
 * vector graph is storing the graph (from input).
 * array visited is marking a node wheather it is visited  or not.
 * array Distance is storing each node's distance from source. In another word 
 * the level of each nodes. Suppose we need to know whath is the distance or level of node 2.
 * The answer lies in Distance[2] ;) ......................... BUT
 * if we want to know how many nodes are there in level 2 ... or level 3 ... or any level ...
 * To know that answer we are using a 2D vector named level.
 * Each specific row of 2D vector level is containig the nodes of that specific level.
 * That means if nodes 3,5,7,9 are at level 2 then ..... the row number 2 of 2D vector level is containing that nodes
 *........ level[2] -> 3 -> 5 -> 7 -> 9.......

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
bool visited[MAX];
int Distance[MAX];
vector <int> level[MAX];

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
	SET(Distance, 0);

	BFS(nodes, source);

	// Now visited array, Distance array and 2D vector level is updated after BFS Call.
	//The are now containing the BFS results as their job.
	//Now use these containers to do the necessary things that need to do .... print it or anything......

	getchar();
	return 0;
} 

void BFS(int nodes, int source){

	queue <int> Q;

	Q.push(source);
	visited[source] = true;
	Distance[source] = 0;
	level[0].push_back(source);

	while( !Q.empty() ){

		int u = Q.front();
		int len = graph[u].size();

		for(int i=0; i<len; i++){
			
			int v = graph[u][i];

			if( !visited[v] ){
				
				Distance[v] = Distance[u]+1;
				level[ Distance[v] ].push_back(v);
				visited[v] = true;
				Q.push(v);
			}
		}

		Q.pop();
	}

	return;
}