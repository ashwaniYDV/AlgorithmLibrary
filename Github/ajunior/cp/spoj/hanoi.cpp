#include <stdio.h>


void hanoi(int n, int orig, int dest, int temp){
	if(n==1){
		dest = orig;
	}else{
		hanoi(n-1, orig,temp,dest);
		dest = orig;
		hanoi(n-1, temp, dest, orig);
	}
}




int main(){
	
	int n, cont = 0;
	
	while(1){
		scanf("%d",n);
		if(n==0)break;
		temp = n-1;
		
		res = (temp*2)+1
		
		
		
		
	}
	
	
	return 0;
}