// https://cp-algorithms.com/string/string-hashing.html

/*
The good and widely used way to define the hash of a string s of length n is:
hash(s) = (s[0] + s[1]⋅p + s[2]⋅p^2 + ... + s[n-1] ⋅ p^(n−1)) mod m
        = (i from 0 to n-1) ∑(s[i]⋅p^i) mod m
where p and m are some chosen, positive numbers. 
It is called a polynomial rolling hash function.

It is reasonable to make p a prime number roughly equal to the number of characters in the input alphabet. 
For example, if the input is composed of only lowercase letters of the English alphabet, p = 31 is a good choice. 
If the input may contain both uppercase and lowercase letters, then p = 53 is a possible choice.
*/


// Calculation of the hash of a string
long long compute_hash(string const& s) {
    const int p = 31;
    const int m = 1e9 + 9;
    long long hash_value = 0;
    long long p_pow = 1;
    for (char c : s) {
        hash_value = (hash_value + (c - 'a' + 1) * p_pow) % m;
        p_pow = (p_pow * p) % m;
    }
    return hash_value;
}

/*
Precomputing the powers of p might give a performance boost.
*/





/*
Problem:
Given a list of n strings si, each no longer than m characters, find all the duplicate strings and divide them into groups.
*/

// Search for duplicate strings in an array of strings
vector<vector<int>> group_identical_strings(vector<string> const& s) {
    int n = s.size();
    vector<pair<long long, int>> hashes(n);
    for (int i = 0; i < n; i++)
        hashes[i] = {compute_hash(s[i]), i};

    sort(hashes.begin(), hashes.end());

    vector<vector<int>> groups;
    for (int i = 0; i < n; i++) {
        if (i == 0 || hashes[i].first != hashes[i-1].first)
            groups.emplace_back();
        groups.back().push_back(hashes[i].second);
    }
    return groups;
}










// Determine the number of different substrings in a string
int count_unique_substrings(string const& s) {
    int n = s.size();

    const int p = 31;
    const int m = 1e9 + 9;
    vector<long long> p_pow(n);
    p_pow[0] = 1;
    for (int i = 1; i < n; i++)
        p_pow[i] = (p_pow[i-1] * p) % m;

    vector<long long> h(n + 1, 0);
    for (int i = 0; i < n; i++)
        h[i+1] = (h[i] + (s[i] - 'a' + 1) * p_pow[i]) % m;

    int cnt = 0;
    for (int l = 1; l <= n; l++) {
        set<long long> hs;
        for (int i = 0; i <= n - l; i++) {
            long long cur_h = (h[i + l] + m - h[i]) % m;
            cur_h = (cur_h * p_pow[n-i-1]) % m;
            hs.insert(cur_h);
        }
        cnt += hs.size();
    }
    return cnt;
}
