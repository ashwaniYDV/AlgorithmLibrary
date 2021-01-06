#include <stdio.h>
#include <iostream>
#include <string.h>
#include <map>
#include <vector>
using namespace std;
 
int main(){
	string a, b;
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a >> b;
		int chave = 0;
		if(b.size() > a.size()){
			cout << "nao encaixa"<< endl;
		}else{
			for(int j = b.size()-1; j >= 0; j--){
				if(a[j+(a.size() - b.size())] != b[j]){
					cout << "nao encaixa" << endl;
					chave = 1;
					break;
				}
			}
			if(chave == 0){
				cout << "encaixa" << endl;
			}
		}
	}



}