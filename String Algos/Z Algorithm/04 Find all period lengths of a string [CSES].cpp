/*
Problem Name: Finding Periods
Problem Link: https://cses.fi/problemset/task/1733
*/

/*
A period of a string is a prefix that can be used to generate the whole string by repeating the prefix. 
The last repetition may be partial. For example, the periods of abcabca are abc, abcabc and abcabca.
Your task is to find all period lengths of a string.

Input:
The only input line has a string of length n consisting of characters a–z.
Output:
Print all period lengths in increasing order.
Constraints
1≤n≤10^6

Example
Input:
abcabca

Output:
3 6 7
*/

vector<int> z_function(string s) {
    int n = (int) s.length();
    vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r)
            z[i] = min (r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    return z;
}

void solve() {
    string s;
    cin >> s;
    n = s.size();
    vector<int> z = z_function(s);
    for(int i = 0; i < n; i++) {
        if(i + z[i] == n) cout << i << " ";
    }
    cout << n << endl;
}
