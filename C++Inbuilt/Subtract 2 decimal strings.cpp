/*
Assumption:
a >= b
*/

#include<bits/stdc++.h>
using namespace std;

string subtract(string a, string b) {
    int i = a.size() - 1, j = b.size() - 1;
    string res = "";

    int carry = 0;
    while (i >= 0 || j >= 0) {
        int x = (i >= 0) ? a[i] - '0' : 0;
        int y = (j >= 0) ? b[j] - '0' : 0;

        if (carry) {
            x -= 1;
            carry = 0;
        }

        if (x < y) {
            x += 10;
            carry = 1;
        }

        res = (char)((x - y) + '0') + res;
        i--, j--;
    }

    /*
        sometimes output can be like 09998
        thus remove leading zeros if any
    */
    int n = res.size();
    i = 0;
    while (i < n - 1 && res[i] == '0') {
        i++;
    }

    res = res.substr(i);
    return res;
}

int main() {
    string a, b;
    cin >> a >> b;
    cout << subtract(a, b) << endl;
    return 0;
}


/*
10040
42

9998
*/
