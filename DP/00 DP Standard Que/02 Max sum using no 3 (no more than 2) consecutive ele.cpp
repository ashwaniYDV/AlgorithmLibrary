// https://www.codechef.com/ZCOPRAC/problems/ZCO14004
// https://unacademy.com/class/learn-dp-through-problem-solving-3/URYJEHRL




const int N = 2e5 + 5;
int n, m;
int dp[N][3];

int go(int pos, int state, vector<int>& a) {
    if (pos >= n) return 0;

    if (dp[pos][state] != -1) return dp[pos][state];

    int x = 0, y = 0;
    if (state < 2) {
        x = a[pos] + go(pos + 1, state + 1, a);
    }
    y = go(pos + 1, 0, a);

    return dp[pos][state] = max(x, y);
}

void solve() {
    cin >> n;
    vector<int> a(n);
    f(i, n) cin >> a[i];
    memset(dp, -1, sizeof dp);
    cout << go(0, 0, a) << endl;
}










void solve() {
    cin >> n;
    vi a(n);
    f(i, n) cin >> a[i];

    if (n == 1) {
        cout << a[0] << endl;
        return;
    }
    if (n == 2) {
        cout << a[0] + a[1] << endl;
        return;
    }

    int dp[n] = {0};
    dp[0] = a[0];
    dp[1] = a[0] + a[1];
    dp[2] = max({a[0] + a[1], a[0] + a[2], a[1] + a[2]});

    fa(i, 3, n) {
        dp[i] = max({dp[i - 1], a[i] + dp[i - 2], a[i] + a[i - 1] + dp[i - 3]});
    }

    cout << dp[n - 1] << endl;
}











// Time = O(n * k), Space = O(n)
const int N = 1e5 + 5;
int n, m, k;


void solve() {
    cin >> n;
    vector<int> a = vector<int>(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];

    k = 2;

    if (n <= k) {
        int res = 0;
        for (int i = 1; i <= n; i++) res += a[i];
        cout << res << endl;
        return;
    }

    vector<int> dp(n + 1);
    dp[0] = 0;
    for (int i = 1; i <= k; i++) {
        dp[i] = dp[i - 1] + a[i];
    }

    for (int i = k + 1; i <= n; i++) {
        dp[i] = dp[i - 1];
        int sum = 0;
        for (int j = i; j > i - k; j--) {
            sum += a[j];
            dp[i] = max(dp[i], sum + dp[j - 2]);
        }
    }

    cout << dp[n] << endl;
}
