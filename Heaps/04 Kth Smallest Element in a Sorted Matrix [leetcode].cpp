// https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/

/*
Problem:
Given an n x n matrix where each of the rows and columns are sorted in ascending order, return the kth smallest element in the matrix.
Note that it is the kth smallest element in the sorted order, not the kth distinct element.
*/



/*
Using Heap :- Here, we know that the row and column is already sorted. 
Therefore, instead of traversing in the entire matrix we can take advantage of that. 
We can take a Min Heap and push the First row(value, indexes) into Min heap. 
You can push first column also, and write your answer according to that.

Now,follow these steps:-

Pop the element from min heap and check whether it is the Kth smallest element. If it is return the value.
Else push the next row value (Note:- column is going to remain same).
The reason behind this logic is, 
when we remove the smallest element from Min Heap (i.e our 1st smallest element, which is always present in the 1st row and 1st column), 
then the 2nd smallest element may lie in that 2nd row and 1st column or it may be present in the First Row and column greater than 1.

Time Complexity:- O(NlogN)
Space Complexity:- O(N)
*/

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<vector<int>, vector<vector<int>> , greater<vector<int>>> pq;
        int n = matrix.size(), m = matrix[0].size();
        for(int j = 0; j < m; j++)
            pq.push({matrix[0][j], 0, j});
        
        int res;
        while(k--) {
            int val = pq.top()[0];
            int i = pq.top()[1];
            int j = pq.top()[2];
            pq.pop();
            res = val;
            
            if(i+1 < n) {
                pq.push({matrix[i + 1][j], i + 1, j});
            }
        }
        return res;
    }
};
