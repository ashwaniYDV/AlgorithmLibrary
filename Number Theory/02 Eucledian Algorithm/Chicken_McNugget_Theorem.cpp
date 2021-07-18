// https://artofproblemsolving.com/wiki/index.php/Chicken_McNugget_Theorem
// https://youtu.be/0Snuq77afU4

/* Chicken_McNugget_Theorem
--------------------------------
The Chicken McNugget Theorem (or Postage Stamp Problem or Frobenius Coin Problem) 
states that for any two relatively prime positive integers a, b [i.e gcd(a, b) = 1], 
the greatest integer that cannot be written in the form ax + by for nonnegative integers x, y is = (a * b - a - b).

A consequence of the theorem is that there are exactly 
[(a - 1)*(b - 1) / 2] positive integers which cannot be expressed in the form a*x + b*y. 
The proof is based on the fact that in each pair of the form (k, a*b-a-b-k), exactly one element is expressible.
*/



// https://www.codechef.com/problems/COPR16G
void solve() {
    int a, b;
    cin >> a >> b;
    int g = __gcd(a, b);
    if(g != 1) {
        cout << -1 << endl;
        return;
    }
    n = a*b - a - b + 1;
    cout << n << endl;
}
int32_t main() {
    IOS
    int T = 1;
    cin >> T;
    while(T--)
    solve();
    return 0;
}












// https://codeforces.com/contest/1245/problem/A

void solve() {
    int x, y;
    cin >> x >> y;
    if(__gcd(x, y) == 1) {
        cout << "Finite\n";
    } else {
        cout << "Infinite\n";
    }
}
