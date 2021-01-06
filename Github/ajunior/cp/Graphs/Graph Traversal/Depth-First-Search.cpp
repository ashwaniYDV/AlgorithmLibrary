#include <bits/stdc++.h>

#define MAX 10010

using namespace std;

typedef pair <int, int> ii;

vector <ii> adj[MAX];
bool mark[MAX];

void dfs(int idx){
    mark[idx] = true;

    for(int i = 0; i < (int)adj[idx].size(); i++){
        int u = adj[idx][i].first;
        if(!mark[u]){
            dfs(u);
        }
    }
}

int main(){
    return 0;
}
