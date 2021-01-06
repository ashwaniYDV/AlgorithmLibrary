#include<cstdio>
#include<ctime>
#include<cmath>
#include<conio.h>

#define MAX 1000000

void sieve(void);

bool prime[MAX+10];

int main()
{
	int i,n, NumberofPrime=0;		 //NumberofPrime=1 ; because 2 is the only even prime number and so we count it as 1
	clock_t start,time;

	start=clock();
	sieve();

	while(scanf("%d", &n) != EOF){
		if(prime[n]){
			NumberofPrime++;
			printf("%d-Yes\n",n);
		}else
			printf("%d-No\n",n);
	}
	time=clock()-start;

	printf("Total Prime : %d\n", NumberofPrime);
	printf("Total time : %.15lf sec\n", ((double)time)/CLOCKS_PER_SEC);


	getch();
	return 0;
}

void sieve(){
	int i,j,k;

	for(i=3;i<=MAX;i+=2)
		prime[i]=true;

	prime[2]=true;

	int squreroot= (int) sqrt(MAX);

	for(i=3;i<=squreroot+2;i+=2){
		if(prime[i]){
			for(j=i*i;j<MAX+2;j+=2*i){
				prime[j]=false;	 // Assigning false indicates that the number is not prime
			}
		}
	}

	return;
}
