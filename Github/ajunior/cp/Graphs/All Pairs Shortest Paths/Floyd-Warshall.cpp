#include <bits/stdc++.h>

#define MAX 1010

using namespace std;

int mat[MAX][MAX], V;

void floyd_warshall(){
    for(int k = 0; k < V; k++){
        for(int i = 0; i < V; i++){
            for(int j = 0; j < V; j++){
                mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);
            }
        }
    }
}

int main(){
    return 0;
}
