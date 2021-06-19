// https://youtu.be/uFPSFsOlklE

/*
In Z algo z[0] doesn't matter. It can be anything
*/

// method 2
vector<ll> z_function(string s){
	ll n=s.size();
	vector<ll> z(n);
	for(ll i=1,l=0,r=0;i<n;i++){
		if(i<=r){
			z[i]=min(r-i+1, z[i-l]);
		}
		while(i+z[i]<n && s[z[i]]==s[i+z[i]]) {
			z[i]++;
		}
		if(i+z[i]-1>r){
			l=i, r=i+z[i]-1;
		}
	}
	return z;
}

auto z_algo(string s) {
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
	auto z = z_algo(s);
	for(auto x: z) cout << x << " ";
}
