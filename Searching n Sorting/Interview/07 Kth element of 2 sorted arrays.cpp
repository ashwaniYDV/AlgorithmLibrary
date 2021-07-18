// https://practice.geeksforgeeks.org/problems/k-th-element-of-two-sorted-array1317/1
// https://youtu.be/nv7F4PiLUzo
// Google interview

/*
Given two sorted arrays size N and M respectively and an element K. 
Find the element that would be at the kth position of the final sorted array.

Input:
    arr1[] = {2, 3, 6, 7, 9}
    arr2[] = {1, 3, 8, 10}
    k = 5
Output: 
    6
Explanation:
    Final sorted array would be: 1, 2, 3, 3, 6, 7, 8, 9, 10
    5th element of this array is 6.
*/



// Time = O(log(min(n1, n2, k)))

class Solution{
public:
    int kthElement(int arr1[], int arr2[], int n1, int n2, int k) {
        if(n1 > n2) {
            return kthElement(arr2, arr1, n2, n1, k); 
        }
        
        // min no of elements that can be taken from arr1
        int low = max(0, k - n2);
        // max no of elements that can be taken from arr1
        int high = min(k, n1);
        
        while(low <= high) {
            // no of elements taken from arr1 from starting
            int cut1 = (low + high) >> 1; 
            // no of elements taken from arr2 from starting
            int cut2 = k - cut1; 
            int l1 = cut1 == 0 ? INT_MIN : arr1[cut1 - 1]; 
            int l2 = cut2 == 0 ? INT_MIN : arr2[cut2 - 1];
            int r1 = cut1 == n1 ? INT_MAX : arr1[cut1]; 
            int r2 = cut2 == n2 ? INT_MAX : arr2[cut2]; 
            
            if(l1 <= r2 && l2 <= r1) {
                return max(l1, l2);
            }
            
            if (l1 > r2) {
                high = cut1 - 1;
            } else {
                low = cut1 + 1; 
            }
        }
        return -1;
    }
};







class Solution {
public:
    int kthElement(int arr1[], int arr2[], int n, int m, int k) {
        int cnt = 0, i = 0, j = 0;
        while (i < n && j < m) {
            if (arr1[i] < arr2[j]) {
                cnt++;
                if (cnt == k) return arr1[i];
                i++;
            } else {
                cnt++;
                if (cnt == k)
                    return arr2[j];
                j++;
            }
        }
        while (i < n) {
            cnt++;
            if (cnt == k) return arr1[i];
            i++;
        }
        while (j < m) {
            cnt++;
            if (cnt == k) return arr2[j];
            j++;
        }
        return -1;
    }
};





// kth element in row-wise sorted matrix concept
class Solution {
public:
    int kthElement(int arr1[], int arr2[], int n, int m, int k) {
        int lo = min(arr1[0], arr2[0]), hi = max(arr1[n - 1], arr2[m - 1]);

        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;

            int cnt = upper_bound(arr1, arr1 + n, mid) - arr1;
            cnt += upper_bound(arr2, arr2 + m, mid) - arr2;

            if (cnt >= k)
                hi = mid;
            else
                lo = mid + 1;
        }
        return lo;
    }
};






class Solution {
public:
    int kthElement(int arr1[], int arr2[], int n, int m, int k) {
        priority_queue<array<int, 3>, vector<array<int, 3>>, greater<array<int, 3>> > pq;

        pq.push({ arr1[0], 1, 0 });
        pq.push({ arr2[0], 2, 0 });
        int res;

        while (!pq.empty() && k--) {
            auto cur = pq.top();
            pq.pop();

            res = cur[0];
            // i = arr1 or arr2
            // j = idx in that arr
            int i = cur[1];
            int j = cur[2];

            if (i == 1) {
                if (j + 1 < n) {
                    pq.push({ arr1[j + 1], i, j + 1 });
                }
            }
            if (i == 2) {
                if (j + 1 < m) {
                    pq.push({ arr2[j + 1], i, j + 1 });
                }
            }
        }

        return res;
    }
};
