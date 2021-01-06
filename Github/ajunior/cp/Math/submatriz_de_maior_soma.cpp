#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max(A,B) ((A)>(B))?(A):(B)

#define MAXN 105
#define MAXM 105
#define INF 999999999

int main(){
    
    int n,m,x,y,matriz[MAXN][MAXM],soma[MAXN][MAXM];
    
    scanf("%d %d %d %d",&n,&m,&x,&y);
    
    for(int i=1; i<=n;i++)
    for(int j=1; j<=m;j++)
        scanf("%d",&matriz[i][j]);
    
    memset(soma,0,sizeof(soma));//inicializo matriz soma - necessário para construir "borda"
    
    for(int i=1; i<=n;i++){//monto matriz soma
            for(int j=1; j<=m;j++) soma[i][j]=soma[i][j-1]+matriz[i][j]; //somo apenas por linha
            for(int j=1; j<=m;j++) soma[i][j]+=soma[i-1][j]; //somo com a coluna correspondente da linha superior
    }
    
    int maior=-INF;//variavel maior é iniciada com - "infinito"
    
    for(int i=x; i<=n;i++)
    for(int j=y; j<=m;j++)
            maior=max( maior , soma[i][j]-soma[i-x][j]-soma[i][j-y]+soma[i-x][j-y] );//guardo a soma desta submatriz se ela for a maior até agora
                  
    printf("%d\n",maior);
    
    system("pause");
    
    return 0;
}


/*
CASOS DE TESTE
==================

Entrada
2 5 2 2
1 2 3 4 5
1 2 3 4 5

Saída
18

Entrada
10 10 3 3
 1  2  3  4  5  6  7  8  9 10 
11 12 13 14 15 16 17 18 19 20
21 22 23 24 25 26 27 28 29 30
31 32 33 34 35 36 37 38 39 40
41 42 43 44 45 46 47 48 49 50
51 52 53 54 55 56 57 58 59 60 
61 62 63 64 65 66 67 68 69 70 
71 72 73 74 75 76 77 78 79 80 
81 82 83 84 85 86 87 88 89 90 
91 92 93 94 95 96 97 98 99 100

Saída
801

*/
