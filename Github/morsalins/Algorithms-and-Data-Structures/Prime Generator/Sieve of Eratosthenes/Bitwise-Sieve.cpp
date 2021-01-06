#include<cstdio>
#include<iostream>
#include<ctime>
#include<conio.h>

#define MAX 100000000
#define LMT 10000

using namespace std;

unsigned flag[MAX>>6];

#define ifc(n) (flag[n>>6]&(1<<((n>>1)&31)))
#define isc(n) (flag[n>>6]|=(1<<((n>>1)&31)))

void bitWiseSieve(void);

int main()
{
	//freopen("i.txt", "r", stdin);
	//freopen("o.txt", "w", stdout);

	int i;
	clock_t start,time;

	start=clock();
	bitWiseSieve();
	time=clock()-start;

	/*****Printing all the prime*****/
	/*for(i = 3; i < MAX>>6; i += 2)
		if(!ifc(i)) 
			printf("%d\n", i);*/

	
	/*****Find a individual number is Prime or not*****/
	/*long long int p=0;
	printf("Please enter your numbers (enter negetive integer to terminate input) : \n");
	while(p>-1){

		printf("number: ");
		scanf("%lld", &p);
		if( p==2 )
			printf("%lld is a prime\n", p);
		else if( p!=1 && p%2==1 && !ifc(p) ) 
			printf("%lld is a prime\n", p);
		else 
			printf("%lld is not a prime\n", p);
	}*/

	printf("Total time : %.15lf sec\n", ((double)time)/CLOCKS_PER_SEC);

	getch();
	return 0;
}
// End of main.

void bitWiseSieve(void){
	
	unsigned i, j, k;
    for(i=3; i<LMT; i+=2)
        if(!ifc(i))
            for(j=i*i, k=i<<1; j<MAX; j+=k)
                isc(j);
}