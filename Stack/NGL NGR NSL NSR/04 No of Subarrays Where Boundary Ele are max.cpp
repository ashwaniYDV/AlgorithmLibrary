// https://leetcode.com/problems/find-the-number-of-subarrays-where-boundary-elements-are-maximum/

/*
You are given an array of positive integers nums.
Return the number of subarrays of nums, 
where the first and last elements of subarray are equal to the largest element in the subarray. 

Input: nums = [1,4,3,3,2]
Output: 6
Explanation:
There are 6 subarrays which have the first and the last elements equal to the largest element of the subarray:
subarray [1], with its largest element 1. The first element is 1 and the last element is also 1.
subarray [4], with its largest element 4. The first element is 4 and the last element is also 4.
subarray [3], with its largest element 3. The first element is 3 and the last element is also 3.
subarray [3], with its largest element 3. The first element is 3 and the last element is also 3.
subarray [2], with its largest element 2. The first element is 2 and the last element is also 2.
subarray [3,3], with its largest element 3. The first element is 3 and the last element is also 3.

Input: nums = [3,3,3]
Output: 6
Explanation:
There are 6 subarrays which have the first and the last elements equal to the largest element of the subarray:
subarray [3], with its largest element 3. The first element is 3 and the last element is also 3.
subarray [3], with its largest element 3. The first element is 3 and the last element is also 3.
subarray [3], with its largest element 3. The first element is 3 and the last element is also 3.
subarray [3,3], with its largest element 3. The first element is 3 and the last element is also 3.
subarray [3,3], with its largest element 3. The first element is 3 and the last element is also 3.
subarray [3,3,3], with its largest element 3. The first element is 3 and the last element is also 3.
*/




/*
Intuition
=========

[1, 2, 5, 3, 4, 5, 2, 1, 5, 1]
       =        =        =

Suppose num[l, , , , r] is a valid subarray, 
then from j = (l+1, to r-1), nums[j] should be less than nums[l] (= nums[r]) 


Approach
=========
* For each element nums[i], we can count the number of valid subarrays ending with it.
* For each index i, find the nearest index j on its left (j < i) such that nums[j] > nums[i].
* i.e. ngl (nearest greater to left) idx of nums[i] = j. 
* This can be done via a monotonic stack.
* For each index i, number of valid subarrays ending with nums[i] = number of indices k in the window [j + 1, i] such that nums[k] == nums[i]. 
* This can be done efficiently by storing all indices of nums[i] in a map and then couning them in a range using binary search.
*/


// This will give TLE
class Solution {
public:
    long long numberOfSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int> ngl(n);
        stack<int> st;
        map<int, vector<int>> mp;

        for(int i = 0; i < n; i++) {
            while(!st.empty() && nums[st.top()] <= nums[i]) {
                st.pop();
            }
            if(st.empty()) {
                ngl[i] = 0;
            } else {
                ngl[i] = st.top() + 1;
            }
            st.push(i);
        }

        long long res = 0;
        for(int i = 0; i < n; i++) {
            // counting how many times num[i] appears in index range l to r
            for(int j = ngl[i]; j <= i; j++) {
                res += (nums[j] == nums[i]);
            }
        }
        
        return res;
    }
};




class Solution {
public:
    // counting how many times num appears in index range l to r
    int cnt(int num, int l, int r, map<int, vector<int>>& mp) {
        return upper_bound(mp[num].begin(), mp[num].end(), r) - lower_bound(mp[num].begin(), mp[num].end(), l);
    }

    long long numberOfSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int> ngl(n);
        stack<int> st;
        map<int, vector<int>> mp;

        for(int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
            while(!st.empty() && nums[st.top()] <= nums[i]) {
                st.pop();
            }
            if(st.empty()) {
                ngl[i] = 0;
            } else {
                ngl[i] = st.top() + 1;
            }
            st.push(i);
        }

        long long res = 0;
        for(int i = 0; i < n; i++) {
            res += cnt(nums[i], ngl[i], i, mp);
        }
        
        return res;
    }
};



class Solution {
public:
    int cnt(int num, int l, int r, map<int, vector<int>>& mp) {
        return upper_bound(mp[num].begin(), mp[num].end(), r) - lower_bound(mp[num].begin(), mp[num].end(), l);
    }

    long long numberOfSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int> ngl(n);
        stack<int> st;
        map<int, vector<int>> mp;

        for(int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
            while(!st.empty() && nums[st.top()] <= nums[i]) {
                st.pop();
            }
            if(st.empty()) {
                ngl[i] = -1;
            } else {
                ngl[i] = st.top();
            }
            st.push(i);
        }

        long long res = 0;
        for(int i = 0; i < n; i++) {
            res += cnt(nums[i], ngl[i] + 1, i, mp);
        }
        

        return res;
    }
};