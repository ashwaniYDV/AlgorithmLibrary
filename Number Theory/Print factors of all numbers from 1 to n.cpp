/*
Queestion: n = 6
Answer:
1 -> 1;
2 -> 1, 2
3 -> 1, 3
4 -> 1, 2, 4
5 -> 1, 5
6 -> 1, 2, 3, 6
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
