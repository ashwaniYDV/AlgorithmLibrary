#include <bits/stdc++.h>

using namespace std;

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

int main()
{
    int n;
    cin >> n;
    extraLongFactorials(n);
    return 0;
}
