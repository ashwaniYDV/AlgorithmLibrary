// https://www.geeksforgeeks.org/box-stacking-problem-dp-22/
// https://practice.geeksforgeeks.org/problems/box-stacking/1

/*
NOTE: this will give error as pointed out by HrishabhRaj.

for(int i = 0; i < n; i++) {
    arr.push_back({height[i], width[i], length[i]});
    arr.push_back({height[i], length[i], width[i]});
    arr.push_back({width[i], length[i], height[i]});
}
Consider only base area of two boxes:-
Dimension of outer box = (3 * 4)
Dimension of inner box = (3 * 2)
And as shown below this will not be valid as heights of both boxes are same

-------------------
|    |       |    |
|    |       |    |
|    |       |    |
-------------------

Now consider of we rotate the inner box.
Dimension of outer box = (3 * 4)
Dimension of inner box = (2 * 3)

And thus the same boxes pair become valid
-------------------
|                 |
|  |-----------|  |
|  |           |  |
|  |-----------|  |
|                 |
-------------------

And that's why we used this:
for(int i = 0; i < n; i++) {
    arr.push_back({max(height[i], width[i]), min(height[i], width[i]), length[i]});
    arr.push_back({max(height[i], length[i]), min(height[i], length[i]), width[i]});
    arr.push_back({max(width[i], length[i]), min(width[i], length[i]), height[i]});
}
*/

class Solution {
    public:
    
    static bool compare(vector<int>& a, vector<int>& b) {
        return a[0]*a[1] < b[0]*b[1];
    }
    
    int maxHeight(int height[],int width[],int length[],int n) {
        //Your code here
        vector<vector<int>> arr;
        
        for(int i = 0; i < n; i++) {
            arr.push_back({max(height[i], width[i]), min(height[i], width[i]), length[i]});
            arr.push_back({max(height[i], length[i]), min(height[i], length[i]), width[i]});
            arr.push_back({max(width[i], length[i]), min(width[i], length[i]), height[i]});
        }
        
        sort(arr.begin(), arr.end(), compare);
        
        int m =3*n;
        vector<int> dp(m);
        for(int i = 0; i < m; i++) dp[i] = arr[i][2];
        int mx = 0;
        
        for(int i = 1; i < m; i++) {
            for(int j = 0; j < i; j++) {
                if(arr[i][0] > arr[j][0] && arr[i][1] > arr[j][1]) {
                    dp[i] = max(dp[i], dp[j] + arr[i][2]);
                }
            }
            mx = max(mx, dp[i]);
        }
        
        return mx;
    }
};
