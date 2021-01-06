// https://www.geeksforgeeks.org/maximum-or-value-of-a-pair-in-an-array/

#include <bits/stdc++.h>
using namespace std;

int maxOR(int arr[], int n)
{
    // find maximum element in the array
    int max_value = *max_element(arr, arr + n);
 
    // To store the maximum OR value
    int ans = 0;
 
    // iterate over rest array elements and find maximum OR value pair
    for (int i = 0; i < n; i++) {
        ans = max(ans, (max_value | arr[i]));
    }
    return ans;
}
 
// Driver code
int main()
{
    int arr[] = { 3, 6, 8, 16 };
    int n = sizeof(arr) / sizeof(arr[0]);
 
    cout << maxOR(arr, n);
 
    return 0;
}
