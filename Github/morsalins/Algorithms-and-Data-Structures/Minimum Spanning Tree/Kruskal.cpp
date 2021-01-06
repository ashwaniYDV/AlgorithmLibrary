#include <stdio.h>
#include <conio.h>

int parent[50];

void Make_set (void);
int Find_set(int);
void Union(int, int);

int main()
{
	freopen("i.txt" , "r" , stdin);
	//freopen("o.txt" , "w" , stdout);
	int start[50] ,end[50], edge[50],nodes,edges,i,j=0,k,l,temp,cost=0;

	printf("How many nodes : ");
	scanf("%d", &nodes);

	printf("How many edges: ");
	scanf("%d",&edges);

	printf("\n\nS E EDGES\n");
	printf("- - -----\n");

	for(i=0;i<edges;i++){
		scanf("%d %d %d", &start[i], &end[i], &edge[i]);
	}

	for(i=0;i<edges-1;i++){
		for(j=0;j<(edges-i)-1;j++){
			if(edge[j]>edge[j+1]){

				temp = edge[j];
				edge[j]=edge[j+1];
				edge[j+1]=temp;
				/***Sorting the Edges***/

				temp = start[j];
				start[j]=start[j+1];
				start[j+1]=temp;

				temp = end[j];
				end[j]=end[j+1];
				end[j+1]=temp;
				/*Sorting the Vertices(Start & End) based on Edges*/
			}
		}
	}
	Make_set();

	printf("\n\n\n VERTICES   EDGE\n");
	printf("---------- ------\n");
	for(i=0;i<edges;i++){
		if( Find_set(start[i]) != Find_set(end[i]) ){
			printf("%d --> %d  = %4d\n", start[i],end[i],edge[i]);
			cost = cost + edge[i];
			Union(start[i], end[i]);
		}
	}

	printf("\n\nMinimum Cost : %d\n", cost);

	getch();
	return 0;
}
/************End of Main************/

void Make_set(void){
	int i;
	for(i=0;i<50;i++){
		parent[i]=i;
	}
	return ;
}
/************End of Make_set************/


int Find_set(int x){

	if(x==parent[x])
		return x;
	else
		return parent[x]=Find_set(parent[x]);

	/*while(x!=parent[x]){
		x=parent[x];
	}
	return x;*/
}
/************End of Find_set************/

void Union(int x,int y){
	int rootx,rooty;

	rootx=Find_set(x);
	rooty=Find_set(y);

	if(rootx==rooty)
		return ;
	else{
		parent[rootx]=rooty;
	}
	return ;
}
/************End of Union************/
