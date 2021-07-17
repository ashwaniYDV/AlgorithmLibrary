// https://codeforces.com/problemset/problem/466/C

/*
First of all, notice that if sum of all elements is equal S then sum of each of three parts is equal S/3.
Therefore, if S is not divided by 3 — then answer is 0.
Otherwise, let’s iterate the end of first part i (1 ≤ i ≤ n - 2) and if sum of 1..i elements is equal S/3, 
then it means that we have to add to the answer the amount of such j (j > i +  1) that the sum of elements from j-th to n-tn also equals S/3.
*/

void solve() {
    int x, y, z;
    cin >> n;
    int a[n];
    int sum = 0;
    f(i, n) cin >> a[i], sum += a[i];

    if(sum % 3) {
        cout << 0 << endl;
        return;
    }

    int prefSum[n] = {0}, sufSum[n] = {0};
    prefSum[0] = a[0], sufSum[n-1] = a[n-1];

    fa(i, 1, n) prefSum[i] += prefSum[i-1] + a[i];
    for(int i = n-2; i >= 0; i--) sufSum[i] += sufSum[i+1] + a[i];

    int cntSuf[n] = {};
    if(a[n-1] == sum/3) cntSuf[n-1] = 1;
    for(int i = n-2; i >= 0; i--) {
        if(sufSum[i] == sum/3) cntSuf[i] = 1;
        cntSuf[i] += cntSuf[i+1];
    }

    int res = 0;
    f(i, n-2) {
        if(prefSum[i] == sum/3) {
            res += cntSuf[i+2];
        }
    }
    cout << res << endl;
}
