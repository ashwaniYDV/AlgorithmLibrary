// https://codeforces.com/contest/1427/problem/C

/*
Problem: 
You are a paparazzi working in Manhattan.
Manhattan has r south-to-north streets, denoted by numbers 1,2,...,r in order from west to east, 
and r west-to-east streets, denoted by numbers 1,2,...,r in order from south to north. 
Each of the r south-to-north streets intersects each of the r west-to-east streets; 
the intersection between the x-th south-to-north street and the y-th west-to-east street is denoted by (x,y). 
In order to move from the intersection (x,y) to the intersection (x′,y′) you need |x−x′|+|y−y′| minutes.

You know about the presence of n celebrities in the city and you want to take photos of as many of them as possible. 
More precisely, for each i=1,...,n, you know that the i-th celebrity will be at the intersection (xi,yi) in exactly ti minutes from now 
(and he will stay there for a very short time, so you may take a photo of him only if at the ti-th minute from now you are at the intersection (xi,yi)). 
You are very good at your job, so you are able to take photos instantaneously. You know that ti < ti+1 for any i=1,2,...,n-1.

Currently you are at your office, which is located at the intersection (1,1). 
If you plan your working day optimally, what is the maximum number of celebrities you can take a photo of?
*/

/*
This is a classical dynamic-programming task with a twist. 

We say that two celebrities i < j are compatible if it is possible to take a photo of both, that is
|xi - xj| + |yi - yj| ≤ tj - ti.
*/


// TLE Solution using LIS concept
struct node {
    int time, x, y;
};

void solve() {
    int x, y, z, t, r;
    cin >> r >> n;
    // Given: a is sorted with time t
    vector<node> a(n);
    f(i, n) {
        cin >> t >> x >> y;
        a[i] = {t, x, y};
    }

    int dp[n];

    // base case
    int res = 0;
    f(i, n) {
        int dist = abs(1 - a[i].x) + abs(1 - a[i].y);
        if(dist <= (a[i].time - 0)) dp[i] = 1;
        else dp[i] = 0;

        res = max(res, dp[i]);
    }

    for(int i = 1; i < n; i++) {
        for(int j = 0; j < i; j++) {
            int dist = abs(a[i].x - a[j].x) + abs(a[i].y - a[j].y);
            if(dp[j] > 0 && dist <= (a[i].time - a[j].time)) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        res = max(res, dp[i]);
    }

    cout << res << endl;
}
