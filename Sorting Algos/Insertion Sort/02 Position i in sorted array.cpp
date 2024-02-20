// https://www.hackerearth.com/practice/algorithms/sorting/insertion-sort/tutorial/?purpose=login&source=practice&update=google

/*
You have been given an A array consisting of N integers. All the elements in this array are guaranteed to be unique. 
For each position i in the array A you need to find the position should be present in, if the array was a sorted array. 
You need to find this for each i and print the resulting solution.
*/



#include <bits/stdc++.h>
using namespace std;

void insertionSortFun(int arr[], int n) {
    int pos[n];
    for(int i = 0; i < n; i++) pos[i] = i+1;

    for (int i = 1; i < n; i++) {
        for (int j = i; j > 0; j--) {
            if(arr[j] < arr[j - 1]) {
                swap(arr[j], arr[j - 1]);
                swap(pos[j], pos[j - 1]);
            } else {
                break;
            }
        }
    }

    int res[n];
    for(int i = 0; i < n; i++) res[pos[i] - 1] = i + 1;
    for(int i = 0; i < n; i++) cout << res[i] << " ";
    cout << endl;

}

int main() {
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++) cin >> arr[i];
    insertionSortFun(arr, n);
}
