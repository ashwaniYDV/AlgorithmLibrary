// https://youtu.be/2yAEj-0A8bk

/*
Ron read a book about boring numbers. According to the book, a positive number is called boring 
if all of the digits at even positions in the number are even and all of the digits at odd positions are odd. 
The digits are enumerated from left to right starting from 1. 

For example, the number 1478 is boring as the odd positions include the digits {1, 7} which are odd 
and even positions include the digits {4, 8} which are even.

Given two numbers L and R, Ron wants to count how many numbers in the range [L, R] (L and R inclusive) are boring. 

Input
The first line of the input gives the number of test cases, T. T test cases follow. Each test case consists of a single line with two numbers L and R.

Output
For each test case, output one line containing Case #x: y, where x is the test case number (starting from 1) and y is the count of boring numbers.



Sample Input:
3
5 15
120 125
779 783
 	
Sample Output:
Case #1: 6
Case #2: 3
Case #3: 2
*/



int dp[20][2][2][2];
string str;

int digit_dp(int pos, int isEvenPos, int leadingzeros, int tight) {
    if(pos == str.length()) return 1;

    if(dp[pos][isEvenPos][leadingzeros][tight] != -1) return dp[pos][isEvenPos][leadingzeros][tight];
    
    int res = 0;

    // leading zeros can only be there in starting position which is odd position
    if(isEvenPos) {
        vector<int> digits = {0, 2, 4, 6, 8};

        int ub = tight ? (str[pos] - '0') : 9;

        for(int dig: digits) {
            if(dig <= ub) {
                res += digit_dp(pos + 1, 0, 0, (tight & (dig == ub)));
            }
        }
    } else {
        vector<int> digits = {1, 3, 5, 7, 9};

        int ub = tight ? (str[pos] - '0') : 9;

        // if leading zeros are there, go for another leading zero
        if(leadingzeros) {
            res += digit_dp(pos + 1, 0, 1, 0);
        }

        for(int dig: digits) {
            if(dig <= ub) {
                res += digit_dp(pos + 1, 1, 0, (tight & (dig == ub)));
            }
        }
    }
    
    return dp[pos][isEvenPos][leadingzeros][tight] = res;
}

int go(int num) {
    str = to_string(num);
    memset(dp, -1, sizeof(dp));
    return digit_dp(0, 0, 1, 1);
}

void solve(int testcase) {
    int l, r;
    cin >> l >> r;
    int res = go(r) - go(l - 1);
    kickstart(testcase, res);
}

signed main() {
    IOS
    clock_t begin = clock();
    PRECISION(10);
    int t = 1;
    cin >> t;
    f(i, t) {
        solve(i+1);
    }
    cerr << "Time elapsed: " << (clock() - begin) * 1000.0 / CLOCKS_PER_SEC << "ms" << '\n';
}
