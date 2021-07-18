// https://practice.geeksforgeeks.org/problems/count-pairs-with-given-sum5022/1
// https://www.geeksforgeeks.org/print-all-pairs-with-given-sum/

/*
Find number of pairs of elements in the array whose sum is equal to K.

Example 1:
Input:
N = 4, K = 6
arr[] = {1, 5, 7, 1}
Output: 2
Explanation: 
arr[0] + arr[1] = 1 + 5 = 6 and arr[1] + arr[3] = 5 + 1 = 6.

Example 2:
Input:
N = 4, X = 2
arr[] = {1, 1, 1, 1}
Output: 6
Explanation: 
Each 1 will produce sum 2 with any 1.
*/


class Solution {
public:
    int getPairsCount(int A[], int n, int k) {
        sort(A, A + n);
        int i = 0, j = n - 1;
        int res = 0;

        while (i < j) {
            int sum = A[i] + A[j];
            if (sum == k) {
                if (A[i] != A[j]) {
                    int a = 1, b = 1;
                    while (i + 1 < j && A[i] == A[i + 1]) i++, a++;
                    while (j - 1 > i && A[j] == A[j - 1]) j--, b++;

                    res += a * b;
                    i++, j--;
                }
                // equal A[i] == A[j]
                else {
                    int temp = (j - i + 1);
                    res += (temp * (temp - 1) / 2);
                    break;
                }
            }
            else if (sum > k) {
                j--;
            }
            else {
                i++;
            }
        }
        return res;
    }
};





class Solution {
public:
    int getPairsCount(int arr[], int n, int k) {
        unordered_map<int, int> mp;

        int res = 0;
        for (int i = 0; i < n; i++) {
            res += mp[k - arr[i]];
            mp[arr[i]]++;
        }

        return res;
    }
};
