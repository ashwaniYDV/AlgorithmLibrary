// ACM UVA Online Judge - 478 por Felipe Holanda
// holanda1@gmail.com
#include <stdio.h>
#include <math.h>

#define MAXRET 12
#define MAXN 12
#define min(A,B) ((A)<(B))?(A):(B)
#define max(A,B) ((A)>(B))?(A):(B)
#define epsilon 0.00000001
#define R 0
#define C 1
#define T 2

typedef struct{
        double x;
        double y;
}point;       

typedef struct {
        point p[3];
}rectangle;
rectangle retangulo[MAXRET];

typedef struct{
        double raio;
        point centro;
}circle;
circle circulo[MAXN];

typedef struct{
        point vertice[4];
}triangle;
triangle triangulo[MAXN];

int retcirc[MAXN];

int ccw(point a, point b, point c){
   
    double conta= (   (a.x*b.y) + (b.x*c.y) + (c.x*a.y)
                     -(a.y*b.x) - (b.y*c.x) - (c.y*a.x) );
    
    if(conta > epsilon) return 1;        //o maior evita na borda
    if(fabs(conta) > epsilon) return -1;
    return 0;
}

int test(double x,double y, int i){
   
    if( x >= retangulo[i].p[1].x || x <= retangulo[i].p[2].x  ) return 0;
    if( y >= retangulo[i].p[2].y || y <= retangulo[i].p[1].y  ) return 0;
    return 1;
}

int nocirculo(double x, double y, int i){
   
    double distancia,craio;
   
    distancia=(x-circulo[i].centro.x)*(x-circulo[i].centro.x);
    distancia+=(y-circulo[i].centro.y)*(y-circulo[i].centro.y);
   
    craio=circulo[i].raio*circulo[i].raio;
       
    if( (distancia-craio) >= epsilon ) return 0;
    return 1;
}

int notriangulo(double x, double y,int i){
   
    point teste;
   
    teste.x=x;
    teste.y=y;

    if( ccw(teste,triangulo[i].vertice[1],triangulo[i].vertice[2]) ==1)
    if( ccw(teste,triangulo[i].vertice[2],triangulo[i].vertice[3]) ==1)
    if( ccw(teste,triangulo[i].vertice[3],triangulo[i].vertice[1]) ==1)
           return 1;
   
    if( ccw(teste,triangulo[i].vertice[1],triangulo[i].vertice[2]) ==-1)
    if( ccw(teste,triangulo[i].vertice[2],triangulo[i].vertice[3]) ==-1)
    if( ccw(teste,triangulo[i].vertice[3],triangulo[i].vertice[1]) ==-1)
           return 1;
   
    return 0;  
}

int main(){
   
    char oqeh;
    double xa,xb,ya,yb,xc,yc,raio;
    int nfig=0;
   
    while ( scanf(" %c",&oqeh) ) {
   
    if(oqeh=='r'){   
       nfig++;
       retcirc[nfig]=R;          
       scanf("%lf %lf %lf %lf",&xa,&ya,&xb,&yb);
      
       retangulo[nfig].p[1].x= max(xa,xb);
       retangulo[nfig].p[1].y= min(ya,yb);
      
       retangulo[nfig].p[2].x= min(xa,xb);
       retangulo[nfig].p[2].y= max(ya,yb);
    }
   
    else if(oqeh=='c'){
       nfig++;
       retcirc[nfig]=C;
       scanf("%lf %lf %lf",&xa,&ya,&raio);
      
       circulo[nfig].centro.x=xa;
       circulo[nfig].centro.y=ya;
      
       circulo[nfig].raio=raio;
    }
   
    else if(oqeh=='t'){
       nfig++;
       retcirc[nfig]=T;
       scanf("%lf %lf %lf %lf %lf %lf",&xa,&ya,&xb,&yb,&xc,&yc);
      
       triangulo[nfig].vertice[1].x=xa;
       triangulo[nfig].vertice[1].y=ya;
   
       triangulo[nfig].vertice[2].x=xb;
       triangulo[nfig].vertice[2].y=yb;
      
       triangulo[nfig].vertice[3].x=xc;
       triangulo[nfig].vertice[3].y=yc;
    }
   
   
    else break;
    }
   
    int np=0;
    int aux;
    double x,y;
   
    while( scanf("%lf %lf",&x,&y) != EOF){
      
       if(fabs(x-9999.9)<=epsilon && fabs(y-9999.9)<=epsilon) break;
      
       np++;
       aux=1;
      
       for(int i=1;i<=nfig;i++){
              
          if(retcirc[i]==R)            
          if( test(x,y,i)==1 ){ printf("Point %d is contained in figure %d\n",np,i); aux=0;}
         
          if(retcirc[i]==C)
          if( nocirculo(x,y,i)==1){ printf("Point %d is contained in figure %d\n",np,i); aux=0; }
         
          if(retcirc[i]==T)
          if( notriangulo(x,y,i)==1){ printf("Point %d is contained in figure %d\n",np,i); aux=0; }
      
       }
      
       if(aux)  printf("Point %d is not contained in any figure\n",np);
      
    }
   
    return 0;
}
 
