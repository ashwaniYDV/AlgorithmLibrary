#include <stdio.h>
#include <iostream>
#include <string.h>
#include <map>
#include <vector>
using namespace std;
 

int main(){
	int n, ent, num;
	int vet[10001];

	while(cin >> n){
		if(n == 0){
			break;
		}
		bool res = true;
		memset(vet, 0, sizeof(vet));
			for(int i = 1; i <= n; i++){
			cin >> num >> ent;
			if(i + ent > 0 && i + ent < 10001){
				if(vet[i + ent] == 0){
					vet[i + ent] = num;
				}else{
					res = false;
				}
			}else{
				res = false;
			}
		}
    	for(int i = 1; i <= n; i++){
				if(vet[i] == 0){
					res = false;
				}
		}
		if(res == true){
		
			for(int i = 1; i <= n; i++){
				cout << vet[i];
				if(i != n) cout  << " ";
			}
			cout << endl;
		}else{
			cout  << -1 << endl;
		}
	}



	return 0;
}