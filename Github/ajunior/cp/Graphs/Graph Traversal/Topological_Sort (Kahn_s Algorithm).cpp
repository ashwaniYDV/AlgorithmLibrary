/*After call kahn with V (the number of vertex in the graph)
**top will contain the topological sort.*/

#include <bits/stdc++.h>

#define MAX 1010

using namespace std;

vector <int> adj[MAX], top;
int in_degree[MAX];

void kahn(int V){

    queue <int> q;

    for(int i = 0; i < V; i++){
        if(in_degree[i] == 0)
            top.push(i);
    }

    while(!q.empty()){
        int u = q.front();
        q.pop();

        top.push_back(u);

        for(int i = 0; i < (int)adj[u].size(); i++){
            int v = adj[u][i];
            in_degree[v]--;

            if(in_degree[v] == 0)
                q.push(v);
        }
    }
}

int main(){
    return 0;
}
