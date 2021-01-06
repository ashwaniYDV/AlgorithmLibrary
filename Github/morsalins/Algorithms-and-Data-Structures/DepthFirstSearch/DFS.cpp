#include<stdio.h>
#include<conio.h>

#define WHITE 0
#define GRAY 1
#define BLACK 2

void DFS_VISIT(int);

int graph[100][100],colour[100],nodes; //d[100],f[100],time=1;


int main()
{
	freopen("i.txt", "r", stdin);
	freopen("o.txt","w", stdout);
	int edges,start,end,i,j;

	printf("how many nodes : ");
	scanf("%d", &nodes);
	printf("how many edges : ");
	scanf("%d", &edges);

	for(i=1;i<=edges;i++){
		scanf("%d %d", &start, &end);
		graph[start][end]=1;
	}

	for(i=1;i<=nodes;i++)
		colour[i]=WHITE;
	/***Intialing every vertex as unvisited***/

	printf("\n\nDFS Traversal : ");

	for(i=1;i<=nodes;i++){
		if( colour[i] == 0 )
			DFS_VISIT(i);
	}

/*	printf("\n\n\nVERTEX   Dis. Time   Fin. Time\n");
	for(i=1;i<=nodes;i++)
		printf("   %2d %20d %20d\n", i,d[i],f[i]); */
	return 0;
}

void DFS_VISIT(int u)
{
	colour[u]=GRAY;
	//d[u]=time;
	//time++;
	printf(" %d", u);


		for(int v=1;v<=nodes;v++){
			if(graph[u][v]){
				if( !colour[v] )    // If Vertex v is WHITE or 0 or unvisited.
					DFS_VISIT(v);
			}
		}


	colour[u]=BLACK;
	//f[u]=time;
	//time++;

	return;
}
