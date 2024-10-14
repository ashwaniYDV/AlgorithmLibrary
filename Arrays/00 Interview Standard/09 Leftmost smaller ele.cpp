/*
Que 1) Find leftmost smaller number in an array.

Input:
[2, 1, 3, 2, 1, 3]
Output:
[-1, -1, 2, 1, -1, 2]

Problem was asked in Amazon's and Google's interview.
How will you start your discussion with your interviewer?
what all things will come in your mind first?
*/


// Method 1
#include <bits/stdc++.h>
using namespace std;

vector<int> farthest_min_to_left(int a[], int n) {
    int prefix_min[n];
    prefix_min[0] = a[0];
    for (int i = 1; i < n; i++) {
        prefix_min[i] = min(prefix_min[i - 1], a[i]);
    }

    vector<int> res;
    for (int i = 0; i < n; i++) {
        int low = 0, high = i-1, ans = -1;

        // FFFFFTTTT
        while (low <= high) {
            int mid = (low + high) / 2;
            if (prefix_min[mid] < a[i]) {
                ans = a[mid];
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        res.push_back(ans);
    }

    return res;
}

int main() {
    int a[] = { 3, 1, 5, 2, 4 };
    int n = sizeof(a) / sizeof(a[0]);

    vector<int> res = farthest_min_to_left(a, n);
    for(int x: res) cout << x << " ";
}


// Method 2
#include <bits/stdc++.h>
using namespace std;

vector<int> farthest_min_to_left(int a[], int n) {
    vector<int> dec; // monotonically decreasing
    dec.push_back(a[0]);

    vector<int> res;
    res.push_back(-1);

    for (int i = 1; i < n; i++) {
        int low = 0, high = (int)dec.size() - 1, ans = -1;

        // FFFFFTTTT
        while (low <= high) {
            int mid = (low + high) / 2;
            if (dec[mid] < a[i]) {
                ans = dec[mid];
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        res.push_back(ans);

        if(a[i] < dec.back()) {
            dec.push_back(a[i]);
        }
    }

    return res;
}

int main() {
    int a[] = { 3, 1, 5, 2, 4 };
    int n = sizeof(a) / sizeof(a[0]);

    vector<int> res = farthest_min_to_left(a, n);
    for(int x: res) cout << x << " ";
}







/*
Que 2) Rightmost smaller element.

https://www.geeksforgeeks.org/find-the-farthest-smaller-number-in-the-right-side/
*/


// Method 1
#include <bits/stdc++.h>
using namespace std;

vector<int> farthest_min_to_right(int a[], int n) {
    int suffix_min[n];
    suffix_min[n - 1] = a[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        suffix_min[i] = min(suffix_min[i + 1], a[i]);
    }

    vector<int> res;
    for (int i = 0; i < n; i++) {
        int low = i + 1, high = n-1, ans = -1;

        // TTTTTFFFFF
        while (low <= high) {
            int mid = (low + high) / 2;
            if (suffix_min[mid] < a[i]) {
                ans = a[mid];
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        res.push_back(ans);
    }

    return res;
}

int main() {
    int a[] = { 3, 1, 5, 2, 4 };
    int n = sizeof(a) / sizeof(a[0]);

    vector<int> res = farthest_min_to_right(a, n);
    for(int x: res) cout << x << " ";
}
