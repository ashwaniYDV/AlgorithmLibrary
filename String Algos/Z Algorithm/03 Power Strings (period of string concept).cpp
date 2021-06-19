// https://open.kattis.com/problems/powerstrings

/*
Given two strings a and b we define a⋅b to be their concatenation. 
For example, if a="abc" and b="def" then a⋅b="abcdef". 
If we think of concatenation as multiplication, exponentiation by a non-negative integer is defined in the normal way: 
a^0 = "" (the empty string) 
and a^(n+1) = a*(a^n).

Input
The input consists of up to 10 test cases. 
Each test case is a line of input containing s, a string of lower case letters (a-z). 
The length of s will be at least 1 and will not exceed 2000000 characters. 
A line containing a period (.) follows the last test case.

Output
For each s you should print the largest n such that s=an for some string a.
*/


int z[2000005];

void z_algo(string s) {
    ll n = s.size();
    ll l = 0, r = 0;
    z[0] = 0;
    for(ll i = 1; i < n; i++) {
        if(i > r) {
            l = r = i;
            while(r < n and s[r] == s[r - l]) {
                r++;
            }
            z[i] = r - l;
            r--;
        }else{
            ll idx = i - l;
            if(i + z[idx] <= r) {
                z[i] = z[idx];
            }else{
                l = i;
                while(r < n and s[r] == s[r - l]) {
                    r++;
                }
                z[i] = r - l;
                r--;
            }
        }
    }
}

void solve(string s) {
    n = s.length();
    z_algo(s);

    int period = 0;
    f(i, n) {
        if(i + z[i] == n) {
            period = i;
            break;
        }
    }

    if(period and (n % period == 0)) {
        cout << n / period << endl;
    } else {
        cout << 1 << endl;
    }
}

signed main() {
    IOS
    clock_t begin = clock();
    int t = 1;
    // cin >> t;
    while(1) {
        string s;
        cin >> s;
        if(s == ".") break;
        solve(s);
    }
    cerr<<"Time elapsed: "<<(clock()-begin)*1000.0/CLOCKS_PER_SEC<<"ms"<<'\n';
}
