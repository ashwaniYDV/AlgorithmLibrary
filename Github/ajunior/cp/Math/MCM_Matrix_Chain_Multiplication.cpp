#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 15
#define linha 0
#define coluna 1
#define abre 0
#define fecha 1
#define INF 999999999
#define min(A,B) ((A)<(B)?(A):(B))
//GLOBAIS---------------//
int matriz[MAXN][2];    //
long TABELA[MAXN][MAXN];//
int volta[MAXN][MAXN];  //         
int parenteses[MAXN][2];//
//----------------------//

long Cquebra(int i,int aux, int j){
      return (matriz[i][linha] * matriz[aux][coluna] * matriz[j][coluna]);     
}

long Cmin(int i,int j){
      
       if(i==j) return 0;
       if(TABELA[i][j]!=-1) return TABELA[i][j];
      
       int aux,custo,minimo=INF;
      
       for(aux=i;aux<j;aux++){
            custo=(Cmin(i,aux) + Cmin(aux+1,j) + Cquebra(i,aux,j));
            minimo=min(minimo,custo);
            if(minimo==custo){
                volta[i][j]=aux;             
            }
       }
      
       TABELA[i][j]=minimo;
      
       return minimo;
}

void faz_volta(int i,int j){
      
       if(i!=j){
             
       parenteses[i-1][abre]++;
       parenteses[j][fecha]++;
         
       if(volta[i][j]){
            faz_volta(i,volta[i][j]);
            faz_volta(volta[i][j]+1,j);
       }
      
       }
}

int main(){
   
    int n,i,j,teste=0;
   
    while(1){
   
    scanf("%d",&n);
   
    if(n==0) break;
   
    for(i=1;i<=n;i++){
       scanf("%d %d",&matriz[i][linha],&matriz[i][coluna]);              
    }
   
    memset(volta,0,sizeof(volta));//seto volt anão iniciada
    memset(parenteses,0,sizeof(parenteses));//zero parenteses
    memset(TABELA,-1,sizeof(TABELA));//seto tabela não incializada
   
    Cmin(1,n);
   
   
    faz_volta(1,n);
   
    teste++;
    printf("Case %d: ",teste);
   
    for(i=0;i<=n;i++){
        if(i==0){
            for(j=1;j<=parenteses[i][abre];j++)
                printf("(");           
        }
       
        else{
            
            
             printf("A%d",i);
            
             for(j=1;j<=parenteses[i][fecha];j++) printf(")");
             if(i!=n) printf(" x ");
             for(j=1;j<=parenteses[i][abre];j++) printf("(");
            
        }
    }
   
    printf("\n");
   
    }
   
    return 0;
}
 
