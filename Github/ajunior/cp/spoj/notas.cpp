#include <algorithm>
#include <stdio.h>

using namespace std;
int main(){
	int n;
	
	scanf("%d",&n);
	int vet[n];
	for(int i = 0; i < n; i++){
		scanf("%d", &vet[i]);		
	}
	
	sort(vet, vet+n);
	int maior = 0, cont = 0, res = vet[n-1], temp = vet[0];
	
	
	for(int i = n-1;  0< i; i--){
		if(temp == vet[i]){
			cont++;
			if(cont>maior){
				maior = cont;
				res = vet[i];
			}
		}else{
			cont = 1;
			temp=vet[i];
		}
	}
	printf("%d\n",res);		
	return 0;
}

