// https://www.geeksforgeeks.org/counting-inversions/
// https://www.hackerearth.com/practice/algorithms/sorting/merge-sort/tutorial/
// https://practice.geeksforgeeks.org/problems/inversion-of-array-1587115620/1

/*
Given an array A on size N, you need to find the number of ordered pairs (i, j) such that i < j  and A[i] > A[j].

Algorithm: 
1) The idea is similar to merge sort, divide the array into two equal or almost equal halves in each step until the base case is reached.
2) Create a function merge that counts the number of inversions when two halves of the array are merged, 
   create two indices i and j, i is the index for the first half, and j is an index of the second half. 
   if a[i] is greater than a[j], then there are (mid – i) inversions. because left and right subarrays are sorted, 
   so all the remaining elements in left-subarray (a[i+1], a[i+2] ... a[mid]) will be greater than a[j].
*/

/*
This is known as “Inversion Counting” problem.
It can be solved using a Binary Indexed Tree (BIT) or Merge Sort.

http://www.geeksforgeeks.org/count-inversions-array-set-3-using-bit/ 121
*/



// Method 1 (Merge Sort)
class Solution {
public:
    #define ll long long
    ll res = 0;
    
    void merge(ll a[], ll start, ll mid, ll end) {
        ll temp[end - start + 1];
        ll i = start, j = mid + 1, k = 0;
    
        while (i <= mid && j <= end) {
            if (a[i] <= a[j]) {
                temp[k++] = a[i++];
            } else {
                res += (mid - i + 1);
                temp[k++] = a[j++];
            }
        }
        while (i <= mid) {
            temp[k++] = a[i++];
        }
        while (j <= end) {
            temp[k++] = a[j++];
        }
    
        for (ll i = 0; i < k; i++) {
            a[start++] = temp[i];
        }
    }
    
    void mergeSort(ll a[], ll start, ll end) {
        if (start < end) {
            ll mid = (start + end) / 2;
            mergeSort(a, start, mid);
            mergeSort(a, mid + 1, end);
            merge(a, start, mid, end);
        }
    }
    
    long long int inversionCount(long long a[], long long n) {
        res = 0;
        mergeSort(a, 0, n - 1);
        return res;
    }
};


















// Method 2 (Using BIT)
// https://www.geeksforgeeks.org/count-inversions-array-set-3-using-bit/
class Solution {
public:
    #define ll long long
    vector<ll> BIT;
    ll n;

    void update(ll i, ll val) {
        while(i <= n) {
            BIT[i] += val;
            i += (i&-i);
        }
    }

    ll query(ll i) {
        ll sum = 0;
        while(i > 0) {
            sum += BIT[i];
            i -= (i&-i);
        }
        return sum;
    }
    
    long long int inversionCount(long long a[], long long size) {
        unordered_map<ll, ll> mp;
        ll rank = 0;
        set<ll> st(a, a + size);
        for(ll it: st) {
            mp[it] = ++rank;
        }
        
        // coordinate compression 
        for(ll i = 0; i < size; i++) {
            a[i] = mp[a[i]];
        }

        // size of BIT array
        n = rank;
        BIT = vector<ll>(n + 1, 0);

        ll res = 0;
        for(ll i = size - 1; i >= 0; i--) {
            // Get count of elements smaller than a[i]
            res += query(a[i] - 1);
            update(a[i], 1);
        }
        
        return res;
    }
};
