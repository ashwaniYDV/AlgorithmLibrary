#include <bits/stdc++.h>

#define MAX 1010

using namespace std;

vector <int> adj[MAX];
int color[MAX];

bool bfs(int idx){
    bool isBipartite = true;
    queue <int> q;

    q.push(idx);
    color[idx] = 0;

    while(!q.empty() & isBipartite){
        int u = q.front();
        q.pop();

        for(int i = 0; i < (int)adj[u].size(); i++){
            int v = adj[u][i];

            if(color[v] == -1){
                color[v] = 1 - color[u];
                q.push(v);
            }else if(color[v] == color[u]){
                isBipartite = false;
                break;
            }
        }
    }

    return isBipartite;
}

int main(){
    return 0;
}
