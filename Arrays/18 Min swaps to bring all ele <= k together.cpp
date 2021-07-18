// https://www.geeksforgeeks.org/minimum-swaps-required-bring-elements-less-equal-k-together/
// https://practice.geeksforgeeks.org/problems/minimum-swaps-required-to-bring-all-elements-less-than-or-equal-to-k-together4847/1

class Solution {
public:
    int minSwap(int arr[], int n, int k) {
        // Find count of elements which are less than equals to k
        int count = 0;
        for (int i = 0; i < n; ++i) {
            if (arr[i] <= k) ++count;
        }

        // Find unwanted elements in current window of size 'count'
        int bad = 0;
        for (int i = 0; i < count; ++i) {
            if (arr[i] > k)
                ++bad;
        }

        // Initialize answer with 'bad' value of current window
        int ans = bad;
        for (int i = count; i < n; ++i) {
            // Decrement count of previous window
            if (arr[i - count] > k) --bad;

            // Increment count of current window
            if (arr[i] > k) ++bad;

            ans = min(ans, bad);
        }
        return ans;
    }
};






// Modified question:
// Min swaps to bring all ele <= k together to the left hand side

class Solution {
public:
    int minSwap(int arr[], int n, int k) {
        // Find count of elements which are less than equals to k
        int count = 0;
        for (int i = 0; i < n; ++i) {
            if (arr[i] <= k) ++count;
        }

        // Find unwanted elements in current window of size 'count'
        int bad = 0;
        for (int i = 0; i < count; ++i) {
            if (arr[i] > k)
                ++bad;
        }

        return bad;
    }
};
