#include<stdio.h>
#include<cmath>
#include<time.h>
#include<conio.h>

#define MAX 1000000

bool isprime(int);

int main()
{
	int i,Number_of_Prime=1;  //Number_of_Prime = 1 ; because 2 is only even prime number and so initially we count it as 1.
	clock_t time,start;

	start=clock();

	for(i=3;i<=MAX;i+=2){
		if(isprime(i))
			Number_of_Prime++;
	}

	time=clock()-start;
	
	printf("Total Prime : %d\n", Number_of_Prime);
	printf("Total Time : %.15f\n", ((double)time)/CLOCKS_PER_SEC);

	getch();
	return 0;
}

bool isprime(int n){
	
	int squreroot,i;

	squreroot = (int) sqrt(n);

	for(i=2;i<=squreroot;i++){
		if(n%i==0)
			return false;
	}

	return true;
}