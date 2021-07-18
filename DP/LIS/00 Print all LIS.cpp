// https://www.youtube.com/watch?v=3mD20VSib5E
// Print All Longest Increasing Subsequences


struct Node {
    int len;
    int idx;
    int val;
    string pathSoFar; 
};

void solve() {
    cin >> n;
    vector<int> nums(n);
    f(i, n) cin >> nums[i];

    vector<int> dp(n+1, 1);
    int mx = 1;

    for(int i=1; i < n; ++i) {
        for(int j=0; j < i; ++j) {
            if(nums[i] > nums[j]){
                if(dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                }
            }
        }
        mx = max(mx, dp[i]);
    }

    /////////////////
    queue<Node> q;
    f(i, n) {
        if(dp[i] == mx)
            q.push({mx, i, nums[i], to_string(nums[i])});
    }

    int totalLIS = 0;
    // bfs traversal to print all LIS
    while(q.size()) {
        Node nodea = q.front();
        q.pop();

        if(nodea.len == 1) {
            cout << nodea.pathSoFar << endl;
            totalLIS++;
        }

        // for(int j = 0; j < nodea.idx; j++) [Method 2: as per answer is required]
        for(int j = nodea.idx - 1; j >= 0; j--) {
            if(dp[j] == nodea.len-1 && nums[j] < nodea.val) {
                Node nodeb = {dp[j], j, nums[j], to_string(nums[j]) + " -> " + nodea.pathSoFar};
                q.push(nodeb);
            }
        }
    }

    cout << "\nTotal LIS = " << totalLIS << endl;
    /////////////////
}

/*

INPUT:
10
10 22 42 33 21 50 41 60 80 3

OUTPUT:
10 -> 22 -> 33 -> 41 -> 60 -> 80
10 -> 22 -> 33 -> 50 -> 60 -> 80
10 -> 22 -> 42 -> 50 -> 60 -> 80

Total LIS = 3






INPUT:
11
10 22 42 33 33 21 50 41 60 80 3

OUTPUT:
10 -> 22 -> 42 -> 50 -> 60 -> 80
10 -> 22 -> 33 -> 50 -> 60 -> 80
10 -> 22 -> 33 -> 50 -> 60 -> 80
10 -> 22 -> 33 -> 41 -> 60 -> 80
10 -> 22 -> 33 -> 41 -> 60 -> 80

Total LIS = 5
*/
