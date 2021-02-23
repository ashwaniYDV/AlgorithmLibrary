// https://codeforces.com/contest/1486/problem/B
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
    return x[n/2] - x[(n-1)/2] + 1;
}
 
void solve() {
    int n;
    cin >> n;
    vector<int> x(n), y(n);
    for (int i = 0; i < n; ++i) {
        cin >> x[i] >> y[i];
    }
    cout << solve(x) * solve(y) << '\n';
}
