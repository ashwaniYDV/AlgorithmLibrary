#include <bits/stdc++.h>

const int MAX = 100010;

using namespace std;

int aux[MAX], seq[MAX], dp[MAX];

/*O(n * log k), onde k é o tamanho da LIS*/
int lis_log(int n){
    int pos, lis = 0, l_aux = 0;

    for(int i = 0; i < n; i++){
        pos = lower_bound(aux, aux + l_aux, seq[i]) - aux;
        aux[pos] = seq[i];
        l_aux = pos + 1;

        lis = max(lis, pos + 1);
    }
    return lis;
}

/*O(n²)*/
int lis_quad(int n){
    int ans = 0;

    for(int i = 0; i < n; i++){
        dp[i] = 1;
        for(int j = i - 1; j >= 0; j--){
            if(seq[j] < seq[i])
                dp[i] = max(dp[i], dp[j] + 1);
        }
        ans = max(ans,dp[i]);
    }
    return ans;
}

int main(){

    int n;

    scanf("%d", &n);

    for(int i = 0; i < n; i++)
        scanf("%d", &seq[i]);

    printf("%d %d\n", lis_log(n), lis_quad(n));

    return 0;
}
