/*O((n * m)^4), no entando existe um algortimo que executa em O((n * m)^3),
dar uma estudada nele depois, não creio que seja tão útil pra OBI, talvez pra Seletiva*/

#include <bits/stdc++.h>

const int MAX = 110;

using namespace std;

int mat[MAX][MAX];

int main(){

    int n, m;

    scanf("%d %d", &n, &m);

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            scanf("%d", &mat[i][j]);

            mat[i][j] += mat[i - 1][j];
            mat[i][j] += mat[i][j - 1];
            mat[i][j] -= mat[i - 1][j - 1];
        }
    }

    int ret = INT_MIN, aux;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            for(int k = i; k <= n; k++){
                for(int l = j; l <= m; l++){
                    aux = mat[k][l];

                    aux -= mat[i - 1][l];
                    aux -= mat[k][j - 1];
                    aux += mat[i - 1][j - 1];

                    ret = max(ret, aux);
                }
            }
        }
    }

    printf("%d\n", ret);

    return 0;
}
