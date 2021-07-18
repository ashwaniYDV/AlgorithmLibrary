// https://www.geeksforgeeks.org/largest-sum-subarray-least-k-numbers/
// https://practice.geeksforgeeks.org/problems/largest-sum-subarray-of-size-at-least-k3121/1


/*
This problem is an extension of Largest Sum Subarray Problem. 
1) We first compute maximum sum till every index i (such that a[i] is part of the sum) and store it in an array maxSum[]. 
   maxSum[i] = maximum sum till index i including a[i] (i.e. a[i] is the ending index of subarray)
2) After filling the array, we use the sliding window concept of size k. Keep track of sum of current k elements. 
   After getting the sum of current window, we add the maxSum of the previous window, if it is greater than current max, then update it.
*/


// Time = O(n), Space = O(n)

#include<bits/stdc++.h>
using namespace std;

int maxSumWithK(int a[], int n, int k) {
    // maxSum[i] is going to store maximum sum till index i including a[i] (i.e. a[i] is the ending index of subarray)
    int maxSum[n];

    // We use Kadane's algorithm to fill maxSum[]
    // Below code is taken from method 3 of https://www.geeksforgeeks.org/largest-sum-contiguous-subarray/
    int curr_max = 0;
    for (int i = 0; i < n; i++) {
        curr_max = max(a[i], curr_max + a[i]);
        maxSum[i] = curr_max;
    }

    // Sum of first k elements
    int sum = 0;
    for (int i = 0; i < k; i++) {
        sum += a[i];
    }
    int res = sum;

    // Use the concept of sliding window
    for (int i = k; i < n; i++) {
        sum = sum + a[i] - a[i - k];
        res = max(res, sum);

        // Include maximum sum till [i - k] also if it increases overall max.
        int moreThanKEle = sum + maxSum[i - k];
        res = max(res, moreThanKEle);
    }

    return res;
}

int main() {
    int a[] = {1, 2, 3, -3, -5};
    int k = 4;
    int n = sizeof(a) / sizeof(a[0]);
    cout << maxSumWithK(a, n, k);
    return 0;
}


















// Time = O(n), Space = O(1)

#include<bits/stdc++.h>
using namespace std;

// Assumption: k <= n
int maxSumWithK(int a[], int n, int k) {
    int cur_sum = 0, best_ps = INT_MAX, cur_ps = 0;
    for (int i = 0; i < k; i++) cur_sum += a[i];

    int ans = cur_sum;

    for (int i = k; i < n; i++) {
        cur_sum += a[i];
        ans = max(ans, cur_sum);

        cur_ps += a[i - k];
        best_ps = min(best_ps, cur_ps);

        ans = max(ans, cur_sum - best_ps);
    }
    return ans;
}

int main() {
    int a[] = {1, 2, 3, -5, -3};
    int k = 4;
    int n = sizeof(a) / sizeof(a[0]);
    cout << maxSumWithK(a, n, k);
    return 0;
}
