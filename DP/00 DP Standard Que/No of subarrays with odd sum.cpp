/*
odd[i] = number of subarray ending at arr[i] that has odd sum.
even[i] = number of subarray ending at arr[i] that has even sum.
if arr[i] is odd, odd[i] = even[i-1] + 1 and even[i] = odd[i-1]
if arr[i] is even, odd[i] = odd[i-1] and even[i] = even[i-1] + 1
*/

class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int mod = 1e9+7;
        int n = arr.size();
        if(n == 0) return 0;

        vector<int> dpOdd(n);
        vector<int> dpEven(n);

        if(arr[0] % 2 == 0) {
            dpEven[0] = 1;
            dpOdd[0] = 0;
        } else {
            dpOdd[0] = 1;
            dpEven[0] = 0;
        }

        int res = dpOdd[0];

        for(int i = 1; i < n; i++) {
            if(arr[i] % 2 == 0) {
                dpEven[i] = dpEven[i-1] + 1;
                dpOdd[i] = dpOdd[i-1];
            } else {
                dpOdd[i] = dpEven[i-1] + 1;
                dpEven[i] = dpOdd[i-1];
            }
            dpOdd[i] = dpOdd[i] % mod;
            dpEven[i] = dpEven[i] % mod;
            res = (res + dpOdd[i]) % mod;
        }
        
        return res % mod;
    }
};
