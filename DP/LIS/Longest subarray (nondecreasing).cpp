void solve() {
    ll t, k, x, y;
    cin >> n;
    ll a[n];
    f(i, n) cin >> a[i];
    ll mx = 1, curMx = 1, back = -1;
    fa(i, 1, n){
        if(a[i] >= a[i - 1]){
            mx++;
        }else{
            mx = 1;
        }
        curMx = max(mx, curMx);
    }
    cout << curMx << endl;
} 
