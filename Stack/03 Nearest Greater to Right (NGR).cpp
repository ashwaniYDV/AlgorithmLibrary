// https://practice.geeksforgeeks.org/problems/next-larger-element-1587115620/1

/*
Given an array A[] of size N having distinct elements, the task is to find the next greater element 
for each element of the array in order of their appearance in the array.
Next greater element of an element in the array is the nearest element on the right which is greater than the current element.
If there does not exist next greater of current element, then next greater element for current element is -1. 
For example, next greater of the last element is always -1.

Input: 
N = 4, arr[] = [1 3 2 4]
Output:
3 4 4 -1

Input: 
N = 5, arr[] = [6 8 0 1 3]
Output:
8 -1 1 3 -1
*/

class Solution {
public:
    vector < long long > nextLargerElement(vector < long long > A, int n) {
        vector < long long > res(n);
        stack < long long > st;
        for (int i = n - 1; i >= 0; i--) {
            while (st.size() && st.top() <= A[i]) {
                st.pop();
            }
            if (st.size()) {
                res[i] = st.top();
            } else {
                res[i] = -1;
            }

            st.push(A[i]);
        }
        return res;
    }
};

















// https://www.interviewbit.com/problems/nextgreater/

/*
Given an array, find the next greater element G[i] for every element A[i] in the array.  
The Next greater Element for an element A[i] is the first greater element on the right side of A[i] in array. 
*/

vector<int> Solution::nextGreater(vector<int> &A) {
    int n = A.size();
    vector<int> res(n);
    stack<int> st;
    for(int i = n-1; i >= 0; i--) {
        while(st.size() && st.top() <= A[i]) {
            st.pop();
        }
        if(st.size()) {
            res[i] = st.top();
        } else {
            res[i] = -1;
        }
        
        st.push(A[i]);
    }
    return res;
}
