#include<bits/stdc++.h>
using namespace std;

string addBinary(string a, string b) {
    string result = "";

    // Traverse both strings starting from last characters
    int i = a.size() - 1, j = b.size() - 1;
    int carry = 0;

    while (i >= 0 || j >= 0 || carry > 0) {
        int total = 0;
        if (i >= 0) {
            total += a[i] - '0';
            i--;
        }
        if (j >= 0) {
            total += b[j] - '0';
            j--;
        }

        total += carry;

        // If current digit sum is 1 or 3, add 1 to result
        result += char(total % 2 + '0');

        // Compute carry
        carry = total / 2;

    }
    reverse(result.begin(), result.end());
    return result;
}

int main() {
    string a = "1101", b = "100";
    cout << addBinary(a, b) << endl;
    return 0;
}
