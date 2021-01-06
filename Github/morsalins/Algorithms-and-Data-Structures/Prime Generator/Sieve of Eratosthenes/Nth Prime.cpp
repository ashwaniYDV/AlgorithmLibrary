#include<cstdio>
#include<ctime>
#include<cmath>
#include<conio.h>


#define MAX 1000000

void sieve(void);

bool prime[MAX+10];

int main()
{
	long int i,n, NumberofPrime;		
	
	sieve();
	
	printf("Enter your numbers to find the Nth Prime : \n");
	printf("------------------------------------------\n");
	
	while(scanf("%d", &n)!=EOF){
		
		i=1; NumberofPrime=0;
		while(NumberofPrime<n){
		
			i++;
		
			if(prime[i])
				NumberofPrime++;
		}
	

		printf("The #%d Prime is: %d\n", n,i);
	
	}
	
	printf("Press any key.....");
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