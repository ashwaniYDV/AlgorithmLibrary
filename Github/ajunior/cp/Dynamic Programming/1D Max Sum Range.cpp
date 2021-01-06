/*O(n)*/

#include <bits/stdc++.h>

using namespace std;

int main(){

    int n, v, sum = 0, ans = INT_MIN;

    scanf("%d", &n);

    while(n--){
        scanf("%d", &v);

        sum += v;
        ans = max(sum, ans);
        if(sum < 0) sum = 0;
    }

    printf("%d\n", ans);

    return 0;

}
