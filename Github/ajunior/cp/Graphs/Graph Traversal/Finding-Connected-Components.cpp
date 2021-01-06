#include <bits/stdc++.h>

#define MAX 1010

using namespace std;

vector <int> adj[MAX];
bool mark[MAX];

void dfs(int idx){
    mark[idx] = true;
    for(int i = 0; i < (int)adj[idx].size(); i++){
        int u = adj[idx][i];
        if(!mark[u]){
            dfs(u);
        }
    }
}

int main(){

    int CC = 0, V;

    for(int i = 0; i < V; i++){
        if(!mark[i]){
            CC++;
            dfs(i);
        }
    }

    printf("%d\n", CC);

    return 0;
}
