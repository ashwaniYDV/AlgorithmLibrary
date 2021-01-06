#include<cstdio>
#include<conio.h>

int main()
{
	int num, a, b, i;

	printf("Enter your numbers : \n");

	while(scanf("%d", &num)!=EOF){

		
/**********Fibonacci Logic**********/
		printf("%d %d", a=0,b=1);
		i=0;

		while( (a+b) <= num ){
			if(i++%2==0)
				printf(" %d", a=a+b);
			else
				printf(" %d", b=a+b);
		}
/**********Fibonacci Logic**********/

	}

	getch();
	return 0;
}
