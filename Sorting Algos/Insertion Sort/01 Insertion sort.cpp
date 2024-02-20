// https://www.hackerearth.com/practice/algorithms/sorting/insertion-sort/tutorial/
// https://www.geeksforgeeks.org/insertion-sort/

/*
Best time = O(n)
Worst Time = O(n^2)
*/


/*
Insertion sort is based on the idea that one element from the input elements is consumed in each iteration to find its correct position 
i.e, the position to which it belongs in a sorted array.
It iterates the input elements by growing the sorted array at each iteration. 
It compares the current element with the largest value in the sorted array. 
If the current element is greater, then it leaves the element in its place and moves on to the next element 
else it finds its correct position in the sorted array and moves it to that position. 
This is done by shifting all the elements, which are larger than the current element, in the sorted array to one position ahead
*/

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        for (int j = i; j > 0; j--) {
            if(arr[j] < arr[j - 1]) {
                swap(arr[j], arr[j - 1]);
            } else {
                break;
            }
        }
    }
}
int main() {
    int arr[] = { 12, 11, 13, 5, 6 };
    int n = sizeof(arr) / sizeof(arr[0]);

    insertionSort(arr, n);
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
}





void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i;

        // Move elements of arr[0..i-1], that are greater than key, to one position ahead of their current position
        while (j > 0 && arr[j - 1] > key) {
            arr[j] = arr[j - 1];
            j = j - 1;
        }
        arr[j] = key;
    }
}
int main() {
    int arr[] = { 12, 11, 13, 5, 6 };
    int n = sizeof(arr) / sizeof(arr[0]);
    insertionSort(arr, n);
    for (int i = 0; i < n; i++) cout << arr[i] << " ";  
}
