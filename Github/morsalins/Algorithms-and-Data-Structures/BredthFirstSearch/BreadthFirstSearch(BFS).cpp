#include<cstdio>
#include<cstdlib>
#include<conio.h>

using namespace std;

#define SIZE 100
#define WHITE 0
#define GRAY 1
#define BLACK 2
#define NIL 0

int graph[SIZE][SIZE], color[SIZE], distance[SIZE], parent[SIZE], queue[SIZE];
int front=0, rear=-1;

void initialize(int, int);
void enqueue(int);
int dequeue(void);
void BFS(int);

int main()
{
	freopen("i.txt", "r", stdin);
	//freopen("o.txt", "w", stdout);
	
	int nodes, edges, source, u, v;

	printf("How many noeds: ");
	scanf("%d", &nodes);
	
	printf("How many edges: ");
	scanf("%d", &edges);

	printf("%c%2c\n",'U','V');
	printf("- -\n");
	
	for(int edge=1;edge<=edges;edge++){
		scanf("%d%d", &u, &v);
		graph[u][v]=1;
		graph[v][u]=1;
	}

	printf("Enter source: ");
	scanf("%d", &source);
	
	initialize(nodes,source);
	enqueue(source);
	

	printf("\nBFS Traversal: %d ", source);
	BFS(nodes);

	printf("\n\n\nPress any key to QUIT ..............");
	getch();
	return 0;
}

void initialize(int nodes, int source){
	for(int node=1;node<=nodes;node++){
			color[node] = WHITE;
			distance[node] = NIL;
			parent[node] = node;
	}
	
	color[source] = GRAY;
	distance[source] = NIL;
	parent[source] = source;

	return ;
}

void BFS(int nodes){
		
	while(front<=rear){
			
		int u = dequeue();
		
		for(int v=1; v<=nodes; v++){
			if(graph[u][v]){
				if(color[v] == WHITE){
					color[v] = GRAY;
					distance[v] = distance[u] + 1;
					parent[v] = u;
					enqueue(v);
					printf("%d ", v);
				}
			}
		}
		
		color[u] = BLACK;
	}
	
	printf("\n");
	return ;
}

void enqueue(int data){
	if(rear==SIZE){
		printf("Error!!!!!Queue Overflow. Can't continue the process.\nPress any key to return......");
		getch();
		exit(0);
	}

	queue[++rear] = data;

	return;
}

int dequeue(){
	if(front>rear){
		return 0;
	}

	int data = queue[front];
	queue[front++] = 0;

	return data;
}