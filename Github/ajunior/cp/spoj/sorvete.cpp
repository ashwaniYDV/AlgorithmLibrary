#include <iostream>
#include <string.h>
using namespace std;

int main(){
	int p , s, inicio, fim, teste = 1;
	int vet[10001];
	while(cin >> p >> s){
		
		if(p==0 && s ==0)break;
		memset(vet, 0, sizeof(vet));
	
		for(int i = 0; i < s; i++){
			cin >> inicio >> fim;
			for(int j = inicio; j < fim; j++){
				vet[j] = 1;
				//cout << i;
			}
		}
		bool b = true;
		cout << "Teste " << teste++ << endl;
		for(int i = 0; i < p+1; i++){
			if(vet[i]==1 && b == true){
				cout << i << " ";
				b = false;
			}else if(vet[i]==0 && b==false){
				cout << i << endl;
				b = true;
			}
		}
		
		
		cout << endl<<endl;;
	}
	
	
	
	return 0;
}