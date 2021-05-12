// https://www.geeksforgeeks.org/counting-inversions/
// https://www.hackerearth.com/practice/algorithms/sorting/merge-sort/tutorial/

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
int n, m;
int res = 0;

void merge(int *a, int start, int mid, int end) {
    int temp[end - start + 1];
    int i = start, j = mid + 1, k = 0;

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

    for (int i = 0; i < k; i++) {
        a[start++] = temp[i];
    }
}

void mergeSort(int a[], int start, int end) {
    if (start < end) {
        int mid = (start + end) / 2;
        mergeSort(a, start, mid);
        mergeSort(a, mid + 1, end);
        merge(a, start, mid, end);
    }
}
 
void solve() {
    cin >> n;
    int a[n];
    f(i, n) cin >> a[i];
    
    mergeSort(a, 0, n - 1);
    cout << res << endl;
}































// Method 2 (Using BIT)
// https://www.geeksforgeeks.org/count-inversions-array-set-3-using-bit/
// It only works for whole numbers as array elements and for smaller value of elements
int n, m;

void update(int BIT[], int n, int i, int val) {
    while(i <= n) {
        BIT[i] += val;
        i += (i&-i);
    }
}

int query(int BIT[], int i) {
    int sum = 0;
    while(i > 0) {
        sum += BIT[i];
        i -= (i&-i);
    }
    return sum;
}
 
void solve() {
    cin >> n;
    int a[n];
    f(i, n) cin >> a[i];
    
    int invcount = 0; // Initialize result
 
    // Find maximum element in a[]
    int maxElement = 0;
    for (int i = 0; i < n; i++) {
        maxElement = max(maxElement, a[i]);
    }
 
    // Create a BIT with size equal to maxElement+1 (Extra one is used so that elements can be directly be used as index)
    int BIT[maxElement + 1];
    for (int i = 1; i <= maxElement; i++) {
        BIT[i] = 0;
    }
 
    // Traverse all elements from right.
    for (int i = n - 1; i >= 0; i--) {
        // Get count of elements smaller than a[i]
        invcount += query(BIT, a[i] - 1);
 
        // Add current element to BIT
        update(BIT, maxElement, a[i], 1);
    }
 
    cout << invcount << endl;
}




























// Method 3: (Using BIT)
// https://www.geeksforgeeks.org/count-inversions-array-set-3-using-bit/
int n, m;

void update(int BIT[], int n, int i, int val) {
    while(i <= n) {
        BIT[i] += val;
        i += (i&-i);
    }
}

int query(int BIT[], int i) {
    int sum = 0;
    while(i > 0) {
        sum += BIT[i];
        i -= (i&-i);
    }
    return sum;
}

// Converts an array to an array with values from 1 to n
// and relative order of smaller and greater elements remains same.
// For example, {7, -90, 100, 1} is converted to {3, 1, 4 ,2 }
void convert(int a[], int n) {
    // Create a copy of a[] in temp and sort the temp array in increasing order
    int temp[n];
    for (int i = 0; i < n; i++) {
        temp[i] = a[i];
    }
    sort(temp, temp + n);
 
    // Traverse all array elements
    for (int i = 0; i < n; i++) {
        // lower_bound() Returns pointer to the first element greater than or equal to a[i]
        a[i] = lower_bound(temp, temp + n, a[i]) - temp + 1;
    }
} 

void solve() {
    cin >> n;
    int a[n];
    f(i, n) cin >> a[i];

    convert(a, n);
    
    int invcount = 0; // Initialize result
 
    // Find maximum element in a[]
    int maxElement = 0;
    for (int i = 0; i < n; i++) {
        maxElement = max(maxElement, a[i]);
    }
 
    // Create a BIT with size equal to maxElement+1 (Extra one is used so that elements can be directly be used as index)
    int BIT[maxElement + 1];
    for (int i = 1; i <= maxElement; i++) {
        BIT[i] = 0;
    }
 
    // Traverse all elements from right.
    for (int i = n - 1; i >= 0; i--) {
        // Get count of elements smaller than a[i]
        invcount += query(BIT, a[i] - 1);
 
        // Add current element to BIT
        update(BIT, maxElement, a[i], 1);
    }
 
    cout << invcount << endl;
}
