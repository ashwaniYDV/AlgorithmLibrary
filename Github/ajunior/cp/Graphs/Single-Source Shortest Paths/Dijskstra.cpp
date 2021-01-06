#include <bits/stdc++.h>

#define MAX 1010
#define INF (int)1e9

using namespace std;

typedef pair<int, int> ii;

vector <ii> adj[MAX];
int dist[MAX]; //set all cell with INF

void dijkstra(int s){
    priority_queue <ii, vector<ii>, greater<ii> > pq;

    pq.push(make_pair(0, s));
    dist[0] = 0;

    while(!pq.empty()){
        ii u = pq.top();
        pq.pop();

        int v = u.second;

        if(dist[v] < u.first) continue;

        for(int i = 0; i < (int)adj[v].size(); i++){
            u = adj[v][i];

            if(dist[u.first] > dist[v] + u.second){
                dist[u.first] = dist[v] + u.second;
                pq.push(make_pair(dist[u.first], u.first));
            }
        }
    }
}

int main(){
}
