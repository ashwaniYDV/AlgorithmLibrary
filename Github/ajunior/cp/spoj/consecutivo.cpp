#include <iostream>
using namespace std;
int main(){
	int n;
	cin >> n;
	long long temp, ent;
	int cont = 1, maior = 0;
	cin >> temp;
	for(int i = 0; i < n-1; i++){
		cin >> ent;
		if(ent == temp){
			cont++;
			if(cont > maior){
				maior = cont;
			}
		}else{
			cont = 1;
			temp = ent;
		}
		
	}
	
	cout << maior << endl;
	
	return 0;
}