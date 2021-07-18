// https://www.techiedelight.com/find-maximum-sequence-of-continuous-1s-can-formed-replacing-k-zeroes-ones/
// https://leetcode.com/problems/max-consecutive-ones-iii/
 
/*
We can solve this problem by using the sliding window technique. 
The idea is to maintain a window containing at most k zeroes at any point. 
Add elements to the window from the right until it becomes unstable. 
The window becomes unstable if the total number of zeros in it becomes more than k . 
IF the window becomes unstable, remove elements from its left till it becomes stable again (by removing leftmost zeros). 
IF the window is stable and the current window length is more than the maximum window found so far, set the maximum window size to the current window size. 
*/

// Find the maximum sequence of continuous 1's by replacing at most `k` zeroes by 1 using sliding window technique
void findLongestSequence(vector<int>& a, int n, int k) {
    // represents the current window's starting index
    int left = 0;
    // stores the total number of zeros in the current window
    int zeroCount = 0;
 
    // stores the maximum number of continuous 1's found so far (including `k` zeroes)
    int window = 0;
 
    // stores the left and right index of maximum window found so far
    int leftIndex = 0, rightIndex = 0;
 
    // maintain a window `[left…right]` containing at most `k` zeroes
    for (int right = 0; right < n; right++) {
        // if the current element is 0, increase the zeroCount of zeros in the current window by 1
        if (a[right] == 0) {
            zeroCount++;
        }
 
        // the window becomes unstable if the total number of zeros in it becomes more than `k`
        while (zeroCount > k) {
            // if we have found zero, decrement the number of zeros in the current window by 1
            if (a[left] == 0) {
                zeroCount--;
            }
            // remove elements from the window's left side till the window becomes stable again
            left++;
        }
 
        // when we reach here, window `[left…right]` contains at most
        // `k` zeroes, and we update max window size and leftmost index
        // of the window
        if (right - left + 1 > window) {
            window = right - left + 1;
            leftIndex = left;
            rightIndex = right;
        }
    }
 
    // print the maximum sequence of continuous 1's
    cout << "The longest sequence has length: " << window << endl; 
    cout << "From index " << leftIndex << " to " << rightIndex << endl;
}

void solve() {
    vi a = { 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 0, 0 };
    int k = 2;
    int n = a.size();
    findLongestSequence(a, n, k);
}
