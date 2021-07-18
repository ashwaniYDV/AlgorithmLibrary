// https://leetcode.com/problems/reverse-pairs/

/*
Return the number of pairs (i, j) such that i < j and nums[i] > 2 * nums[j]

Problem:
Given an integer array nums, return the number of reverse pairs in the array.
A reverse pair is a pair (i, j) where 0 <= i < j < nums.length and nums[i] > 2 * nums[j].
*/


class Solution {
public:
    int res = 0;

    void merge(vector<int>& a, int start, int mid, int end) {
        int temp[end - start + 1];
        int i = start, j = mid + 1, k = 0;

        // calculate answer
        while (i <= mid && j <= end) {
            if (a[i] <= (2LL * a[j])) {
                i++;
            } else {
                res += (mid - i + 1);
                j++;
            }
        }
        
        // now do sorting part
        i = start, j = mid + 1, k = 0;
        while (i <= mid && j <= end) {
            if (a[i] <= a[j]) {
                temp[k++] = a[i++];
            } else {
                temp[k++] = a[j++];
            }
        }
        while (i <= mid) {
            temp[k++] = a[i++];
        }
        while (j <= end) {
            temp[k++] = a[j++];
        }

        for (int i = 0; i < k; i++) {
            a[start++] = temp[i];
        }
    }

    void mergeSort(vector<int>& a, int start, int end) {
        if (start < end) {
            int mid = (start + end) / 2;
            mergeSort(a, start, mid);
            mergeSort(a, mid + 1, end);
            
            merge(a, start, mid, end);
        }
    }

    int reversePairs(vector<int>& nums) {
        res = 0;
        mergeSort(nums, 0, nums.size() - 1);
        return res;
    }
};
