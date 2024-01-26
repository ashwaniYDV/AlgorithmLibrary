// https://www.spoj.com/problems/RMQSQ/


const ll N = 1e6+5;
ll n, m;

ll st[4*N] , arr[N];

void build(ll si , ll ss , ll se) {
	if(ss == se) {
		st[si] = arr[ss];
		return;
	}
 
	ll mid = (ss + se)/2;
	build(2*si , ss , mid);
	build(2*si+1 , mid+1 , se);
 
	st[si] = min(st[2*si] , st[2*si+1]);
}

void update(ll si , ll ss , ll se , ll qi) {
	if(ss == se) {
		// here ss == se == qi
		st[si] = arr[qi];
		return;
	}

	ll mid = (ss + se) / 2;
	
	if(qi <= mid) update(2*si, ss, mid, qi);
	else update(2*si + 1, mid + 1, se, qi);

	st[si] = min(st[2*si], st[2*si + 1]);
}

ll query(ll si , ll ss , ll se , ll qs , ll qe) {
	if(qe < ss || qs > se)
		return INT_MAX;
 
	if(ss >= qs && se <= qe)
		return st[si];
 
	ll mid = (ss + se)/2;
	ll l = query(2*si , ss , mid , qs , qe);
	ll r = query(2*si+1 , mid+1 , se , qs , qe);
 
	return min(l , r);
}

void solve() {
	ll t, l, r;
	cin >> n;
	loop(i, 1, n) cin >> arr[i];
	build(1 , 1 , n);

	cin >> t;
	while(t--) {
		cin >> l >> r;
		cout << query(1 , 1 , n , l+1 , r+1)<<endl;
	}
}
