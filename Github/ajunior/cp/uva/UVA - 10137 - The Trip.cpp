#include <cstdio>
 
using namespace std;
 
int n;
double vet[1010];
int main() {
    while(true) {
        scanf("%d", &n);
        if(n == 0) break;
        double temp = 0, aux  , res1 = 0, res2 = 0;;
        for(int i = 0; i < n; i++) {
            scanf("%lf", &vet[i]);
            temp += vet[i];
        }
        temp = temp / n;
        for(int i = 0; i < n; i++) {
            aux = (int) ((vet[i] - temp) * 100.0) / 100.0;
            if(aux > 0){ 
            	res1 += aux;
            }else{
            	res2 += aux;
            }
        }
        res2 = -res2;
        if(res2 > res1){
        	printf("$%.2f\n", res2);
        }else{
        	printf("$%.2f\n", res1);
        } 
    }
}