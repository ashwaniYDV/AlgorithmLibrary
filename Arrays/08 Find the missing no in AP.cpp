// https://www.geeksforgeeks.org/find-missing-number-arithmetic-progression/


// C++ program to find the missing number in a given arithmetic progression
#include<iostream>
using namespace std;

// It assumes that there is exactly one missing element
// and may give incorrect result when there is no missing element or more than one missing elements.
// This function also assumes that the difference in AP is an integer.
int findMissing(int arr[], int n) {
    // If exactly one element is missing, then we can find difference of arithmetic progression using following formula.
    // Example, 2, 4, 6, 10, diff = (10 - 2) / 4 = 2.
    // The assumption in formula is that the difference is an integer.
    int diff = (arr[n - 1] - arr[0]) / n;

    int low = 0, high = n - 1;
    // There must be two elements to find the missing
    while (low < high) {
        int mid = low + (high - low) / 2;

        // The element just after the middle element is missing.
        if (arr[mid + 1] - arr[mid] != diff) return (arr[mid] + diff);

        // The element just before mid is missing
        if (mid > 0 && arr[mid] - arr[mid - 1] != diff) return (arr[mid - 1] + diff);

        // If the elements till mid follow AP, then recur for right half
        if (arr[mid] == arr[0] + mid * diff) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return -1;
}

int main() {
    int arr[] = {2, 4, 8, 10, 12, 14};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << findMissing(arr, n);
    return 0;
}
