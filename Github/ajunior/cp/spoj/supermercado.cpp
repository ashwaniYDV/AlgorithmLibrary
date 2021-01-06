
#include <stdio.h>
#include <algorithm>
using namespace std;
int main(){
  int x[1001], y[1001];
  int temp, cont=0;
  
  while (scanf("%d", &temp),temp) {
      for (int i = 0; i < temp; i++){scanf("%d %d", &x[i], &y[i]);}
      sort(x,x+temp);
  	  sort(y,y+temp);
  	  cont++;
        printf("Teste %d\n%d %d\n\n", cont, x[temp/2], y[temp/2]);
    }
  return 0;
}
