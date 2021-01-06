#include <stdio.h>
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <map>
#include <vector>
using namespace std;
 

int main(){
	string a, b, cpf = "", temp = "";
	cin >> a >> b;

	for(int i = 0; i < a.size(); i++){
		if(a[i] >= '0' && a[i] <= '9' || a[i] == '.'){
			temp+= a[i];
		}
	}
	a = temp;
	temp = "";
	for(int i = 0; i < b.size(); i++){
		if(b[i] >= '0' && b[i] <= '9' || b[i] == '.'){
			temp+= b[i];
		}
	}
	b = temp;
	temp = "";
	for(int i = 0; i < a.size(); i++){
		if(i < 11){
			cpf += a[i];
		}else{
			temp += a[i];
		}
	}	
	a = temp;
	temp = "";
	int chave = 0, cont = 0;
	for(int i = 0; i < a.size(); i++){
		temp += a[i];
		if(a[i] == '.'){
			chave = 1;
		}
		if(chave == 1){
			cont++;
		}
		if(cont == 3){
			break;
		}
	}

	a = temp;
	chave = 0;
	cont = 0;
	temp = "";
	for(int i = 0; i < b.size(); i++){
		temp += b[i];
		if(b[i] == '.'){
			chave = 1;
		}
		if(chave == 1){
			cont++;
		}
		if(cont == 3){
			break;
		}
	}
	b = temp;

	char aa[1024];
	char bb[1024];
	strcpy(aa, a.c_str());
	strcpy(bb, b.c_str());
 	long double n,m;
    n = atof (aa);
  	m = atof (bb);
  //	n = 100000000000000.22;
   	n = n + m;
  	cout <<"cpf " << cpf<< endl;
  	printf("%.2llf\n", n);
	
	return 0;

}