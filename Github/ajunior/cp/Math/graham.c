#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAXN 1010 //numero de pontos maximo na entrada do problema
#define epsilon 0.0001 // criterio para saber se um double é zero. Se menor que epsilon -> igual a zero

typedef struct{
	double x;
	double y;
}tipo_ponto;	

tipo_ponto pivo;

int ccw(tipo_ponto a, tipo_ponto b, tipo_ponto c){
	double resultado= ( (a.x*b.y) + (b.x*c.y) + (c.x*a.y) )
			- ( (a.y*b.x) + (b.y*c.x) + (c.y*a.x) );
      
	if( fabs(resultado)<epsilon ) return 0;
	return resultado;
}

int ordena_x_y(const void *a, const void *b){
	if( ((tipo_ponto*) a)->x < ((tipo_ponto*) b)->x ) return -1;
	if( ((tipo_ponto*) a)->x > ((tipo_ponto*) b)->x ) return 1;
	
	if( ((tipo_ponto*) a)->y < ((tipo_ponto*) b)->y ) return -1;
	if( ((tipo_ponto*) a)->y > ((tipo_ponto*) b)->y ) return 1;
	
	return 0;
}

int ordena_angular(const void *a, const void *b){
	if( ccw( pivo, * ((tipo_ponto*) a), *((tipo_ponto*) b) ) ==0 ){
		if( ((tipo_ponto*) a)->x < ((tipo_ponto*) b)->x ) return -1;
		if( ((tipo_ponto*) a)->x > ((tipo_ponto*) b)->x ) return 1;
	}
	
	if( ccw( pivo, *((tipo_ponto*) a), *((tipo_ponto*) b) ) <0 ) return 1;
	else return -1;
}

int main(){
	int n;
	tipo_ponto ponto[MAXN];
	int convexo[MAXN],m=0,i;
	
	scanf("%d",&n);
	
	for(i=1; i<=n; i++) scanf("%lf %lf",&ponto[i].x,&ponto[i].y);
	
	qsort( &ponto[1], n , sizeof(tipo_ponto), ordena_x_y);//ordeno por menor x, em caso de empate, por menor y
	
	pivo.x=ponto[1].x;	
	pivo.y=ponto[1].y;
	
	qsort( &ponto[2], n-1, sizeof(tipo_ponto), ordena_angular);//ordeno por angulos, nao coloco nessa ordenacao o ponto com menor x (pivô)
	
	convexo[++m]=1;//coloco o ponto 1 (ponto com menor x) no fecho convexo  
	convexo[++m]=2;//coloco o ponto 2 (ponto com menor angulo) no fecho convexo
	
	i=3;
	while( i<=n ){//algoritmo em si, vou testando ponto a ponto...
		if(  ccw( ponto[ convexo[m-1] ], ponto[ convexo[m] ], ponto[i] ) <= 0 ) m--;
		else convexo[++m]=i, i++;
	}
	
	for(i=1; i<=m ; i++)//saida, mostro o fecho convexo
		printf("%lf %lf\n", ponto[ convexo[i] ].x, ponto[ convexo[i] ].y);
	
    return 0;
}	