/*
Input:
6

Output:
Factors of 1 -> 1 
Factors of 2 -> 1 2 
Factors of 3 -> 1 3 
Factors of 4 -> 1 2 4 
Factors of 5 -> 1 5 
Factors of 6 -> 1 2 3 6 
*/

/*
Important Property:
For any number x, the total number of factors of x is of the order cuberoot(x)
*/

// O(n*log(n))
void solve() {
    cin >> n;
    vector<int> factors[n+1];

    for(int i = 1; i <= n; i++) {
    	for(int j = i; j <= n; j += i) {
    		factors[j].pb(i);
    	}
    }

    for(int i = 1; i <= n; i++) {
    	cout << "Factors of " << i << " -> ";
    	for(int x: factors[i]) {
    		cout << x << " ";
    	}
    	cout << endl;
    }

}
