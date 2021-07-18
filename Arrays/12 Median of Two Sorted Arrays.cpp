// https://leetcode.com/problems/median-of-two-sorted-arrays/

/*
Given two sorted arrays nums1 and nums2 of size n and m respectively, return the median of the two sorted arrays.
The overall run time complexity should be O(log(n + m)).
*/


// Time = O(log(min(n, m)))

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }
        int n1 = nums1.size(), n2 = nums2.size();

        // min no of elements that can be taken from nums1
        int low = 0;
        // max no of elements that can be taken from nums1
        int high = n1;

        while (low <= high) {
            // no of elements taken from nums1 from starting
            int cut1 = (low + high) >> 1;
            // no of elements taken from nums2 from starting
            int cut2 = ((n1 + n2 + 1) / 2) - cut1;

            int left1 = cut1 == 0 ? INT_MIN : nums1[cut1 - 1];
            int left2 = cut2 == 0 ? INT_MIN : nums2[cut2 - 1];
            int right1 = cut1 == n1 ? INT_MAX : nums1[cut1];
            int right2 = cut2 == n2 ? INT_MAX : nums2[cut2];

            if (left1 <= right2 && left2 <= right1) {
                if ((n1 + n2) % 2) return max(left1, left2);
                return (max(left1, left2) + min(right1, right2)) / 2.0;
            }

            if (left1 > right2) {
                high = cut1 - 1;
            } else {
                low = cut1 + 1;
            }
        }
        return 0.0;
    }
};









// Using K-th largest ele of two sorted arrays concept

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }
        int n1 = nums1.size(), n2 = nums2.size();
        
        int k = (n1 + n2 + 1) / 2;

        // min no of elements that can be taken from nums1
        int low = max(0, k - n2);
        // max no of elements that can be taken from nums1
        int high = min(k, n1);

        while (low <= high) {
            // no of elements taken from nums1 from starting
            int cut1 = (low + high) >> 1;
            // no of elements taken from nums2 from starting
            int cut2 = k - cut1;

            int left1 = cut1 == 0 ? INT_MIN : nums1[cut1 - 1];
            int left2 = cut2 == 0 ? INT_MIN : nums2[cut2 - 1];
            int right1 = cut1 == n1 ? INT_MAX : nums1[cut1];
            int right2 = cut2 == n2 ? INT_MAX : nums2[cut2];

            if (left1 <= right2 && left2 <= right1) {
                if ((n1 + n2) % 2) return max(left1, left2);
                return (max(left1, left2) + min(right1, right2)) / 2.0;
            }

            if (left1 > right2) {
                high = cut1 - 1;
            } else {
                low = cut1 + 1;
            }
        }
        return 0.0;
    }
};



















/*
Using median of row-wise sorted matrix concept.
*/

class Solution {
public:
    int bs(vector<int>& a, vector<int>& b, int target) {
        int n = a.size(), m = b.size();
        int lo = min(a[0], b[0]), hi = max(a[n - 1], b[m - 1]);

        while (lo < hi) {
            int mid = (lo + hi) >> 1;

            int cnt = upper_bound(a.begin(), a.end(), mid) - a.begin();
            cnt += upper_bound(b.begin(), b.end(), mid) - b.begin();

            if (cnt >= target) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        return lo;
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        if (n == 0 && m == 0) return 0;
        if (m == 0) {
            if (n % 2) {
                return nums1[n / 2];
            } else {
                return (double)(nums1[n / 2 - 1] + nums1[n / 2]) / 2.0;
            }
        }
        if (n == 0) {
            if (m % 2) {
                return nums2[m / 2];
            } else {
                return (double)(nums2[m / 2 - 1] + nums2[m / 2]) / 2.0;
            }
        }

        int target = (n + m + 1) / 2;
        if ((n + m) % 2) {
            return (double)bs(nums1, nums2, target);
        } else {
            double x = (double)bs(nums1, nums2, target);
            double y = (double)bs(nums1, nums2, target + 1);
            return (x + y) / 2.0;
        }
    }
};
