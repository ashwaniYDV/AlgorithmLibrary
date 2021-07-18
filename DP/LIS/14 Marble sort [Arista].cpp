/*
You have marbles numbered from 1 to n.
These marbles are randomly distributed in 3 arrays a1, a2, a3.
Every marble is present in any of the three arrays.
Now these arrays are given to you to construct a new sorted array.

You have to apply the given operation minimum number of times to make constructed array sorted.
You can select one marble from any of the 3 arrays and move to any other array.

Now you have to construct a new array by sorting all the 3 arrays a1, a2, a3 and then appending in order a1, a2, a3
such that the new constructedarray array contains element in sorted order from 1 to n.


Example:
a1 = 2, 3
a2 = 1, 4, 6
a3 = 5, 7

Result: min operations required = 2

Explantion:
operation #1: move 1 from a2 to a1
thus a1 = 1, 2, 3
     a2 = 4, 6
     a3 = 5, 7

operation #2: from 6 from a2 to a3
thus a1 = 1, 2, 3
     a2 = 4
     a3 = 5, 6, 7
     
Thus now after sorting a1, a2, a3 and appending a1, a2, a3 in order
Constructed array = 1, 2, 3, 4, 5, 6, 7
*/






class Solution {
public:
    int LIS(vector<int> &arr) {
        int n = arr.size();

        vector<int> dp(n, 1);
        int mx = 1;

        for(int i = 1; i < n; i++) {
            for(int j = 0; j < i; j++) {
                if(arr[i] > arr[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            mx = max(mx, dp[i]);
        }

        return mx;
    }

    int solveFun(vector<int> a1, vector<int> a2, vector<int> a3) {
        sort(all(a1));
        sort(all(a2));
        sort(all(a3));

        vector<int> arr;
        f(i, a1.size()) arr.push_back(a1[i]);
        f(i, a2.size()) arr.push_back(a2[i]);
        f(i, a3.size()) arr.push_back(a3[i]);

        return arr.size() - LIS(arr);
    }
};

void solve() {
    int n1, n2, n3;
    cin >> n1 >> n2 >> n3;
    vi a1(n1), a2(n2), a3(n3);
    
    f(i, n1) cin >> a1[i];
    f(i, n2) cin >> a2[i];
    f(i, n3) cin >> a3[i];

    Solution obj;
    cout << obj.solveFun(a1, a2, a3);
}


/*
Input:
2 3 2
2 3
1 4 6
5 7

Output:
2
*/
