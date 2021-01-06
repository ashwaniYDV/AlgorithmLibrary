#include <cstdio>
#include <algorithm>
 
using namespace std;
 
typedef struct pais{
    int o, p, b, pos;
}pais;
 
bool cmp(pais a, pais b){
 
    if(a.o == b.o){
        if(a.p == b.p){
            if(a.b == b.b){
                return a.pos < b.pos;
            }
            return a.b > b.b;
        }
        return a.p > b.p;
    }
    return a.o > b.o;
}
 
int main(){
 
    pais paises[101];
    int n, m, o, p, b;
 
    scanf("%d %d", &n, &m);
 
    for(int i = 1; i <= n; i++){
        paises[i - 1].o = 0;
        paises[i - 1].p = 0;
        paises[i - 1].b = 0;
        paises[i - 1].pos = i;
    }
 
    while(m--){
 
        scanf("%d %d %d", &o, &p, &b);
 
        paises[o - 1].o++;
        paises[p - 1].p++;
        paises[b - 1].b++;
    }
 
    sort(paises, paises + n, cmp);
 
    printf("%d", paises[0].pos);
 
    for(int i = 1; i < n; i++)
        printf(" %d", paises[i].pos);
 
    return 0;
}