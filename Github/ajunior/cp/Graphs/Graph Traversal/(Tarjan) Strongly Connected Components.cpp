/*Encontrado componentes fortemente conexos em O(V + E) DFS. Nesse algortimo eu uso Union-Find só 
**pra agrupar os componentes, mas o uso de um vector<int> seria mais prático*/

#include <bits/stdc++.h>

const int MAXV = 100010;

using namespace std;

vector <int> adj[MAXV], S;
/*Listas de adjacência e uma pilha auxiliar, que na verdade é um vector :v*/
int num[MAXV], low[MAXV];
/*momento de primeira visitação e menor visitação*/
int dfsCount, SCC; 
/*contador de visitação e número de componentes fortemente conexos*/ 
bool mark[MAXV];

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

void dfs(int u){
	num[u] = low[u] = dfsCount++;
	S.push_back(u);
	mark[u] = true;
	
	for(int i = 0; i < (int)adj[u].size(); i++){
		int v = adj[u][i];
		
		if(num[v] == -1)
			dfs(v);
		if(mark[v])
			low[u] = min(low[u], low[v]);
	}
	
	if(num[u] == low[u]){
		SCC++;
		
		while(true & !S.empty()){
			int v = S.back(); S.pop_back();
			mark[v] = false;
			
			union_set(u, v);
			
			if(v == u) break;
		}
	}
}

int main(){
	int V, E, u, v;
	
	cin >> V >> E;
	
	for(int i = 1; i <= V; i++){
		num[i] = low[i] = -1;
		id[i] = i; rk[i] = 1;
	}
	
	while(E--){
		cin >> u >> v;
		adj[u].push_back(v);
	}
	
	dfsCount = SCC = 0;
	for(int i = 1; i <= V; i++){
		if(num[i] == -1){
			memset(mark, false, sizeof mark); //cuidado com isso tomei 3 WA
			dfs(i);
		}
	}
	
	cout << SCC << "\n";
	
	return 0;
}
