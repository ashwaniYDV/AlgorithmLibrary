#include <cstdio>
#include <ctime>
#include <math.h>
#include <string>
#include <cstring>
#include <conio.h>

#define MAX 1000000

void sieve(void);

bool prime[MAX+10];

int main()
{
	int i,n, NumberofPrime=1;		 //NumberofPrime=1 ; because 2 is the only even prime number and so we count it as 1
	clock_t start,time;

	start=clock();
	sieve();

	for (i = 3; i <= MAX; i += 2){
		if(prime[i])
			NumberofPrime++;
	}
	time=clock()-start;

	printf("Total Prime : %d\n", NumberofPrime);
	printf("Total time : %.15lf sec\n", ((double)time)/CLOCKS_PER_SEC);

	getch();
	return 0;
}

void sieve(){

    memset(prime, true, sizeof prime); // Assume all the numbers are prime initially.
    prime[1] = false;
    int limit = sqrt(MAX) + 2;

    for (int i = 3; i <= limit; i += 2) {
        if (prime[i]) {
            for (int j = i * i, k = i << 1; j <= MAX; j += i) {
                prime[j] = false; // Assigning false which are not prime.
            }
        }
    }
	return;
}
