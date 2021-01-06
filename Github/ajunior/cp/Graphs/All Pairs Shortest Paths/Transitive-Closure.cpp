/*O(n³), algoritmo que pré-calcula todas as transitividades, ou seja, se existe caminho entre um determinado vértice
** e outro*/

#include <bits/stdc++.h>

const int MAXV = 210;

using namespace std;

bool mat[MAXV][MAXV];

/*Caso já haja caminho entre o vértice 'i' e o vértice 'j', eles têm transitividade direta.
No entanto se a transitividade direta não acontecer, devemos verificar a transitividade indireta
entre os dois vértices e todas as possibilidades de vértices pivóres 'k', mas claro utilizando o auxílio
da programação dinâmica que faz com que o algoritmo não repita cálculos*/

void transitive_closure(int n){
	for(int k = 0; k < n; k++){
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				mat[i][j] = mat[i][j] | (mat[i][k] & mat[k][j]);
				//transitividade direta  //transitividade indireta
				//podemos utilizar o operador '|=' para simplificar o código, ficaria dessa forma:
				//mat[i][j] |= (mat[i][k] & mat[k][j]);
			}
		}
	}
}

int main(){
	
	int n, e, q, x, y;
	
	scanf("%d %d %d", &n, &e, &q);
	
	while(e--){
		scanf("%d %d", &x, &y);
		x--; y--;
		mat[x][y] = true; //grafo direcionado
	}
	
	transitive_closure(n);
	
	while(q--){
		scanf("%d %d", &x, &y);
		x--; y--;
		puts(mat[x][y] ? "SIM" : "NAO");
	}
	
	return 0;
}
