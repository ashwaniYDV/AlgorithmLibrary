#include <stdio.h>
#include <iostream>
using namespace std;
    int main() {
        int rep, n;
        char pe;    
		int e[61];
		int d[61];
        while (scanf("%d",&rep)>0) {
            int res = 0;

            for(int i = 0; i < 61; i++)
			{
				e[i]=0;
				d[i]=0;
			}
            for (int i = 0; i < rep; i++) {
                scanf("%d",&n);
				cin >> pe;
                if (pe=='D') {
                    d[n]++;
                  //  printf("%dEntradaD\n", d[n]);
                }else{
                    e[n]++;
                  //  printf("%dEntradaE\n",e[n]);
                }   
            }
            
            for (int i = 0; i < 61; i++) {
                if (d[i]>e[i]) {
                    res+=e[i];
                }else{
                    res+=d[i];
                }
            
            }
            printf("%d\n",res);
        }
		return 0;
	    }

          
            