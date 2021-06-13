vector<int> rabin_karp(string const& str, string const& pat) {
    const int p = 31; 
    const int mod = 1e9 + 9;
    int n = str.size(), m = pat.size();

    vector<long long> p_pow(max(n, m)); 
    p_pow[0] = 1; 
    for (int i = 1; i < (int)p_pow.size(); i++) {
        p_pow[i] = (p_pow[i-1] * p) % mod;
    }

    vector<long long> h_str(n + 1, 0); 
    for (int i = 0; i < n; i++) {
        h_str[i+1] = (h_str[i] + (str[i] - 'a' + 1) * p_pow[i]) % mod; 
    }

    long long h_pat = 0; 
    for (int i = 0; i < m; i++) {
        h_pat = (h_pat + (pat[i] - 'a' + 1) * p_pow[i]) % mod; 
    }

    vector<int> occurences;
    for (int i = 0; i <= n - m; i++) { 
        long long cur_h = (h_str[i+m] - h_str[i] + mod) % mod; 
        // (cur_h / p_pow[i]) = h_pat
        if (cur_h == h_pat * p_pow[i] % mod) {
            occurences.push_back(i);
        }
    }
    return occurences;
}

void solve() {
    string str, pat;
    cin >> str >> pat;
    for(auto i: rabin_karp(str, pat)) cout << i << " ";
}
