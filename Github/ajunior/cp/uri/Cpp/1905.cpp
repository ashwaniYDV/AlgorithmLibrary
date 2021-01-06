#include <stdio.h>
#include <iostream>
#include <string.h>
#include <map>
#include <vector>
using namespace std;
 
typedef struct No{
	int a, b;
}No;

bool res = false;
int mat[6][6];
vector<No> vet;
bool l(int a, int b){//verifica limite
	if(a > 0 && b > 0 && a < 6 && b < 6){
		return true;
	}
	return false;
}

void varrer(No no){
	mat[no.a][no.b] = 2;
	No aux;
	if(l(no.a+1, no.b) && mat[no.a+1][no.b] == 0){
		aux.a = no.a+1;
		aux.b = no.b;
		vet.push_back(aux);
		mat[no.a+1][no.b] = 2;
	}
	if(l(no.a, no.b-1) && mat[no.a][no.b-1] == 0){
		aux.a = no.a;
		aux.b = no.b-1;
		vet.push_back(aux);
		mat[no.a][no.b-1] = 2;
	}
	if(l(no.a-1, no.b) && mat[no.a-1][no.b] == 0){
		aux.a = no.a-1;
		aux.b = no.b;
		vet.push_back(aux);
		mat[no.a-1][no.b] = 2;	
	}
	if(l(no.a, no.b+1) && mat[no.a][no.b+1] == 0){
		aux.a = no.a;
		aux.b = no.b+1;
		vet.push_back(aux);
		mat[no.a][no.b+1] = 2;
	}
	if(vet.size() > 0){
		aux = vet.back();
		vet.pop_back();
		if(aux.a == 5 && aux.b == 5){
			res = true;
			return;
		}
		varrer(aux);
	}		
}





int main(){

int n;
cin >> n;
for(int t = 0; t < n; t++){
	for(int i = 1; i <= 5; i++){
		for (int j = 1; j <= 5; j++){
			cin >> mat[i][j];
		}
	}
	vet.clear();
	No no;
	 	no.a = 1;
		no.b = 1;
		res = false;
		varrer(no);
	if(res){
		cout << "COPS" << endl;
	}else{
		cout << "ROBBERS" << endl;
	}
}
return 0;

}