
// add n strings of given base

string addStringsOfBase(string s1, string s2, int base) {
    string res = "";

    int i = s1.size() - 1, j = s2.size() - 1;
    int carry = 0;
    while(i >= 0 || j >= 0 || carry > 0) {
        int digit1 = 0, digit2 = 0;
        if(i >= 0) {
            digit1 = s1[i] - '0';
        }
        if(j >= 0) {
            digit2 = s2[j] - '0';
        }

        int total = digit1 + digit2 + carry;
        res = char('0' + total % base) + res;

        carry = total / base;
        i--, j--;
    }

    return res;
}

void solve() {
    int n, base;
    cin >> n >> base;
    vector<string> a(n);
    f(i, n) cin >> a[i];

    string res = "0";
    f(i, n) {
        res = addStringsOfBase(res, a[i], base);
    }
    cout << res;
}


/*
Input:
9 10
213124234234
43
5346365464
54645645
56456456457457
54647457
7457
4575675756785685
66797075677

Output:
4632417590219119
*/
