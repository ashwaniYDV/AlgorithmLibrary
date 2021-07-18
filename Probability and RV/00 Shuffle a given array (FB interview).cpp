// Shuffle a given array using Fisher–Yates shuffle Algorithm
// https://www.geeksforgeeks.org/shuffle-a-given-array-using-fisher-yates-shuffle-algorithm/
// Rachit: https://youtu.be/hSZARPLUSDM 

// Method 1
#include<bits/stdc++.h>
using namespace std;


// A utility function to print an array
void printArray (int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << "\n";
}

// A function to generate a random permutation of arr[]
void randomize (int arr[], int n) {
    // Use a different seed value so that we don't get same result each time we run this program
    srand (time(NULL));

    // Start from the last element and swap one by one.
    for (int i = n - 1; i >= 0; i--) {
        // Pick a random index from 0 to i
        int j = rand() % (i + 1);

        // Swap arr[i] with the element at random index
        swap(arr[i], arr[j]);
    }
}

// Driver Code
int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    randomize (arr, n);
    printArray(arr, n);

    return 0;
}

/*
7 8 4 6 3 1 2 5
Note: Output will differ every time as it selects and prints random elements
*/


























// Method 2
#include<bits/stdc++.h>
using namespace std;


// A utility function to print an array
void printArray (int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << "\n";
}

// A function to generate a random permutation of arr[]
void randomize (int arr[], int n) {
    // Use a different seed value so that we don't get same result each time we run this program
    srand (time(NULL));

    for (int i = 0; i < n; i++) {
        // Pick a random index from i to n-1
        int mn = i, mx = n-1;
        int j = mn + (rand() % (mx - mn + 1));

        // Swap arr[i] with the element at random index
        swap(arr[i], arr[j]);
    }
}

// Driver Code
int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    randomize (arr, n);
    printArray(arr, n);

    return 0;
}
