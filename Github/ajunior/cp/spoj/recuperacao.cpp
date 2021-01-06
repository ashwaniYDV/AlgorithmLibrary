#include <iostream>

using namespace std;

int main(){
	int n, ent, res, soma = 0;
	bool time;
	int cont = 0;
	while(cin >> n)	{
		time = true;
		res = 0;
		soma = 0;
		
		for(int i = 0; i < n; i++){
			cin >> ent;
			if(soma==ent && time){
				res = ent;
				time = false;
			}
			soma+=ent;
			
		}
		cont++;
		cout << "Instancia " << cont << endl;
		if(time){
		cout<< "nao achei" << endl << endl;	
		}else{
		cout << res << endl << endl;
		}
	}
	
	
	
	return 0;
}