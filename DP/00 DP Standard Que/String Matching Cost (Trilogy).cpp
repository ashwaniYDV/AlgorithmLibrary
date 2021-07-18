/*
Trilogy Innovations (formerly CodeNation Innovation Labs) - 14_Aug_2021

Problem Name: Yet another string operation problem

Given two strings A, B (|A| = |B| <= 1000) and a integer C, you can do 2 types of operations
set A[i] = B[i], cost = 1
reverse A[i...j], cost = C (given), this operation can be performed only once
Find the min cost to make A = B

Sample Input 1:
abceda
bdecbo
1
Sample Output 1:
3

Sample Input 2:
finger 
ginger
0
Sample Output 2:
1
*/


/*
Given 2 string a and b of same size and an integer c.
Find the minimum cost to make a equal to b by applying these operations:
a) Change a[i] = b[i] with cost = 1 (any number of time)
b) Reverse a substring a[i...j] with cost = c (atmost 1 time)
*/

const int N = 1e3+5;
int n, m;

int dp[N][N][2];
string a, b;
int c;

int go(int i, int j, int isRotated) {
    if(i > j) return 0;
    if(i == j) {
        if(a[i] == b[i]) return 0;
        return 1;
    }

    if(dp[i][j][isRotated] != -1) return dp[i][j][isRotated];
    
    int res = INF;
  
    if(isRotated) {
        res = ((a[j] != b[i]) + (a[i] != b[j]) + go(i + 1, j - 1, 1)); 
    } else {
        res = min(res, c + (a[i] != b[j]) + (a[j] != b[i])+ go(i + 1, j - 1, 1));
        res = min(res, (a[i] != b[i]) + go(i + 1, j, 0) );
        res = min(res, (a[j] != b[j]) + go(i, j - 1, 0) );
    }

    return dp[i][j][isRotated] = res;
}


void solve() {
    cin >> a >> b;
    cin >> c;
    memset(dp, -1, sizeof dp);
    n = a.size();
    cout << go(0, n - 1, 0) << endl;
}
