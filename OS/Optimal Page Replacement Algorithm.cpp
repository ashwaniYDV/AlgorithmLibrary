// https://www.geeksforgeeks.org/optimal-page-replacement-algorithm/

/*
Algorithm:
1) If referred page is already present, increment hit count.
2) If not present, find if a page that is never referenced in future. If such a page exists, replace this page with new page. 
   If no such page exists, find a page that is referenced farthest in future. Replace this page with new page.
*/



// CPP program to demonstrate optimal page replacement algorithm.
#include <bits/stdc++.h>
using namespace std;

// Function to check whether a page exists in a frame or not
bool search(int key, vector<int>& frame) {
    for (int i = 0; i < frame.size(); i++) {
        if (frame[i] == key) return true;
    }
    return false;
}

// Function to find the frame that will not be used recently in future after given index in page[0..n-1]
int predict(int page[], vector<int>& frame, int n, int index) {
    // Store the index of pages which are going to be used recently in future
    int res = -1, farthest = index;
    for (int i = 0; i < frame.size(); i++) {
        int j;
        for (j = index; j < n; j++) {
            if (frame[i] == page[j]) {
                if (j > farthest) {
                    farthest = j;
                    res = i;
                }
                break;
            }
        }

        // If a page is never referenced in future, return it.
        if (j == n) {
            return i;
        }
    }

    // If all of the frames were not in future,
    // return any of them, we return 0. Otherwise we return res.
    return (res == -1) ? 0 : res;
}

void optimalPage(int page[], int n, int no_of_frames) {
    // Create an array for given number of frames and initialize it as empty.
    vector<int> frame;

    // Traverse through page reference array
    // and check for miss and hit.
    int hit = 0;
    for (int i = 0; i < n; i++) {

        // Page found in a frame: HIT
        if (search(page[i], frame)) {
            hit++;
            continue;
        }

        // Page not found in a frame: MISS

        // If there is space available in frames.
        if (frame.size() < no_of_frames) {
            frame.push_back(page[i]);
        }

        // Find the page to be replaced.
        else {
            int j = predict(page, frame, n, i + 1);
            frame[j] = page[i];
        }
    }

    cout << "No. of hits = " << hit << endl;
    cout << "No. of misses = " << n - hit << endl;
}

int main() {
    int page[] = { 7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2 };
    int n = sizeof(page) / sizeof(page[0]);
    int no_of_frames = 4;
    optimalPage(page, n, no_of_frames);
    return 0;
}
