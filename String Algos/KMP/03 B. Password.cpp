// // https://codeforces.com/contest/126/problem/B


/*
Problem:
Find a substring t in the given string s such that t appears in begining, in middle and in back of s as substring (i.e t is longest prefix, suffix and infix of s).
Besides, from all acceptable variants find the longest one.
You are given string s. 
Find the substring t or determine that such substring does not exist.
NOTE:
The front, middle and back part can overlap but no two should overlap fully.
Exapmle:
Input   = aaaaaaaa
Outpput = aaaaaa
*/



/*
while loop case is used to handle this type of string
string  = q w e r t y q w e r t y q w e  r t  y
pi      = 0 0 0 0 0 0 1 2 3 4 5 6 7 8 9 10 11 12 
*/

int pi[1000000+5];

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
    string s;
    cin >> s;
    n = s.size();
    prefix_function(s);

    int mx = 0;
    for (int i = 0; i < n-1; ++i) {
        mx = max(mx, pi[i]);
    }
 
    int l = pi[n-1];
    while(l > 0 && l > mx) {
        l = pi[l - 1];
    }

    if (l == 0) {
        cout << "Just a legend";
        return;
    }
 
    cout << s.substr(0, l) << endl;
}

signed main() {
    IOS
    clock_t begin = clock();
    int t = 1;
    // cin >> t;
    f(i, t) {
        solve();
    }
    cerr<<"Time elapsed: "<<(clock()-begin)*1000.0/CLOCKS_PER_SEC<<"ms"<<'\n';
}
