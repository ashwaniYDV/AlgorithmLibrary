// https://codeforces.com/problemset/problem/255/C
// C. Almost Arithmetical Progression
// https://codeforces.com/blog/entry/6161?#comment-637359


/*
Gena loves sequences of numbers. Recently, he has discovered a new type of sequences which he called an almost arithmetical progression. 
A sequence is an almost arithmetical progression, if its elements can be represented as:

a[1] =  p,  where p is some integer;
a[i]  =  a[i - 1] + (( - 1)^(i + 1))*q  (i > 1),  where q is some integer.

Right now Gena has a piece of paper with sequence b, consisting of n integers. 
Help Gena, find there the longest subsequence of integers that is an almost arithmetical progression.

input:
2
3 5
output:
2

input:
4
10 20 10 30
output:
3
*/



/*
The problem asks to compute the length of the longest subsequence in the form of a, b, a, b, ....

You can map A[1..n] values to 0..n-1
Once, the values are mapped, fill an array dp[i][j] which contains the max subsequence length 
ending with a[i] and previous element being a[j].

We have to find the longest subsequence of A,B,A,B,A,B,... Type. 
Since in an array of size n, we cant have more than n different numbers, 
we map the numbers accordingly. 
For example, a = [ 10 , 20 , 30 , 20 , 30 ] --> a = [ 0 , 1 , 2 , 1 , 2 ] 
We updated the initial array!

Now we create dp[n][n], where dp[ i ][ j ] means length of longest subsequence 
ending at i th element (a[ i ]) and j th element (a[j]) being the previous element in subsequence! 
Here's the tricky part: For every (i,j) , we dont update dp[ i ][ j ], 
Instead we update dp[ i ][ a[ j ] ]. 
(Yes, some dp[ i ][ j ] may never be updated , if array elements repeat , 
but we just have to find the maximum length. It'll make sense soon! )
*/



void solve() {
    int x, y, z;

    cin >> n;
    int a[n];

    f(i, n) 
        cin >> a[i];

    // map all elements from 0 to n-1 range
    map<int, int> mp;
    int idx = 0;
    f(i, n) {
        if(mp.count(a[i]) == 0)
            mp[a[i]] = idx++;
    }
    f(i, n) {
        a[i] = mp[a[i]];
    }

    int dp[n][n];
    int ans = 0;

    f(i, n) {
        f(j, n) {
            dp[i][j] = 1;
        }
    }

    for(int i = 1; i < n; i++) {
        for(int j = 0; j < i; j++) { 
            dp[i][a[j]] = max(1 + dp[j][a[i]], dp[i][a[j]]);
        }
    }

    f(i, n) {
        f(j, n) {
            ans = max(ans, dp[i][j]);
        }
    }

    cout << ans << endl;
}
