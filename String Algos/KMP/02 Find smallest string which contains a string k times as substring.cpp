// ADAPET - Ada and Pet [SPOJ]
// https://www.spoj.com/problems/ADAPET/

/*
Problem:
Ada the Ladybug just got herself a new pet. She was thinking about a name for it. 
She thought-up a beautiful name for it already but now she doesn't think this name is "enough". 
She wants to find a new name, which will contain the original name at least K times as substring (to emphasize its importance). 
As ada doesn't want the pet's name to be too long, she wants to find the shortest one - can you find the length of it?


Input:
s = ada, k = 3

Output:
7

Explanation:
Required string = adadada
*/


int pi[500005];

// generates PI array (or LPS [largest prefix suffix])
void prefix_function(string &s) {
    int n = (int)s.length();
    pi[0] = 0;
    for (int i = 1; i < n; i++) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j]) {
            j = pi[j-1];
        }
        if (s[i] == s[j]) {
            j++;
        }
        pi[i] = j;
    }
}


void solve() {
    int x, y, k;
    string s;
    cin >> s >> k;
    n = s.length();
    prefix_function(s);

    cout << n + (k - 1) * (n - pi[n - 1]) << endl;
}

signed main() {
    IOS
    clock_t begin = clock();
    int t = 1;
    cin >> t;
    f(i, t) {
        solve();
    }
    cerr<<"Time elapsed: "<<(clock()-begin)*1000.0/CLOCKS_PER_SEC<<"ms"<<'\n';
}
