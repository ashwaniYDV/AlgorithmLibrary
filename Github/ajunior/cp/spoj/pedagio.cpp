#include <stdio.h>
#include <string.h>
int c, e, l, p, inicio, fim, est[51][51], dist[51], fila[51];
int main(){
  int x, y, teste=1, prim;
  while (scanf("%d %d %d %d", &c, &e, &l, &p), c!= 0 && e!= 0 && l!=0 && p!=0){
	     memset(dist, -1, sizeof(dist));
    	dist[l] = 0;
        fila[0] = l;
        inicio = 0;
        fim = 1;

 	    for(int i = 0; i < e; i++)  {
		  scanf("%d %d", &x, &y);
	  		est[x][y] = 1;
			est[y][x] = 1;
		}
  
      while (inicio < fim && dist[fila[inicio]] < p){
		  prim = fila[inicio];
		  for (int i = 1; i <= c; i++)
		    if (est[prim][i] && dist[i] == -1)    {
				fila[fim++] = i;
				dist[i] = dist[prim] + 1;
     	 	 }
		  inicio++;
	  }
	  
      printf("Teste %d\n", teste++);
      for (int i = 1; i < c; i++){
		  if (i != l && dist[i] != -1)
		  	  printf("%d ", i);
		  }
	  printf("\n\n");
      }
      
  return 0;
}
			