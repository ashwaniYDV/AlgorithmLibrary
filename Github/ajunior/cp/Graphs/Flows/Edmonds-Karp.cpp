/*O(VE²)*/

#include <bits/stdc++.h>

const int MAXV = 10010;
const int INF = (int)1e9;

using namespace std;

int s, t; /*Vértice de saída e vértice de destino respectivamente*/
int flow, maxFlow; /*Fluxo auxiliar, Fluxo Máximo respectivamente*/
int p[MAXV]; /*Vetor que armazena o vértice antecessor de cada vértice em um caminho de s a t*/
int mat[MAXV][MAXV]; /*Matriz de adjacência*/
bool mark[MAXV]; /*Vetor que controla o acesso aos vértices, prevenindo que um vértice seja visitado apenas uma vez*/

void augment(int v, int minEdge){ /*Função responsável por calcular o fluxo máximo de um caminho qualquer entre s e t*/
	if(v == s){                   /*tal fluxo será o valor da aresta de valor mínimo entre esse caminho. Além disso essa função*/
		flow = minEdge;           /*é responsável por adicionar o fluxo máximo desse caminho na aresta de retorno e subatraí-lo da*/
		return;                   /*sua aresta correspondente que esteve no caminho de s a t*/
	}else if(p[v] != -1){
		augment(p[v], min(minEdge, mat[p[v]][v]));
		mat[p[v]][v] -= flow;
		mat[v][p[v]] += flow;
	}
}

/*O fator de utilizar BFS ao invés de DFS diminui a complexidade de tempo do algoritmo que antes era calculada 
**em função do fluxo máximo, inviávels em casos onde o fluxo máximo fosse muito grande. Tudo isso devido ao 
**fato da BFS realizar a busca em camadas*/

void edmonds_karp(int V){
	
	maxFlow = 0;
	
	/*Enquanto houver fluxo para ser mandado, faça mais BFS's*/
	while(true){
		flow = 0;
		queue <int> q;
		
		for(int i = 0; i < V; i++){
			mark[i] = false;
			p[i] = -1; 
		}
		
		mark[s] = true;
		q.push(s);
		
		while(!q.empty()){
			int u = q.front();
			q.pop();
			
			if(u == t) break;
			
			for(int i = 0; i < V; i++){
				if(mat[u][i] > 0 && !mark[i]){ 
					p[i] = u;
					mark[i] = true;
					q.push(i);
				}
			}
		}
		
		augment(t, INF);
		
		if(!flow) break;
		
		maxFlow += flow;
	}
}

int main(){
	
	return 0;
}
