#include <iostream>
#include <string>
using namespace std;

int main(){
	int n;
	string vet[60000];
	string ent;
	bool temp = false;
	while(cin >> n, n != 0){ 
		if(n != 0 && temp)	{
					cout << endl;
				
		}	temp = true;
		int maior = 0;
		for(int i = 0; i < n; i++){
			cin >> ent;
			vet[i] = ent;
			if(ent.length() > maior){
				maior = ent.length();
			}
		}		
		for(int i = 0; i < n; i++){
			for(int j = 0; j < (maior - vet[i].length()); j++)	{
				cout<<" ";
			}
			cout << vet[i] << endl;
		}

		
	}
	return 0;
}