

// Print any LIS
class Solution {
public:
    vector<int> printLIS(vector<int>& nums) {
        int n = (int)nums.size();

        vector<int> ans;
        
        int mx = 1;
        vector<int> dp(n+1, 1);
        
        for(int i = 1; i < n; i++) {
            for(int j = 0; j < i; j++) {
                if(nums[i] > nums[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            mx = max(mx, dp[i]);
        }

        //Now push the answer LIS
        int prev = -1;
        for(int i = n - 1; i >= 0; i--) {
            if(dp[i] == mx &&  (prev > nums[i] || prev == -1)) {
                ans.push_back(nums[i]);
                mx -= 1;
                prev = nums[i];
            }
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};






// https://www.youtube.com/watch?v=3mD20VSib5E
// Print All Longest Increasing Subsequences

class Solution {
public:
    struct Node {
        int len;
        int idx;
        int val;
        string pathSoFar; 
    };

    void printLIS(vector<int>& nums) {
        int n = (int)nums.size();

        vector<int> ans;
        
        int mx = 1;
        vector<int> dp(n+1, 1);
        
        for(int i = 1; i < n; i++) {
            for(int j = 0; j < i; j++) {
                if(nums[i] > nums[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            mx = max(mx, dp[i]);
        }

        /////////////////
        queue<Node> q;
        for(int i = 0; i < n; i++) {
            if(dp[i] == mx)
                q.push({mx, i, nums[i], to_string(nums[i])});
        }

        int totalLIS = 0;
        // bfs traversal to print all LIS
        while(!q.empty()) {
            Node nodeA = q.front();
            q.pop();

            if(nodeA.len == 1) {
                cout << nodeA.pathSoFar << endl;
                totalLIS++;
            }

            // for(int j = 0; j < nodeA.idx; j++) [Method 2: as per answer is required]
            for(int j = nodeA.idx - 1; j >= 0; j--) {
                if(dp[j] == nodeA.len-1 && nums[j] < nodeA.val) {
                    Node nodeB = {dp[j], j, nums[j], to_string(nums[j]) + " -> " + nodeA.pathSoFar};
                    q.push(nodeB);
                }
            }
        }

        cout << "\nTotal LIS = " << totalLIS << endl;
    }
};

/*
INPUT:
10 22 42 33 21 50 41 60 80 3

OUTPUT:
10 -> 22 -> 33 -> 41 -> 60 -> 80
10 -> 22 -> 33 -> 50 -> 60 -> 80
10 -> 22 -> 42 -> 50 -> 60 -> 80

Total LIS = 3
*/

class Solution {
public:
    struct Node {
        int len;
        int idx;
        int val;
        vector<int> pathSoFar;
    };

    vector<vector<int>> printLIS(vector<int>& nums) {
        int n = (int)nums.size();

        vector<int> ans;
        
        int mx = 1;
        vector<int> dp(n+1, 1);
        
        for(int i = 1; i < n; i++) {
            for(int j = 0; j < i; j++) {
                if(nums[i] > nums[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            mx = max(mx, dp[i]);
        }

        /////////////////
        queue<Node> q;
        for(int i = 0; i < n; i++) {
            if(dp[i] == mx)
                q.push({ mx, i, nums[i], {nums[i]} });
        }

        int totalLIS = 0;
        vector<vector<int>> res;

        // bfs traversal to print all LIS
        while(!q.empty()) {
            Node nodeA = q.front();
            q.pop();

            if(nodeA.len == 1) {
                reverse(nodeA.pathSoFar.begin(), nodeA.pathSoFar.end());
                res.push_back(nodeA.pathSoFar);
                totalLIS++;
                continue;
            }

            // for(int j = 0; j < nodeA.idx; j++) [Method 2: as per answer is required]
            for(int j = nodeA.idx - 1; j >= 0; j--) {
                if(dp[j] == nodeA.len-1 && nums[j] < nodeA.val) {
                    nodeA.pathSoFar.push_back(nums[j]);
                    Node nodeB = { dp[j], j, nums[j], nodeA.pathSoFar };
                    q.push(nodeB);

                    // backtrack
                    nodeA.pathSoFar.pop_back();
                }
            }
        }

        cout << "\nTotal LIS = " << totalLIS << endl;
        return res;
    }
};