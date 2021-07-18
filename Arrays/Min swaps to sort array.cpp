/*
Given an array of N distinct elements, find the minimum number of swaps required to sort the array.
Eg:
6
{ 3, 5, 2, 4, 6, 8}
*/


// NOTE: Array must have distinct elements for the below solutions.

void fun1(vl a) {
    vector<ll> b = a;
    sort(all(b));
    map<ll, ll> mp;
    f(i, n){
        mp[b[i]] = i;
    }

    ll ct = 0;
    f(i, n){
        if(a[i] == b[i]) continue;

        ll pos = mp[a[i]];
        swap(a[i], a[pos]);
        ct++;
        i--;
    }
    cout << ct << endl;
}

/*
Minimum number of swaps required to sort an array of first N number (1.....n)
Eg:
5
{2, 1, 3, 5, 4}
*/
void fun2(vl a) {
    ll ct = 0;
    f(i, n){
        if(a[i] == i + 1) continue;

        swap(a[i], a[a[i] - 1]);
        ct++;
        i--;
    }
    cout << ct << endl;
}

void solve() {
    ll t, k, x, y, u, v;
    cin >> n;
    vector<ll> a(n);
    f(i, n) cin >> a[i];
    fun1(a);

    cin >> n;
    a = vector<ll>(n);
    f(i, n) cin >> a[i];
    fun2(a);
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
6
3 5 2 4 6 8
4
4 3 1 2

OUT:
3
3
*/
