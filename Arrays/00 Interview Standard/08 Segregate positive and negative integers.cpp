// https://www.techiedelight.com/positive-and-negative-integers-segregate/

/*
Given an array of positive and negative integers, 
segregate them by printing all negative numbers, followed by all positive numbers.

Input:  [9, -3, 5, -2, -8, -6, 1, 3]
Output: [-3, -2, -8, -6, 5, 9, 1, 3]
*/


// Method 1 (For all integers with same sign, order in which they were present is not preserved.)
/*
We can solve this problem in linear time by using the partitioning logic of Quicksort (https://www.techiedelight.com/quicksort)
The idea is to use 0 as a pivot element and make one pass of the partition process. 
*/

void partition(int a[], int n) {
    int pivot = 0;
    int pIndex = 0;

    // each time we find a negative number, `pIndex` is incremented,
    // and that element would be placed before the pivot
    for (int i = 0; i < n; i++) {
        // pivot is 0
        if (a[i] < pivot) {
            swap(a[i], a[pIndex]);
            pIndex++;
        }
    }
}
