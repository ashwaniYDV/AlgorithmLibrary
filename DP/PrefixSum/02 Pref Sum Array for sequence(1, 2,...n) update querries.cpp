// Scanline Algo concept

// Reference Problem:     https://www.codechef.com/BYTR20B/problems/AGCY
// Editorial:             https://discuss.codechef.com/t/agcy-editorial/83045

/*
Given an array, A of size N initially filled with 0's, 
For each query containing two integers L, R 
add 1 to A[L], 2 to A[L+1], 3 to A[L+2] ... (R-L+1) to A[R]. 
In general, add i+1 to A[L+i] for every L <= i <= R.
Do this for all q queries.
Find the final array.
*/


void solve() {
    int x, y, l, r, q;
    cin >> n >> q;
    vector<int> pref(n+5, 0);
    vector<int> res(n+5, 0);
    while(q--) {
        cin >> l >> r;
        pref[l] += 1;
        pref[r+1] -= 1;

        // res[l] += 1;      (do not do this line)
        res[r+1] -= (r - l + 1);
    }

    // normal prefix sum
    for(int i = 1; i <= n; i++) {
        pref[i] += pref[i - 1];
    }

    // answer generation
    for(int i = 1; i <= n; i++) {
        res[i] += (res[i - 1] + pref[i]);
    }

    for(int i = 1; i <= n; i++) {
        cout << res[i] << " ";
    }
    cout << endl;
}
 
/*
Input: 
5
3
1 3
2 3
2 4

Output:
1 4 7 3 0 

Explanation:
After 1st query array is:    1, 2, 3, 0, 0
After 2nd query array is:    1, 3, 5, 0, 0
After 3rd query array is:    1, 4, 7, 3, 0
*/
