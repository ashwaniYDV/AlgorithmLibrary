// https://codeforces.com/contest/1486/problem/B
// https://math.stackexchange.com/questions/113270/the-median-minimizes-the-sum-of-absolute-deviations-the-ell-1-norm

/*
NOTE: The median minimizes the sum of absolute deviations.
If there are two medians m1, m2, then all the points between m1, m2 (inclusive), [m1, m1+1, ..., m2] will give the same deviations
If there is only one median m1, then there is only one solution in this coordiante.

If array length n is even then there will be 2 medians m1, m2
If array length n is odd then there will be only 1 median m1
*/

/*
// https://cses.fi/book/index.php

Case 1: To minimize this
|a1 - x| + |a2 - x| + |a3 - x| + ... + |an - x|
The optimum choice is to select x as median (i.e. the middle number of a1, a2, ..., an after sorting)  
[=> the two sub cases are if n is even or odd as discussed above]


Case 2: To minimize this
(a1 - x)^2 + (a2 - x)^2 + (a3 - x)^2 + ... + (an - x)^2
The optimum choice is to select x as mean of a1, a2, ..., an
*/

/*
Hint1:
Is problem really two dimensional?

Hint2:
How to solve the problem if y=0?

Solution:
At first let's see that the problem is not two dimensional. If we change the x coordinate the sum of distances by y is not changed at all. 
So we just need to calculate the number of good points on a line with points having coordinates x and then y and multiply the answers.

Now to calculate the answer on a line we could use a known fact: point with the smallest summary distance is between left and right median. 
So now we only need to sort the array and find the elements on positions ⌊(n+1)/2⌋ and ⌊(n+2)/2⌋ and return their difference plus one.
*/

int solve(vector<int> x) {
    sort(x.begin(), x.end());
    int n = x.size();
    return x[n/2] - x[n/2 - 1] + 1;
}
 
void solve() {
    int n;
    cin >> n;
    vector<int> x(n), y(n);
    for (int i = 0; i < n; ++i) {
        cin >> x[i] >> y[i];
    }
    if(n % 2 == 1) {
        cout << 1 << endl;
        return;
    }
    cout << solve(x) * solve(y) << '\n';
}
