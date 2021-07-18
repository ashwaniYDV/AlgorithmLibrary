// Method 1

void extraLongFactorials(int n) {
    vector<int> res;
    res.push_back(1);
    int carry = 0;
    for(int i = 2; i <= n; i++) {
        for(int j = 0; j < res.size(); j++) {
            int prod = res[j] * i + carry;
            res[j] = prod % 10;
            carry = prod / 10;
        }
        while(carry) {
            res.push_back(carry % 10);
            carry /= 10;
        }
    }
    for(int i = res.size() - 1; i >= 0; i--) {
        cout << res[i];
    }
    cout << endl;
}

void solve() {
    cin >> n;
    extraLongFactorials(n);
}















// Method 2

vector<int> multiplyDecimal(vector<int> a, int n) {
    int carry = 0;
    for(int j = 0; j < a.size(); j++) {
        int prod = a[j] * n + carry;
        a[j] = prod % 10;
        carry = prod / 10;
    }
    while(carry) {
        a.push_back(carry % 10);
        carry /= 10;
    }
    return a;
}

void extraLongFactorials(int n) {
    vector<int> res;
    res.push_back(1);
    for(int i = 1; i <= n; i++) {
        res = multiplyDecimal(res, i);
    }

    for(int i = res.size() - 1; i >= 0; i--) {
        cout << res[i];
    }
    cout << endl;
}

void solve() {
    cin >> n;
    extraLongFactorials(n);
}
