// https://codeforces.com/contest/527/problem/A


int gcd(int a, int b) {
    if(b == 0) return 0;
    return (a / b) + gcd(b, a % b);
}


void solve() {
    cin >> n >> m;
    cout << gcd(n, m) << endl;
}
 
 
int32_t main() {
    IOS
    int T = 1;
    // cin >> T;
    while(T--)
    solve();
    return 0;
}
