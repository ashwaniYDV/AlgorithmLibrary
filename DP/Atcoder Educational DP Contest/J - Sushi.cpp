// https://atcoder.jp/contests/dp/tasks/dp_j
// https://youtu.be/XRVCU2Ys9Mk

/*
NOTE: The order in which dishes are places is of no use to us.
We just want at any time count of dishes with 0, 1, 2, 3 number of shushies

dp[x][y][z][w] = answer when we have (x = count of dishes with 3 shushies, 
                                    y = count of dishes with 2 shushies, 
                                    z = count of dishes with 1 shushies, 
                                    w = count of dishes with 0 shushies)


Since x + y + z + w = n
Therefore we can redce a state as:

dp[x][y][z] = answer when we have (x = count of dishes with 3 shushies, 
                                    y = count of dishes with 2 shushies, 
                                    z = count of dishes with 1 shushies)
Count of dishes with 0 shushies = n - x - y - z

Base case:
dp[0][0][0] = 0
Since expected number of times the operation is performed before all the pieces of sushi are eaten = 0.

p0 = probability of picking a dish with 0 shushy
p1 = probability of picking a dish with 1 shushy
p2 = probability of picking a dish with 2 shushies
p3 = probability of picking a dish with 3 shushies

dp[x][y][z] = 1 + p3 * dp[x-1][y+1][z] + p2 * dp[x][y-1][z+1] + p1 * dp[x][y][z-1] + p0 * dp[x][y][z]

But in above equation dp[x][y][z] depends on dp[x][y][z]
Therefore bringing the right term on left side

dp[x][y][z] - p0 * dp[x][y][z] = 1 + p3 * dp[x-1][y+1][z] + p2 * dp[x][y-1][z+1] + p1 * dp[x][y][z-1]
dp[x][y][z] * (1 - p0)         = 1 + p3 * dp[x-1][y+1][z] + p2 * dp[x][y-1][z+1] + p1 * dp[x][y][z-1]
dp[x][y][z]                    = (1 + p3 * dp[x-1][y+1][z] + p2 * dp[x][y-1][z+1] + p1 * dp[x][y][z-1]) / (1 - p0)
*/


// Method 1
ld dp[305][305][305];

void solve() {
    int x;
    cin >> n;
    vi cnt(4, 0);

    f(i, n) {
        cin >> x;
        cnt[x]++;
    }

    // base case (zero = n)
    dp[0][0][0] = 0;

    for (int three = 0; three <= n; three++) {
        for (int two = 0; two <= n; two++) {
            for (int one = 0; one <= n; one++) {
                int zero = n - one - two - three;
                
                // this is base case already covered
                if(zero == n) {
                    continue;
                }

                // not possible state
                if(one + two + three > n) {
                    continue;
                }

                ld value = 1.0;

                ld p0 = (1.0 * zero / n);
                ld p1 = (1.0 * one / n);
                ld p2 = (1.0 * two / n);
                ld p3 = (1.0 * three / n);

                // pick 3
                if(three > 0)
                    value += p3 * dp[three - 1][two + 1][one]; 

                // pick 2
                if(two > 0)
                    value += p2 * dp[three][two - 1][one + 1]; 

                // pick 1
                if(one > 0)
                    value += p1 * dp[three][two][one - 1]; 

                value /= (1 - p0);

                dp[three][two][one] = value;
            }
        }
    }

    cout << dp[cnt[3]][cnt[2]][cnt[1]] << endl;
}

signed main() {
    IOS
    int t = 1;
    PRECISION(10)
    // cin >> t;
    f(i, t) {
        solve();
    }
}










































// Method 2
ld dp[305][305][305];

void solve() {
    int x;
    cin >> n;
    vi cnt(4, 0);

    f(i, n) {
        cin >> x;
        cnt[x]++;
    }

    // base case (zero = n)
    dp[0][0][0] = 0;

    for (int three = 0; three <= n; three++) {
        for (int two = 0; two <= n; two++) {
            for (int one = 0; one <= n; one++) {
                int zero = n - one - two - three;
                
                // this is base case already covered
                if(zero == n) {
                    continue;
                }

                // not possible state
                if(one + two + three > n) {
                    continue;
                }

                ld value = 1.0;

                ld p0 = (1.0 * zero / n);
                ld p1 = (1.0 * one / n);
                ld p2 = (1.0 * two / n);
                ld p3 = (1.0 * three / n);

                // pick 1
                if(one > 0)
                    value += p1 * dp[one - 1][two][three]; 

                // pick 2
                if(two > 0)
                    value += p2 * dp[one + 1][two - 1][three]; 

                // pick 3
                if(three > 0)
                    value += p3 * dp[one][two + 1][three - 1]; 

                value /= (1 - p0);

                dp[one][two][three] = value;
            }
        }
    }

    cout << dp[cnt[1]][cnt[2]][cnt[3]] << endl;
}

signed main() {
    IOS
    int t = 1;
    PRECISION(10)
    // cin >> t;
    f(i, t) {
        solve();
    }
}
