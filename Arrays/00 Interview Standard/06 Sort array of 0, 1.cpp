// https://www.geeksforgeeks.org/segregate-0s-and-1s-in-an-array-by-traversing-array-once/


// Dutch National Flag Algorithm for sorting 0, 1, 2 elements array (ignoring '2' for this question) 
#include <bits/stdc++.h>
using namespace std;

void segregate0and1(int arr[], int n) {
    int lo = 0;
    int hi = n - 1;
    int mid = 0;

    while (mid <= hi) {
        int x = arr[mid];

        if (x == 0) {
            swap(arr[lo++], arr[mid++]);
        }

        if (x == 1) {
            mid++;
        }

        // if(x == 2) {
        //     swap(arr[mid], arr[hi--]);
        // }
    }
}

int main() {
    int arr[] = {0, 1, 0, 1, 1, 1};
    int i, arr_size = sizeof(arr) / sizeof(arr[0]);

    segregate0and1(arr, arr_size);

    for (i = 0; i < arr_size; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}



















// C++ program to sort a binary array in one pass
#include <bits/stdc++.h>
using namespace std;

void segregate0and1(int arr[], int n) {
    int type0 = 0;
    int type1 = n - 1;

    while (type0 < type1) {
        if (arr[type0] == 1) {
            swap(arr[type0], arr[type1]);
            type1--;
        } else {
            type0++;
        }
    }
}

int main() {
    int arr[] = {0, 1, 0, 1, 1, 1};
    int i, arr_size = sizeof(arr) / sizeof(arr[0]);

    segregate0and1(arr, arr_size);

    for (i = 0; i < arr_size; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}








// C++ program to sort a binary array in one pass
#include <bits/stdc++.h>
using namespace std;

void segregate0and1(int arr[], int size) {
    /* Initialize left and right indexes */
    int left = 0, right = size - 1;

    while (left < right) {
        /* Increment left index while we see 0 at left */
        while (arr[left] == 0 && left < right) {
            left++;
        }

        /* Decrement right index while we see 1 at right */
        while (arr[right] == 1 && left < right) {
            right--;
        }

        /* If left is smaller than right then there is a 1 at left and a 0 at right.
        Exchange arr[left] and arr[right]*/
        if (left < right) {
            arr[left] = 0;
            arr[right] = 1;
            left++;
            right--;
        }
    }
}

int main() {
    int arr[] = {0, 1, 0, 1, 1, 1};
    int i, arr_size = sizeof(arr) / sizeof(arr[0]);

    segregate0and1(arr, arr_size);

    cout << "Array after segregation ";
    for (i = 0; i < 6; i++)
        cout << arr[i] << " ";
    return 0;
}
