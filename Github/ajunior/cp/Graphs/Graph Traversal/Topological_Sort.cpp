//after call dfs(0) reverse top, or write on reverse order

#include <bits/stdc++.h>

#define 1010

using namespace std;

vector <int> adj[MAX], top;
bool mark[MAX];

void dfs(int idx){
    mark[idx] = true;

    for(int i = 0; i < (int)adj[idx].size(); i++){
        int u = adj[idx][i];
        if(!mark[u]){
            dfs(u);
        }
    }

    top.push_back(idx);
}

int main(){
    return 0;
}
