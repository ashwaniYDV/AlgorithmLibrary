// https://www.hackerearth.com/practice/data-structures/advanced-data-structures/fenwick-binary-indexed-trees/tutorial/


const int MAXN = 5e5+5;
const int N = 1e6+5;
int n, m, k;

int phi[MAXN + 1], pillai[MAXN + 1];
int a[N], BIT[N];

int inline mod(int x) {
    return (x % MOD + MOD) % MOD;
}

// Euler Phi Function in O(Nlog(logN)) [preprocessing time]
void init_phi() {
    for(int i = 1; i <= MAXN; i++) {
        phi[i] = i;
    }

    for(int i = 2; i <= MAXN; i++) {
        if(phi[i] == i) {
            for(int j = i; j <= MAXN; j += i) {
            phi[j] *= (i - 1);
            phi[j] /= i;
           } 
        }
    }
}

void init_pillai() {
    for(int i = 1; i <= MAXN; i++)
        for(int j = i; j <= MAXN; j += i) {
            pillai[j] += i * phi[j / i];
            pillai[j] = mod(pillai[j]);
        }
}

void update(int i, int val) {
    while(i <= n) {
        BIT[i] += val;
        i += (i&-i);
    }
}

int query(int i) {
    int sum = 0;
    while(i > 0) {
        sum += BIT[i];
        i -= (i&-i);
    }
    return sum;
}


void solve() {
    int t, x, y;
    init_phi();
    init_pillai();
    cin >> n;
    loop(i, 1, n) {
        cin >> a[i];
        update(i, pillai[a[i]]);
    }
    cin >> t;
    while(t--){
        char c;
        cin >> c >> x >> y;
        if (c == 'U') {
            // increment is added as update
            update(x, pillai[y] - pillai[a[x]]);
            a[x] = y;
        } else if (c == 'C') {
            cout << mod(query(y) - query(x - 1)) << '\n';
        }
    }
}
