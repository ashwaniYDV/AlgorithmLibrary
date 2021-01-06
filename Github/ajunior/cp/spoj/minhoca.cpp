#include <stdio.h>
#include <string.h>
using namespace std;

int main(){
	int c, l,temp, maior = 0;
	scanf("%d %d", &l, &c);
	int mat[l][c];
	
	for(int i = 0; i < l; i++){
		temp = 0;
		for(int j = 0; j < c; j++){
			scanf("%d", &mat[i][j]);
			temp += mat[i][j];
			if(temp>maior){
				maior = temp;
			}		
		}
	}
		
		
		for(int i = 0; i < c; i++){
			temp = 0;
			for(int j = 0; j < l; j++){
				   	temp+= mat[j][i];
			}
			if(temp>maior){
				maior = temp;
			}
			
		}
		
		
		printf("%d\n", maior);
	
		
	
	
	
}