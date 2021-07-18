// https://leetcode.com/problems/set-mismatch/
// https://www.geeksforgeeks.org/problems/find-missing-and-repeating2512/1
// https://youtu.be/5nMGY4VUoRY


/*
Given an unsorted array of size n. Array elements are in the range from 1 to n. 
One number from set {1, 2, ...n} is missing and one number occurs twice in the array. 
Find these two numbers.

arr[] = {3, 1, 3}
Missing = 2, Repeating = 3

arr[] = {4, 3, 6, 2, 1, 1}
Missing = 5, Repeating = 1
*/


class Solution {
public:
    vector<int> findErrorNums(vector<int>& arr) {
        int n = arr.size();
        for (int i = 0; i < n; i++) {
            while (arr[i] != arr[arr[i] - 1]) {
                swap(arr[i], arr[arr[i] - 1]);
            }
        }

        vector<int> res;
        for (int i = 0; i < n; i++) {
            if (arr[i] != i + 1) {
                res.push_back(arr[i]);
                res.push_back(i + 1);
            }
        }

        return res;
    }
};