#include<cstdio>
#include<conio.h>

int num;

void fibonacci(int,int,int);

int main()
{
	int a, b, i;

	printf("Enter your numbers : \n");

	while(scanf("%d", &num)!=EOF){
		
		printf("0 1");
		fibonacci(0,1,0);
		printf("\n");
	
	}

	getch();
	return 0;
}


void fibonacci(int a, int b, int i){
	
	if( (a+b) <= num ){
			if(i++%2==0)
				printf(" %d", a=a+b);
			else
				printf(" %d", b=a+b);
		fibonacci(a,b,i);
	}
	
	return ;
}