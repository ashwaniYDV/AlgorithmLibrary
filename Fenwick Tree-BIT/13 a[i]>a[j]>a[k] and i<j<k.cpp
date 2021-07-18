// https://www.geeksforgeeks.org/find-number-of-triplets-in-array-such-that-aiajak-and-ijk/

/*
Given an array arr of size N. The task is to count number of triplets in the array such that a[i]>a[j]>a[k] and i<j<k
 
Input : arr[] = {10, 8, 3, 1} 
Output : 4 
The triplets are: 
1, 3, 8 
1, 3, 10 
1, 8, 10 
3, 8, 10
*/



// CPP program to find triplets a[i] > a[j] > a[k] and i < j < k
#include<bits/stdc++.h>
using namespace std;

// Updates a node in Binary Index Tree (BIT)
// at given index(i) in BIT. The given value
// 'val' is added to BITree[i] and
// all of its ancestors in tree.
void update(int BIT[], int n, int i, int val) {
    for (; i <= n; i += (i & -i)) {
        BIT[i] += val;
    }
}

// Returns sum of arr[0..i]. This function
// assumes that the array is preprocessed
// and partial sums of array elements are
// stored in BIT[].
int query(int BIT[], int i) {
    int sum = 0;
    for (; i > 0; i -= (i & -i)) {
        sum += BIT[i];
    }
    return sum;
}

// Converts an array to an array with values from 1 to n
// and relative order of smaller and greater elements
// remains same. For example, {7, -90, 100, 1} is
// converted to {3, 1, 4 ,2 }
void CoordinateCompression(int arr[], int n) {
    set<int> st(arr, arr + n);
    map<int, int> mp;

    int rank = 0;
    for (int x : st) mp[x] = ++rank;

    for (int i = 0; i < n; i++) {
        arr[i] = mp[arr[i]];
    }
}

// Function to find triplets
int getCount(int arr[], int n) {
    // Decomposition
    CoordinateCompression(arr, n);

    int BIT[n + 1] = { 0 };
    int smaller_right[n + 1] = { 0 };
    int greater_left[n + 1] = { 0 };

    // Find all right side smaller elements
    for (int i = n - 1; i >= 0; i--) {
        smaller_right[i] = query(BIT, arr[i] - 1);
        update(BIT, n, arr[i], 1);
    }

    for (int i = 0; i <= n; i++) {
        BIT[i] = 0;
    }

    // Find all left side greater elements
    for (int i = 0; i < n; i++) {
        greater_left[i] = query(BIT, n) - query(BIT, arr[i]);
        update(BIT, n, arr[i], 1);
    }

    // Find the required answer
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans += greater_left[i] * smaller_right[i];
    }

    // Return the required answer
    return ans;
}

// Driver code
int main() {
    int arr[] = { 7, 3, 4, 3, 3, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << getCount(arr, n) << endl;
    return 0;
}
