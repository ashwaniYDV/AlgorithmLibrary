#include <bits/stdc++.h>

#define MAX 100010

using namespace std;

int p[MAX], _rank[MAX], cont;

void init(int n){
    cont = n;
    for(int i = 0; i < n; i++){
        p[i] = i;
        _rank[i] = 1;
    }
}

int _find(int x){
    if(p[x] == x) return x;
    return p[x] = _find(p[x]);
}

bool sameSet(int x, int y){
    return _find(x) == _find(y);
}

bool join(int x, int y){
    int i = _find(x), j = _find(y);

    if(i != j){
        if(_rank[i] >= _rank[j]){
            p[j] = i;
            _rank[i] += _rank[j];
        }else{
            p[i] = j;
            _rank[j] += _rank[i];
        }
        return true;
    }
    return false;
}

int main(){
    return 0;
}
