// faadcoder = https://youtu.be/uFPSFsOlklE
// codencode = https://youtu.be/hDKTCWWGIxk

/*
In Z algo z[0] doesn't matter. It can be anything
*/

/*
cp-algorithms:

Trivial algorithm (Naive approach)
Formal definition can be represented in the following elementary O(n^2) implementation.
*/
vector<int> z_function_trivial(string s) {
    int n = (int) s.length();
    vector<int> z(n);
    for (int i = 1; i < n; ++i)
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
    return z;
}


/*
cp-algorithms:

Efficient algorithm to compute the Z-function O(n)
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








int z[1000000+5];
void z_function(string s) {
    int n = (int) s.length();
    memset(z, 0, sizeof z);
    z[0] = 0;
    int l = 0, r = 0;
    for (int i = 1; i < n; ++i) {
        if (i <= r)
            z[i] = min (r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
}






// method 2
auto z_function(string s) {
	ll n = s.size();
	ll l = 0, r = 0;
	vector<ll> z(n, 0);
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
	return z;
}

void solve() {
	ll k, q, t;
	string s;
	cin >> s;
	auto z = z_function(s);
	for(auto x: z) cout << x << " ";
}
