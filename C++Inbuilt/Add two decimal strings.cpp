#include<bits/stdc++.h>
using namespace std;


string addDecimalStrings(string s1, string s2) {
    string res = "";

    int i = s1.size() - 1, j = s2.size() - 1;
    int carry = 0;
    while (i >= 0 || j >= 0 || carry > 0) {
        int total = 0;
        if (i >= 0) {
            total += s1[i] - '0';
            i--;
        }
        if (j >= 0) {
            total += s2[j] - '0';
            j--;
        }

        total += carry;
        res += char(total % 10 + '0');

        carry = total / 10;
    }

    reverse(res.begin(), res.end());
    return res;
}

void solve() {
    string a = "5346365464", b = "54645645";
    cout << addDecimalStrings(a, b);
}


int main() {
    solve();
    return 0;
}
