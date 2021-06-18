// https://cp-algorithms.com/string/prefix-function.html


// generates PI array (or LPS [largest prefix suffix])
vector<int> prefix_function(string &s) {
    int n = (int)s.length();
    vector<int> pi(n);
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
    return pi;
}

vector<int> find_occurences(string &text, string &pattern){
    string cur = pattern + '#' + text;
    int sz1 = text.size(), sz2 = pattern.size();
    vector<int> v;
    vector<int> lps = prefix_function(cur);

    for(int i = sz2 + 1; i <= sz1 + sz2; i++) {
        if(lps[i] == sz2) {
            v.push_back(i - 2 * sz2);
        }
    }
    return v;
}

void solve(){
    string s, pat;
    cin >> s >> pat;
    vector<int> res = find_occurences(s, pat);
    for(int x: res) cout << x << " ";
}

int32_t main() {
    IOS
    clock_t begin = clock();
    ll T = 1;
    // cin >> T;
    while(T--)
    solve();
    cerr<<"Time elapsed : "<<(clock()-begin)*1000.0/CLOCKS_PER_SEC<<"ms"<<'\n';
    return 0;
}

/*
INP:
ashwaniashwani
ash

OUT:
0 7
*/
