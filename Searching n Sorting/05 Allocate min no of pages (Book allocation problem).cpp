// https://practice.geeksforgeeks.org/problems/allocate-minimum-number-of-pages0937/1
// https://www.geeksforgeeks.org/allocate-minimum-number-pages/
// https://www.interviewbit.com/problems/allocate-books/

/*
You are given N number of books having pages[i] number of pages. 
You have to allocate contagious books to M number of students so that maximum number of pages alloted to a student is minimum.

A book will be allocated to exactly one student.
Each student has to be allocated at least one book.
Allotment should be in contiguous order, for example: A student cannot be allocated book 1 and book 3, skipping book 2.

Input:
pages[] = {12,34,67,90}
M = 2
Output:
113
Explanation: 
Allocation can be done in following ways:
{12} and {34, 67, 90} Maximum Pages = 191
{12, 34} and {67, 90} Maximum Pages = 157
{12, 34, 67} and {90}  Maximum Pages =113
Therefore, the minimum of these cases is 113, which is selected as the output.
*/


// FFFFFFFFTTTTTT (condition => cnt <= mid)


bool check(int mid, int m, vector<int>& pages) {
    int cnt = 1, sum = 0;
    for (int i = 0; i < pages.size(); i++) {
        sum += pages[i];
        if (sum > mid) {
            sum = pages[i];
            cnt++;
        }
    }
    return cnt <= m;
}

int Solution::books(vector<int> &pages, int m) {
    if (m > pages.size()) return -1;

    int lo = 0, hi = 0;
    for (int x : pages) {
        lo = max(lo, x);
        hi += x;
    }

    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if (check(mid, m, pages)) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }
    return lo;
}









bool check(int mid, int m, vector<int>& pages) {
    int cnt = 1, sum = 0;
    for (int i = 0; i < pages.size(); i++) {
        sum += pages[i];
        if (sum > mid) {
            sum = pages[i];
            cnt++;
        }
    }
    return cnt <= m;
}
int Solution::books(vector<int> &pages, int m) {
    if (m > pages.size()) return -1;

    int lo = 0, hi = 0;
    for (int x : pages) {
        lo = max(lo, x);
        hi += x;
    }

    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (check(mid, m, pages)) {
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }
    return lo;
}