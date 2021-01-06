#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
int main(){
	int vet[3];
	scanf("%d%d%d", &vet[0], &vet[1], &vet[2]);
	int port[2];
	scanf("%d%d", &port[0], &port[1]);

	sort(vet, vet+3);
	sort(port, port+2);
if(port[0]<vet[0] || port[1]<vet[1]){
		cout << "N" <<endl;
	}else{
		cout << "S" <<endl;
	}
	
	return 0;
}