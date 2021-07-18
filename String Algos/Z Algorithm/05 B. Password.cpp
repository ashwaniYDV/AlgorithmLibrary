// https://codeforces.com/contest/126/problem/B


/*
Problem:
Find a substring t in the given string s such that t appears in begining, in middle and in back of s as substring 
(i.e t is longest prefix, suffix and infix of s).
Besides, from all acceptable variants find the longest one.

You are given string s. Find the substring t or determine that such substring does not exist.

NOTE:
The front, middle and back part can overlap but no two should overlap fully.
Exapmle:
Input   = aaaaaaaa
Outpput = aaaaaa
*/

int z[1000000+5];

void z_function(string s) {
    int n = s.size();
    int l = 0, r = 0;
    memset(z, 0, sizeof z);
    z[0] = 0;
    for(int i = 1; i < n; i++) {
        if(i > r) {
            l = r = i;
            while(r < n and s[r] == s[r - l]) {
                r++;
            }
            z[i] = r - l;
            r--;
        } else {
            int idx = i - l;
            if(i + z[idx] <= r) {
                z[i] = z[idx];
            } else {
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

void solve() {
    string s;
    cin >> s;
    n = s.size();
    z_function(s);

    int maxz = 0, res = 0;
    for (int i = 1; i < n; i++) {
        if (z[i] == n-i && maxz >= n-i) {
            res = n-i;
            break;
        }
        maxz = max(maxz, z[i]);
    }
    if(!res) cout << "Just a legend\n";
    else cout << s.substr(0, res) << endl;
}
