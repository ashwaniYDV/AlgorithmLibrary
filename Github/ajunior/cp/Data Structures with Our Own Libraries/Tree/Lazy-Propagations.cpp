#include <bits/stdc++.h>

#define MAX 100010

using namespace std;

typedef long long ll;

ll tree[4 * MAX], lazy[4 * MAX], arr[MAX];

ll query(int idx, int l, int r, int i, int j){

    if(i > r || j < l)
        return 0;

    if(lazy[idx] != 0){
        tree[idx] += (r - l + 1) * lazy[idx];

        if(l != r){
            lazy[2 * idx] += lazy[idx];
            lazy[2 * idx + 1] += lazy[idx];
        }

        lazy[idx] = 0;
    }

    if(l >= i && r <= j)
        return tree[idx];

    int mid = (l + r) / 2;

    return query(2 * idx, l, mid, i, j) +
           query(2 * idx + 1, mid + 1, r, i, j);
}

void update(int idx, int l, int r, int i, int j, ll val){

    if(lazy[idx] != 0){
        tree[idx] += (r - l + 1) * lazy[idx];

        if(l != r){
            lazy[2 * idx] += lazy[idx];
            lazy[2 * idx + 1] += lazy[idx];
        }

        lazy[idx] = 0;
    }

    if(i > r || j < l)
        return;

    if(l >= i && r <= j){
        tree[idx] += (r - l + 1) * val;

        if(l != r){
            lazy[2 * idx] += val;
            lazy[2 * idx + 1] += val;
        }
    }else{
        int mid = (l + r) / 2;

        update(2 * idx, l, mid, i, j, val);
        update(2 * idx + 1, mid + 1, r, i, j, val);

        tree[idx] = tree[2 * idx] + tree[2 * idx + 1];
    }
}

int main(){
    return 0;
}
