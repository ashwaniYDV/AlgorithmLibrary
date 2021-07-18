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
    string s = pattern + '#' + text;
    int t = text.size(), p = pattern.size();

    vector<int> lps = prefix_function(s);
    int n = lps.size();

    vector<int> res;

    for(int i = p + 1; i < n; i++) {
        if(lps[i] == p) {
            res.push_back(i - 2 * p);
        }
    }
    return res;
}

void solve(){
    string s, pat;
    cin >> s >> pat;
    vector<int> res = find_occurences(s, pat);
    for(int x: res) cout << x << " ";
}

/*
INP:
ashwaniashwani
ash

OUT:
0 7
*/
