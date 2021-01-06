#include <stdio.h>
#include <stdlib.h>

#define MAXN 100005

int memoria[MAXN];//PD: memoria para guardar os valores e evitar recálculo

int fibonacci(int a){
    
    if(a==0) return 0;
    if(a==1) return 1;
    
    if(memoria[a]!=-1) return memoria[a]; //PD: se já calculei o fibonacci de a, não recalculo
    
    memoria[a]=fibonacci(a-1) + fibonacci(a-2);//PD: guardo na memoria para evitar recálculos posteriores
    
    return memoria[a];
}

int main(){
    
    int n;
    
    scanf("%d",&n);
    
    for(int i=0;i<=n;i++) memoria[i]=-1;//PD: inicializo memória utilizada pela Prog. Dinâmica
    
    printf("%d", fibonacci(n) );
    
    return 0;
} 

