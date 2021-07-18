// https://practice.geeksforgeeks.org/problems/find-the-smallest-and-second-smallest-element-in-an-array3226/1
// https://www.geeksforgeeks.org/to-find-smallest-and-second-smallest-element-in-an-array/


vector<int> minAnd2ndMin(int arr[], int n) {
    int first = 0, second = -1;
    for (int i = 1; i < n ; i ++) {
        // If current element is smaller than first then update both first and second
        if (arr[i] < arr[first]) {
            second = first;
            first = i;
        }

        /* If arr[i] is in between first and second then update second */
        else if (arr[i] > arr[first]) {
            if (second == -1 || arr[second] > arr[i]) {
                second = i;
            }
        }
    }

    if (second == -1) return { -1 };

    return {arr[first], arr[second]};
}














vector<int> minAnd2ndMin(int arr[], int n) {
    int first = INT_MAX, second = INT_MAX;
    for (int i = 0; i < n ; i ++) {
        // If current element is smaller than first then update both first and second
        if (arr[i] < first) {
            second = first;
            first = arr[i];
        }

        /* If arr[i] is in between first and second then update second */
        else if (arr[i] < second && arr[i] != first) {
            second = arr[i];
        }
    }

    if (second == INT_MAX) return { -1 };

    return {first, second};
}
