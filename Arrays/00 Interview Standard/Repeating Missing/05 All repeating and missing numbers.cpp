// C++ program to Find the repeating and missing elements

#include <bits/stdc++.h>
using namespace std;

void printRepeatingAndMissing(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        while (arr[i] != arr[arr[i] - 1]) {
            swap(arr[i], arr[arr[i] - 1]);
        }
    }

    for (int i = 0; i < n; i++) {
        if (arr[i] != i + 1) {
            cout << "Repeating: " << arr[i] << endl;
            cout << "Missing: " << i + 1 << endl;
        }
    }
}

int main() {
    int arr[] = { 1, 2, 3, 8, 2, 3, 5, 1 };
    int n = sizeof(arr) / sizeof(arr[0]);
    printRepeatingAndMissing(arr, n);
}
