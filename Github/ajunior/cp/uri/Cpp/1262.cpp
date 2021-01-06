#include <stdio.h>
#include <iostream>
#include <string.h>

using namespace std;

int main(){
	string ent;
	int n;

	while(cin >> ent){
		cin >> n;
		int res = 0, chave = 0;
		for(int i = 0; i < ent.size(); i++){
			if(ent[i] == 'W'){
				if(chave > 0){
					res++;
					chave = 0;
				}
				res++;
			}else{
				chave++;
			}
			if(chave == n){
				res++;
				chave = 0;
			}
		}
		if(chave > 0){
			res++;
		}
		cout << res << endl;
	}


	return 0;
}