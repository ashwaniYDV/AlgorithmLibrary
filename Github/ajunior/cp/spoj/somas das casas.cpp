#include <iostream>

using namespace std;


int n, t;


int busca(int *vet, int num, int c){
	int m, i = 0, f = num;
	while (i<=f){
		m=(i+f)/2;
		if (vet[m]+c==t){
			return vet[m];	
		}else if (vet[m]+c<t){
			i = m + 1;
		}else{
			f = m - 1;	
		}
	}
   	return -1;	
}




int main (){

	 
	cin >> n;
	int vet[n];
	for(int i = 0; i < n; i++){
		cin >> vet[i];
	}
	cin >> t;
	
	
	for(int i = 0; i < n; i++){
		if(busca(vet, n,  vet[i])!=-1){
		cout << vet[i] << " " << busca(vet, n, vet[i]) << endl;
	   	break;
		}
	}
	return 0;
}