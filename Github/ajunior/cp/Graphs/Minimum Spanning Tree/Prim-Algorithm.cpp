#include <bits/stdc++.h>

#define MAX 1010

using namespace std;

typedef pair<int, int> ii;

priority_queue <ii, vector<ii>, greater<ii> > pq;
vector <ii> adj[MAX];
bool mark[MAX];

void process(int idx){
    mark[idx] = true;
    for(int i = 0; i < (int)adj[idx].size(); i++){
        ii v = adj[idx][i];
        if(!mark[v.first]){
            pq.push(make_pair(v.second, v.first));
        }
    }
}

int prim(int idx){
    int mst = 0;

    process(idx);

    while(!pq.empty()){
        ii v = pq.top();
        pq.pop();
        int x = v.second, w = v.first;;
        if(!mark[x]){
            mst += w;
            process(x);
        }
    }
    
    return mst;
}

int main(){
    return 0;
}
