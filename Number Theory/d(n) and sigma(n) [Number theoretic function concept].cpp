// https://cp-algorithms.com/algebra/divisors.html

/*
Question: Given a number n, find:
a) d(x) = the number of divisors for each x from 1 to n
b) sigma(x) = the sum of all the divisors for each x from 1 to n

Input:
10

Output:
1 2 2 3 2 4 2 4 3 4 
1 3 4 7 6 12 8 15 13 18 
*/


const int N = 1e7+5;
int n, m;

int sigma[N+5];
int Dn[N+5];

int spf[N+5];
bool prime[N+5];
void SieveAndSPF() {
	memset(prime, true, sizeof(prime));
	prime[0] = prime[1] = false;

	// marking smallest prime factor for every number to be itself.
	for (int i = 1; i < N; i++) spf[i] = i;
	
	for(int p=2; p*p<=N; p++) { 
		if (prime[p] == true) {
			for(int i=p*p;i<=N;i+=p) {
				prime[i] = false; 
				spf[i] = min(spf[i], p);
			}
		} 
	}
}

void d_of_n() {
	Dn[1] = 1;
	for(int i = 2; i <= n; i++) {
        if(prime[i]) {
        	// no of divisors of prime i = 2
            Dn[i] = 2;
            continue;
        }
        int x = i, y = spf[x];
        int tempDn = 1;
        while(x % y == 0) {
            x /= y;
            tempDn++;
        }

        // using Number-Theoretic-Function property of d(n): d(a*b) = d(a)*d(b), where a, b are coprime
        tempDn *= Dn[x];
        Dn[i] = tempDn;
    }

    for(int i = 1; i <= n; i++) {
        cout << Dn[i] << " ";
    }
    cout << endl;
}

void sigma_of_n() {
	sigma[1] = 1;
	for(int i = 2; i <= n; i++) {
        if(prime[i]) {
        	// divisors of prime i = (1 and i)
            sigma[i] = 1 + i;
            continue;
        }
        int x = i, y = spf[x], z = y;
        int tempSigma = 1;
        while(x % y == 0) {
            x /= y;
            tempSigma += z;
            z *= y;
        }

        // using Number-Theoretic-Function property of sigma: sigma(a*b) = sigma(a)*sigma(b), where a, b are coprime
        tempSigma *= sigma[x];
        sigma[i] = tempSigma;
    }

    for(int i = 1; i <= n; i++) {
        cout << sigma[i] << " ";
    }
    cout << endl;
}

void solve() {
	SieveAndSPF();

	cin >> n;
	d_of_n();
	sigma_of_n();
}
