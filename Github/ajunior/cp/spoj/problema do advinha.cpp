#include <iostream>
#define MAX 10001
using namespace std;
int n, k;

int busca(int chave){//fim é o maior tamanho possível da fatia
    int inicio = 1, fim =100, cont = 0, meio;
    while (inicio <= fim) {
    	cont ++;
        meio = (inicio + fim) / 2; //encontro meio
	  if(meio==chave){
		  return cont;
	  } if (meio < chave ) {//verifica se o numero testado é maior ou IGUAL ao número de pessoas
		inicio = meio + 1;
		cont++;//armazena sempre o ultimo melhor resultado possível
      } else {
		fim = meio - 1;
		cont++;
      }
    }
	return cont;//retorna o ultimo melhor valor armazenado
}

int main () {
	int n;
	cin >> n;
	cout << busca(n); 
	
	
	return 0;
}