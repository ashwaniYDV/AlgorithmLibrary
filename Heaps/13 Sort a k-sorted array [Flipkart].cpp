// Sort a k-sorted array | Sort a nearly sorted array 
// https://www.techiedelight.com/sort-k-sorted-array/
// https://www.geeksforgeeks.org/nearly-sorted-algorithm/
// https://www.geeksforgeeks.org/sort-a-nearly-sorted-array-using-stl/

/*
Given an array of n elements, where each element is at most k away from its target position, 
devise a space and time efficient algorithm that sorts in O(n*logk) time. 

For example, let us consider k is 2, an element at index 7 in the sorted array, can be at indexes 5, 6, 7, 8, 9 in the given array. 
It may be assumed that k < n.

Input: arr[] = {6, 5, 3, 2, 8, 10, 9}, k = 3
Output: arr[] = {2, 3, 5, 6, 8, 9, 10}
*/


void sortKSortedArray(vector<int> &A, int k) {
    // create an empty min-heap
    priority_queue<int, vector<int>, greater<int>> pq;
 
    // insert the first `k+1` elements into a heap
    for (int i = 0; i < k+1; i++) {
        pq.push(A[i]);
    }
 
    int index = 0;
 
    // do for remaining elements in the array
    for (int i = k + 1; i < A.size(); i++) {
        // pop the top element from the min-heap and assign them to the next available array index
        A[index++] = pq.top();
        pq.pop();
 
        // push the next array element into min-heap
        pq.push(A[i]);
    }
 
    // pop all remaining elements from the min-heap and assign them to the next available array index
    while (!pq.empty()) {
        A[index++] = pq.top();
        pq.pop();
    }
}
 
int main() {
    vector<int> A = { 1, 4, 5, 2, 3, 7, 8, 6, 10, 9};
    int k = 2;
    sortKSortedArray(A, k);
    for (int &i: A) {
        cout << i << " ";
    }
    return 0;
}
