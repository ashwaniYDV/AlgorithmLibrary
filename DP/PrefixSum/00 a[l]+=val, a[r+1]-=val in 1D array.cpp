// https://www.geeksforgeeks.org/constant-time-range-add-operation-array/

/*
Given an array of size N which is initialized with all zeros. 
We are given many ranges add queries, which should be applied to this array. 
We need to print the final updated array as our result. 

Examples: 

N = 6
Arr = [0, 0, 0, 0, 0, 0]
rangeUpdate1 [0, 2], add 100
Arr = [100, 100, 100, 0, 0, 0]
rangeUpdate1 [1, 5], add 100
Arr = [100, 200, 200, 100, 100, 100]
rangeUpdate1 [2, 3], add 100
Arr = [100, 200, 300, 200, 100, 100]
Which is the final updated array.
*/


int main() {
    int n = 6;
    vector<int> arr = vector<int>(n, 0);
    vector<vector<int> > queries = {{0, 2, 100}, {1, 5, 100}, {2, 3, 100}};


    for(auto it: queries) {
        int l = it[0], r = it[1], val = it[2];
        arr[l] += val;
        if(r+1 < n) {
            arr[r+1] -= val;
        }
    }

    for(int i = 1; i < n; i++) {
        arr[i] += arr[i - 1];
    }

    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
}
