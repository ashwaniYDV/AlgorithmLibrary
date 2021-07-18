// https://leetcode.com/problems/sliding-window-median/

/*
You are given an integer array nums and an integer k. 
There is a sliding window of size k which is moving from left to right. 
Return the median array for each window in the original array. 
Answers within 10^-5 of the actual value will be accepted.

Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
Output: [1.00000,-1.00000,-1.00000,3.00000,5.00000,6.00000]
Explanation: 
Window position                Median
---------------                -----
[1  3  -1] -3  5  3  6  7        1
 1 [3  -1  -3] 5  3  6  7       -1
 1  3 [-1  -3  5] 3  6  7       -1
 1  3  -1 [-3  5  3] 6  7        3
 1  3  -1  -3 [5  3  6] 7        5
 1  3  -1  -3  5 [3  6  7]       6
*/


#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;
typedef tree<long long, null_type, less_equal<long long>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

class Solution {
public:
    #define ld long double
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        ordered_set st;
        vector<double> res;
        
        for(int i = 0; i < k; i++) st.insert(nums[i]);

        if(k % 2) {
            res.push_back(*st.find_by_order(k / 2));
        } else {
            ld x = *st.find_by_order(k / 2) + *st.find_by_order(k/2 - 1);
            res.push_back(x / 2.0); 
        }

        for(int i = k; i < n; i++) {
            st.erase(st.find_by_order(st.order_of_key(nums[i - k])));
            st.insert(nums[i]);
            if(k % 2) {
                res.push_back(*st.find_by_order(k / 2));
            } else {
                ld x = *st.find_by_order(k / 2) + *st.find_by_order(k/2 - 1);
                res.push_back(x / 2.0); 
            }
        }
        
        return res;
    }
};






// Method 2: (Using multiset)
class Solution {
public:
    using ld = long double;
    multiset<int, greater<int>> left;
    multiset<int> right;
    vector<double> res;
    
    void addEle(int x) {
        if(left.empty() || (*left.begin()) > x) {
            left.insert(x);
        } else {
            right.insert(x);
        }
        reshuffle();
    }

    void removeEle(int x) {
        if(left.find(x) != left.end()) {
            left.erase(left.find(x));
        } else {
            right.erase(right.find(x));
        }
        reshuffle();
    }
    
    void reshuffle() {
        if(left.size() > right.size() + 1) {
            right.insert(*left.begin());
            left.erase(left.begin());
        }
        if(right.size() > left.size() + 1) {
            left.insert(*right.begin());
            right.erase(right.begin());
        }
    }
    
    void setAnswer() {
        if(left.size() == right.size()) {
            ld median = ((ld)(*left.begin()) + (ld)(*right.begin())) / 2.0;
            res.push_back(median);
        } else if(left.size() < right.size()) {
            res.push_back(*right.begin());
        } else {
            res.push_back(*left.begin());
        }
    }
    
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        res.clear();
        left.clear(), right.clear();
        
        for(int i = 0; i < k; i++) {
            addEle(nums[i]);
        }
        setAnswer();
        
        for(int i = k; i < nums.size(); i++) {
            removeEle(nums[i - k]);            
            addEle(nums[i]);
            setAnswer();
        }
        
        return res;
    }
};