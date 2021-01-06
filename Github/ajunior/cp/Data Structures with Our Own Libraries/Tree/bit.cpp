/*
Binary Indexed Tree (BIT)
Fenwick's Tree

por Felipe Holanda - holanda1@gmail.com
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXVALUE 1001

int bit[MAXVALUE+1];

int soma_ate(int indice){
       int soma = 0;
       while (indice > 0){
             soma += bit[indice];
             indice -= (indice & -indice); // faz o ultimo 1 do binário andar para direita
       }
       return soma;
}

void insere(int val, int indice){
       while (indice <= MAXVALUE){
             bit[indice] += val;
             indice += (indice & -indice);// faz o ultimo 1 do binário andar para esquerda
       }
}

int soma_intervalo(int a,int b){
       return soma_ate(b) - soma_ate(a-1);
}

int main(){

       int valor, caixa;
       int inicio, fim;
       int n;

	printf("%d\n",1&-1);
	printf("%d\n",13&-13);

       scanf("%d",&n);
	
	

       memset(bit,0,sizeof(bit));           

       for(int i=0;i<n;i++){
             scanf("%d %d", &caixa, &valor);
             insere(caixa,valor);
       }             

	while( scanf("%d %d",&inicio, &fim)!=EOF ){
	     printf("%d\n",soma_intervalo(inicio,fim));	
	}  
       
       return 0;
}
