// https://www.hackerearth.com/practice/algorithms/sorting/merge-sort/tutorial/

/*
Given an array A on size N, you need to find the number of ordered pairs (i, j) such that i < j  and A[i] > A[j].
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
