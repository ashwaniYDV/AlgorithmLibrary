// https://practice.geeksforgeeks.org/problems/search-in-a-matrix17201720/1

class Solution{
public:	
	int matSearch (vector <vector <int>> &mat, int n, int m, int x) {
	    if(x < mat[0][0] || x > mat[n-1][m-1]) {
            return 0;
	    }
    
        int i = 0, j = m-1;
    
        while(i < n && j >= 0) {
            if(mat[i][j] == x) {
                return 1;
            } else if(x > mat[i][j]) {
                i++;
            } else {
                j--;
            }
        }
        
        return 0;
	}
};
