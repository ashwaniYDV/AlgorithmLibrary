// https://www.codechef.com/problems/RECTCNT

/*
Given N separate integer points on the Cartesian plane satisfying: there is no any three of them sharing a same X-coordinate. 
Your task is to count the number of rectangles (whose edges parrallel to the axes) created from any four of given points.

Input
There are several test cases (ten at most), each formed as follows:
The first line contains a positive integer N (N ≤ 10^5).
N lines follow, each containing a pair of integers (each having an absolute value of 10^9 at most) describing coordinates of a given point.
The input is ended with N = 0.

Output
For each test case, output on a line an integer which is the respective number of rectangles found.

Input:
6
7 1
3 5
3 1
1 5
1 1
7 5
0

Output:
3
*/


int n, m;

void count_rectangles(int n) {
    int x, y;
    vector<pair<int, int>> points;
    f(i, n) {
        cin >> x >> y;
        points.pb({x, y});
    }

    sort(all(points));

    map<pair<int, int>, int> count;
    int res = 0;

    for(int i = 0; i < n-1; i++) {
        auto p = points[i], p_above = points[i+1];
        if(p.first == p_above.first && p.second < p_above.second) {
            res += count[{p.second, p_above.second}];
            count[{p.second, p_above.second}]++;
        }
    }

    cout << res << endl;
}


void solve() {
    while(1) {
        cin >> n;
        if(n == 0) return;
        count_rectangles(n);
    }
}
