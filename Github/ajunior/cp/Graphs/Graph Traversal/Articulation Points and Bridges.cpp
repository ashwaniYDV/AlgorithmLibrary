/*Encontrado pontos de articulação e pontes em um grafo não direcionado
**com O(V + E) DFS*/

#include <bits/stdc++.h>

const int MAXV = 100010;

using namespace std;

int dfsRoot, rootChildren, dfsCount;
/*raiz da DFS, número de filhos da raiz, contador de visitação*/ 
bool articulationPoint[MAXV];
/*pontos de articulação*/
int num[MAXV], low[MAXV];
/*momento de primeira visitação e menor visitação*/
vector <int> adj[MAXV];

/*Union-Find*/
int id[MAXV], rk[MAXV];

int find_set(int x){
	if(id[x] == x) return x;
	return id[x] = find_set(id[x]);
}

void union_set(int x, int y){
	x = find_set(x), y = find_set(y);
	
	if(x != y){
		if(rk[x] > rk[y]){
			rk[x] += rk[y];
			id[y] = x;
		}else{
			rk[y] += rk[x];
			id[x] = y;
		}
	}
}
/*Union-Find*/

void dfs(int u, int p){
	num[u] = low[u] = dfsCount++; //Primeira visitação, lembre-se que low[u] <= num[u]
	
	for(int i = 0; i < (int)adj[u].size(); i++){
		int v = adj[u][i];
		
		if(num[v] == -1){ //Aresta de árvore
			if(u == dfsRoot) rootChildren++; //O caso da raiz
			
			dfs(v, u);
			
			if(low[v] >= num[u]) //Se isso acontecer é porquê não á outro caminho de um vértice qualquer w até v que não passe por u
				articulationPoint[u] = true;
			if(low[v] > num[u]) //Retiramos o sinal de igual pelo fato de aresta de ciclo não serem pontes
				union_set(u, v);
			
			low[u] = min(low[u], low[v]); //Atualizamos o low[u] com o low[v];
		}else if(v != p)
			low[u] = min(low[u], num[v]); //Atualizamos o low[u] com o num[v];
	}
}

int main(){
	int V, E, u, v;
	
	cin >> V >> E;
	
	for(int i = 0; i < V; i++){
		id[i] = i; rk[i] = 1;
		num[i] = low[i] = -1;
		articulationPoint[i] = false;
	}
	
	while(E--){
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	for(int i = 0; i < V; i++){
		dfsRoot = i; rootChildren = dfsCount = 0;
		if(num[i] == -1) dfs(i, -1); //Pequeno caso que deve ser testado
		
		articulationPoint[dfsRoot] = (rootChildren > 1); //A raiz só será 
		//um ponto de artilação caso ela tenha obviamente mais que dois filhos
	}
	
	return 0;
}
