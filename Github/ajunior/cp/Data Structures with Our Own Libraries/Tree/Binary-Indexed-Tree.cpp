#include <bits/stdc++.h>

#define MAX 100011

using namespace std;

int tree[MAX];

void update(int idx, int val){
    while(idx < MAX){
        tree[idx] += val;
        idx += idx & (-idx);
    }
}

int query(int idx){
    int ret = 0;
    while(idx > 0){
        ret += tree[idx];
        idx -= idx & (-idx);
    }
    return ret;
}

int main(){
    return 0;
}
