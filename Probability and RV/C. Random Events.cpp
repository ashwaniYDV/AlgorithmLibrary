// https://codeforces.com/contest/1461/problem/C

/*
total prob = (success1) + (filure1*success2) + (filure1*filure2*success3) + (filure1*filure2*filure3*success4) + ...........
*/


void solve() {
    int x, y, z, u, v;
    cin >> n >> m;
    int a[n+1];
 
    // index = largest i such that a[i] != i
    int index = 0;
    loop(i, 1, n) {
        cin >> a[i];
        if(a[i] != i) index = i;
    }
 
    double ans = 0.0;
    double prevFail = 1.0;
    double prob;
    f(i, m) {
        cin >> x >> prob;
        if(x >= index) {
            ans += prob*prevFail;
            prevFail *= (1 - prob);
        }
    }
 
    if(index == 0) {
        cout << 1.000000 << endl;
        return;
    }
 
    cout << ans << endl;
 
}














/*
Method 2
total prob = 1 - allFailure;
           = 1 - (failure1*failure2*failure3*....)
*/

void solve() {
    int x, y, z, u, v;
    cin >> n >> m;
    int a[n+1];

    // index = largest i such that a[i] != i
    int index = 0;
    loop(i, 1, n) {
        cin >> a[i];
        if(a[i] != i) index = i;
    }

    double allFail = 1.0;
    f(i, m) {
        double prob;
        cin >> x >> prob;
        if(x >= index) {
            allFail *= (1 - prob);
        }
    }

    if(index == 0) {
        cout << 1.000000 << endl;
        return;
    }
    
    double ans = 1 - allFail;
    cout << ans << endl;

}
