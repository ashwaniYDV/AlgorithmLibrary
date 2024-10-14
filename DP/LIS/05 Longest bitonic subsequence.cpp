// https://takeuforward.org/data-structure/longest-bitonic-subsequence-dp-46/
/*
Given an array, find the longest bitonic subsequence.
A bitonic subsequence is a subsequence in which elements can be any of these 3:
a) First, increase till a point and then decrease.
b) Goes on increasing (Longest increasing subsequence)
c) Goes on decreasing (Longest decreasing subsequence)
*/


/*
dp_lis[i] stores the value of longest increasing subsequence ending with nums[i]
dp_lds[i] stores the value of longest decreasing subsequence starting with nums[i]
NOTE: for dp_dls in this question, dp[i] contains lds value when lds array starts with nums[i], i.e. nums[i] is included and it's the starting point (not the ending point)
as in dp_lis which is calculated as usual.

Examples:

(1)
           #
       #       #
   #                #
#                            #



(2)
                        #
              #     
      #            
#                    

        
        
  (3)    
           #
                       #
                                 #
                                            #


*/


void solve() {
    cin >> n;
    vector<int> nums(n);
    f(i, n) cin >> nums[i];
    
    vector<int> dp_lis(n+1, 1);
    vector<int> dp_lds(n+1, 1);
    
    // longest increasing
    for(int i = 1; i < n; ++i) {
        for(int j = 0; j < i; ++j) {
            if(nums[i] > nums[j]){
                dp_lis[i] = max(dp_lis[i], dp_lis[j] + 1);
            }
        }
    }

    // longest decreasing
    for(int i = n-2; i >= 0; i--) {
        for(int j = n-1; j > i; j--) {
            if(nums[i] > nums[j]){
                dp_lds[i] = max(dp_lds[i], dp_lds[j] + 1);
            }
        }
    }
    
    int longest_bitonic = 0;
    for(int i = 0; i < n; i++) {
        longest_bitonic = max(longest_bitonic, dp_lis[i] + dp_lds[i] - 1);
    }
    cout << longest_bitonic << endl;
}

/*
Input:
6
80 60 30 40 20 10

Output:
5
*/
