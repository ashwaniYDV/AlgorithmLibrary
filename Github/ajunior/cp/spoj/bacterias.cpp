#include <stdio.h>
#include <math.h>
using namespace std;
int main(){
int N, D,C, res, i;
double bact = 0.0;


scanf("%d", &N);
for (i = 0; i < N; i++) {
scanf("%d%d", &D, &C);

if (bact < (double)C*log(D)) {
bact = C*log(D);
res = i;
}
}
printf("%d\n", res);
return 0;
}