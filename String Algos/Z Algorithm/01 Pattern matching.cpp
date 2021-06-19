auto z_algo(string s) {
	ll n = s.size();
	ll l = 0, r = 0;
	vector<ll> z(n);
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
	return z;
}

void solve() {
	ll k, q, t;
	string s, pat;
	cin >> s >> pat;
	string tot = pat + "$" + s;
	auto z = z_algo(tot);
	for(ll i = 0; i < z.size(); i++) {
		if(z[i] == pat.size()) {
			cout << i - pat.size() - 1 << endl;
		}
	}
}
