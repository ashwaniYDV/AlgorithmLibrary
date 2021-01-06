/*O(n²), nesse caso meoizing é melhor que dp de fato*/
#include <bits/stdc++.h>

const int MAX = 110;

using namespace std;

int w[MAX], p[MAX], memo[MAX][MAX], n;

int top_down(int i, int rem){
    if(i == n || rem == 0)
        return 0;

    int &ret = memo[i][rem];

    if(ret != -1)
        return ret;

    if(w[i] > rem){
        ret = top_down(i + 1, rem);
    }else{
        ret = max(top_down(i + 1, rem), p[i] + top_down(i + 1, rem - w[i]));
    }

    return ret;
}

int main(){

    int rem;

    scanf("%d %d", &n, &rem);

    for(int i = 0; i < n; i++)
        scanf("%d %d", &w[i], &p[i]);

    printf("%d\n", top_down(0, rem));

    return 0;
}
