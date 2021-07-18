// https://www.scaler.com/problems/maximum-xor-subarray/

/*
Given an array A of integers of size N. 
Find the subarray AL, AL+1, AL+2, ... AR with 1<=L<=R<=N which has maximum XOR value.
NOTE: If there are multiple subarrays with same maximum value, return the subarray with minimum length. 
If length is same, return the subarray with minimum starting index.
*/


/*
Build a prefXor array in which the ith element represents the xor of all elements from 0 to i. 
To find the xor of any subarray[l..r], we can just take the xor of prefXor[r] and prefXor[l-1].

To find the maximum xor subarray ending at the index i, insert the bit representation(starting from most significant bit) 
of all the elements of prefXor array upto i-1 into the trie data structure.

We have two possible cases at ith index.
a) The prefix itself has maximum xor.
b) We need to remove some prefix (ending at index from 0 to i-1).
Try to have most significant bit to be set bit ie 1. 
As we have maintained the trie data structure of bit representation of i-1 elements of prefXor array, 
we can find the maximum xor in O(logm) where m is the maximum number present in the given array.
We can find the maximum subarray ending at every index and return the subarray which has maximum XOR value.
*/


struct TrieNode {
    TrieNode * children[2];
    int cnt;
};

TrieNode * newNode() {
    TrieNode * temp = new TrieNode;
    temp -> cnt = 0;
    temp -> children[0] = NULL;
    temp -> children[1] = NULL;
    return temp;
}

bool check(int N, int i) {
    return (bool)(N & (1 << i));
}

void insert(TrieNode * root, int x) {
    TrieNode * itr = root;
    // padding upto 32 bits 
    for (int i = 31; i >= 0; i--) {
        int f = check(x, i);
        if (!itr -> children[f])
            itr -> children[f] = newNode();
        itr = itr -> children[f];
    }
    itr -> cnt += 1;
}

int findXor(TrieNode * root, int x) {
    TrieNode * itr = root;
    // Do XOR from root to a leaf path 
    int ans = 0;
    for (int i = 31; i >= 0; i--) {
        // Find i-th bit in x 
        int f = check(x, i);
        // Move to the child whose XOR with f 
        // is 1. 
        if ((itr -> children[f ^ 1])) {
            ans = ans + (1 << i); // update answer 
            itr = itr -> children[f ^ 1];
        } else
            itr = itr -> children[f];
    }
    return ans;
}

vector < int > Solution::solve(vector < int > & A) {
    int n = A.size();
    for (int i = 1; i < n; i++) {
        A[i] = A[i] ^ A[i - 1];
    }
    vector < int > ans(2, 1);
    int maxx = A[0];
    TrieNode * root = newNode();
    insert(root, A[0]);
    unordered_map < int, int > mp; // to store the indices of the XOR value
    mp[A[0]] = 0;
    for (int i = 1; i < A.size(); i++) {
        // Case 1 check for subarray(0, i)
        mp[A[i]] = i;
        if (A[i] > maxx) {
            maxx = A[i];
            ans[0] = 1;
            ans[1] = i + 1;
        } else if (A[i] == maxx) {
            if (ans[0] != ans[1]) {
                ans[0] = i + 1;
                ans[1] = i + 1;
            }
        }
        int curMaxx = findXor(root, A[i]);
        int res = curMaxx ^ A[i];
        int j = mp[res];
        j += 1;
        if (curMaxx > maxx) {
            maxx = curMaxx;
            ans[0] = j + 1;
            ans[1] = i + 1;
        } else if (curMaxx == maxx) //  check for minimum length if current maximum  = maxx.           
        {
            int curL = i - j + 1, ansL = ans[1] - ans[0] + 1;
            if (curL < ansL) {
                ans[0] = j + 1;
                ans[1] = i + 1;
            }
        }
        insert(root, A[i]); // insert the xor of the prefix(0, i) into the trie.                  
    }
    return ans;
}
