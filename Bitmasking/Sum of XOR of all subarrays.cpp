// https://www.geeksforgeeks.org/sum-of-xor-of-all-subarrays/

// C++ program to find the sum of XOR of all subarray of the array

#include <iostream>
#include <vector>
using namespace std;

// Function to calculate the sum of XOR of all subarrays
int findXorSum(int arr[], int n) {
    // variable to store the final sum
    int sum = 0;

    // multiplier
    int mul = 1;

    for (int i = 0; i < 30; i++) {

        // variable to store number of sub-arrays with odd number of elements
        // with ith bits starting from the first
        // element to the end of the array
        int c_odd = 0;

        // variable to check the status of the odd-even count while calculating c_odd
        bool odd = 0;

        // loop to calculate initial value of c_odd
        // c_odd = no of subaarys with starting index as 0 and odd no of set bits at i'th index
        for (int j = 0; j < n; j++) {
            if ((arr[j] & (1 << i)) > 0)
                odd = (!odd);
            if (odd)
                c_odd++;
        }

        // loop to iterate through all the elements of the array and update sum
        // (mul * c_odd) = contrinution when starting index of all the subarrays is j
        for (int j = 0; j < n; j++) {
            sum += (mul * c_odd);

            if ((arr[j] & (1 << i)) > 0)
                c_odd = (n - j - c_odd);
        }

        // updating the multiplier
        mul *= 2;
    }

    // returning the sum
    return sum;
}

// Driver Code
int main() {
    int arr[] = { 3, 8, 13 };
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << findXorSum(arr, n);
    return 0;
}
