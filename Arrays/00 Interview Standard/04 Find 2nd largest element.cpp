// https://www.geeksforgeeks.org/find-second-largest-element-array/

/*
Input: arr[] = {12, 35, 1, 10, 34, 1}
Output: The second largest element is 34.
Explanation: The largest element of the array is 35 and the second largest element is 34

Input: arr[] = {10, 5, 10}
Output: The second largest element is 5.
Explanation: The largest element of the array is 10 and the second largest element is 5

Input: arr[] = {10, 10, 10}
Output: The second largest does not exist.
Explanation: Largest element of the array is 10 there is no second largest element
*/



/*
Time = O(n)
Space = O(1)

Approach: Find the second largest element in a single traversal. 
Below is the complete algorithm for doing this:  
1) Initialize the first as 0 (i.e, index of arr[0] element)
2) Start traversing the array from array[1],
   a) If the current element in array say arr[i] is greater than first. Then update first and second as,
      second = first
      first = arr[i]
   b) If the current element is in between first and second, then update second to store the value of current variable as
      second = arr[i]
3) Return the value stored in second.
*/


class Solution {
public:
    int print2largest(int arr[], int n) {
        int first = 0, second = -1;
        for (int i = 1; i < n; i++) {
            if (arr[i] > arr[first]) {
                second = first;
                first = i;
            } else if (arr[i] < arr[first]) {
                if (second == -1 || arr[second] < arr[i]) {
                    second = i;
                }
            }
        }
        return second == -1 ? -1 : arr[second];
    }

};







/*
Time = O(2*n)
Space = O(1)
*/
class Solution {
public:
    int print2largest(int arr[], int n) {
        int largest = 0, secondLargest = -1;

        // finding the largest element in the array
        for (int i = 1; i < n; i++) {
            if (arr[i] > arr[largest])
                largest = i;
        }

        // finding the largest element in the array excluding the largest element calculated above
        for (int i = 0; i < n; i++) {
            if (arr[i] != arr[largest]) {
                // first change the value of second largest as soon as the next element is found
                if (secondLargest == -1 || arr[i] > arr[secondLargest])
                    secondLargest = i;
            }
        }
        return secondLargest == -1 ? -1 : arr[secondLargest];
    }
};
