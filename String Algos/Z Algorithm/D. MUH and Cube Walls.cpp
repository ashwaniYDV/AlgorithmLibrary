// https://codeforces.com/problemset/problem/471/D
// https://youtu.be/GFFum0JXmjo


auto z_algo(vector<ll> s) {
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
	ll w;
	cin >> n >> w;
	vector<ll> str(n), pat(w);
	f(i, n) cin >> str[i];
	f(i, w) cin >> pat[i];
	vector<ll> s, p;
	for(ll i = 0; i < n-1; i++) {
		s.pb(str[i+1] - str[i]);
	}
	for(ll i = 0; i < w-1; i++) {
		p.pb(pat[i+1] - pat[i]);
	}

	vector<ll> tot;
	for(ll x: p) tot.pb(x);

	// special character 1e10
	tot.pb(10000000000);

	for(ll x: s) tot.pb(x);

	auto z = z_algo(tot);
	ll ans = 0;
	for(auto x: z) {
		if(x == p.size()) ans++;
	}
	cout << ans << endl;
}

int32_t main() {
	IOS
	ll T;
	// cin >> T;
	// while(T--)
	solve();
	cerr<<"Time elapsed : "<<clock()*1000.0/CLOCKS_PER_SEC<<"ms"<<'\n'; 
	return 0;
}
