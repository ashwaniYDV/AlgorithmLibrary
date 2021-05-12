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
