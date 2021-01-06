#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

#define MAX 1000

struct edge{

	int u, v, w;
};

typedef struct  edge E;

int parents[MAX+5];
vector <E> graph; // Store the inputted graph (u, v, w).
vector <E> selected_edges; // Store the edges which is selected for the MST from given graph.

bool comp( const E&, const E& );
void make_set(int);
int findParent(int);
int Kruskal_MST(int);

int main()
{
	E getEdge;
	int nodes, edges;

	printf("How many nodes: ");
	cin >> nodes;

	printf("How many edges: ");
	cin >> edges;

	printf("Enter 2 nodes & their costs (u v & w): \n");
	
	for(int i=1; i<=edges; i++){

		int u, v, w;
		printf("Edge %d: ", i);
		cin >> u >> v >> w;

		getEdge.u = u; getEdge.v = v; getEdge.w = w;
		graph.push_back(getEdge);
	}

	int totalCost = Kruskal_MST(nodes); 
	
	printf("\n\nSelected Edges and their costs: \n");
	
	for(int i=0; i<selected_edges.size(); i++){
		printf("Edge %d: %d -> %d : cost %d\n", i+1, selected_edges[i].u, selected_edges[i].v, selected_edges[i].w);
	}

	printf("\nTotal Costs: %d\n", totalCost);

	getchar();
	return 0;
}

bool comp (const E& l, const E& r){

	return l.w < r.w;
}

int Kruskal_MST (int nodes){

	make_set(nodes);

	sort(graph.begin(), graph.end(), comp);

	int edgeCounter=0, totalCost=0;

	int len = graph.size();
	
	for(int i=0; i<len; i++){

		int parent_of_u = findParent( graph[i].u );
		int parent_of_v = findParent( graph[i].v );

		if( parent_of_u != parent_of_v ){

			parents[ parent_of_u ] = parent_of_v;
			totalCost += graph[i].w;
			selected_edges.push_back( graph[i] );

			edgeCounter++;
			if( edgeCounter == nodes-1 )
				break;
		}

	}

	return totalCost;
}

void make_set(int nodes){

	for(int i=1; i<=nodes; i++)
		parents[i] = i;

	return;
}

int findParent( int r ){

	if( r == parents[r] ) return r;

	return parents[r] = findParent( parents[r] );
}