#include <bits/stdc++.h>

#define MAX 100010

using namespace std;

int tree[4 * MAX], arr[MAX];

void build(int idx, int l, int r){
    if(l == r){
        tree[idx] = arr[l];
    }else{
        int mid = (l + r) / 2;
        build(2 * idx, l, mid);
        build(2 * idx + 1, mid + 1, r);

        tree[idx] = tree[2 * idx] + tree[2 * idx + 1];
    }
}

int query(int idx, int l, int r, int i, int j){
    if(i > r || j < l)
        return 0;
    if(l >= i && r <= j)
        return tree[idx];

    int mid = (l + r) / 2;

    return query(2 * idx, l, mid, i, j) +
           query(2 * idx + 1, mid + 1, r, i, j);
}

void update(int idx, int l, int r, int i, int val){
    if(l == r){
        tree[idx] = val;
    }else{
        int mid = (l + r) / 2;

        if(i <= mid)
            update(2 * idx, l, mid, i, val);
        else
            update(2 * idx + 1, mid + 1, r, i, val);

        tree[idx] = tree[2 * idx] + tree[2 * idx + 1];
    }
}

int main(){
    return 0;
}
