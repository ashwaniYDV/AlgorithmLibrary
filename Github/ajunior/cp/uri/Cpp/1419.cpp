#include <stdio.h>
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <map>
#include <vector>
using namespace std;
 

int main(){
	int n, ent;
	while (true){
		cin >> n;
		if(n == 0){
			break;
		}
		int a = 0, b = 0, m = 0, cont = 0, aux = 0, l = 0, M = 10000000, L = 10000000;
		
		for(int i = 0; i < n; i++){
			cin >> ent;
			m += ent;
			if(ent == aux){
				cont++;
			}else{
				aux = ent;
				cont = 0;
			}
			if(cont == 2 && M == 10000000){
				M = i;
			}
		}

		aux = 0;
		cont = 0;
		for(int i = 0; i < n; i++){
			cin >> ent;
			l += ent;
			if(ent == aux){
				cont++;
			}else{
				aux = ent;
				cont = 0;
			}
			if(cont == 2 && L == 10000000){
				L = i;
			}
		}


		if(M < L){
			m += 30;
		}else if (M > L){
			l += 30;
		}

		if(m > l){
			cout << "M"  << endl;
		}else if(m < l){
			cout << "L"  << endl;
		}else{
			cout << "T"  << endl;
		}


	}
	return 0;

}