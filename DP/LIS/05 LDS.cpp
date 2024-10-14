/*
LDS can be implemented in 2 ways depending on question
a) dp_lds[i] = longest decreasing subsequence ending with nums[i]  (i.e including nums[i])
b) dp_lds[i] = longest decreasing subsequence starting with nums[i]  (i.e including nums[i])
*/

void solve() {
    cin >> n;
    vector<int> nums(n);
    f(i, n) cin >> nums[i];
    
    int mx_lis = 0, mx_lds = 0;
    vector<int> dp_lis(n+1, 1);
    vector<int> dp_lds(n+1, 1);
    
    for(int i = 1; i < n; ++i) {
        for(int j = 0; j < i; ++j) {
            // longest increasing
            if(nums[i] > nums[j]){
                dp_lis[i] = max(dp_lis[i], dp_lis[j] + 1);
            }
            // longest decreasing
            if(nums[i] < nums[j]){
                dp_lds[i] = max(dp_lds[i], dp_lds[j] + 1);
            }
        }
        mx_lis = max(mx_lis, dp_lis[i]);
        mx_lds = max(mx_lds, dp_lds[i]);
    }
    cout << mx_lis << endl;
    cout << mx_lds << endl;
}
 
int32_t main() {
    IOS
    int T = 1;
    // cin >> T;
    while(T--)
    solve();
    return 0;
}
