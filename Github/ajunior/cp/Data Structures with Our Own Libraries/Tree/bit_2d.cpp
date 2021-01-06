/*
Binary Indexed Tree (BIT) :: 2D
Fenwick's Tree :: 2D

por Felipe Holanda - holanda1@gmail.com
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_X 1001
#define MAX_Y 1001

int bit[MAX_X][MAX_Y];

int soma_ate(int x, int y_fixo){
       int soma = 0;
       
       while (x > 0){
          int y=y_fixo;

	  while(y > 0){
             soma += bit[x][y];
	     y -= (y & -y);
	  }
 
             x -= (x & -x); 
       }
       return soma;
}

void insere(int x , int y_fixo , int valor){
	while (x <= MAX_X){
		int y = y_fixo;
		
		while (y <= MAX_Y){
			bit[x][y] += valor;
			y += (y & -y); 
		}
		
		x += (x & -x); 
	}
}


int soma_intervalo(int a, int b,int x,int y){
       return ( soma_ate(x,y) - soma_ate(x,b) - soma_ate(a,y) + soma_ate(a,b) );
}

int main(){

       int n;
       int x,y,valor;
       int x1,y1,x2,y2;

       scanf("%d",&n);

       memset(bit,0,sizeof(bit));

       for(int i=0;i<n;i++){
             scanf("%d %d %d", &x, &y,&valor);
             insere(x,y,valor);
       }

	printf("Calculando...\n");

	while( scanf("%d %d %d %d", &x1, &y1, &x2, &y2) != EOF ){
	     printf("%d\n",soma_intervalo(x1,y1,x2,y2));
	}

       return 0;
}
