// https://www.geeksforgeeks.org/maximum-value-pair-array/
// https://www.naukri.com/code360/library/maximum-and-value-of-a-pair-in-an-array

class Solution{
    static int maxAND (int arr[], int n){
        int res = 0;
        
        for (int bit = 31; bit >= 0; bit--) {
            // find the count of element having set msb
            int count = 0, cVal = (res | (1<<bit));
            
            /*
              Counting the number of elements 
              with the ith bit and the already 
              included bits set to 1.
            */
            for (int i = 0; i < n; i++){
                if ((cVal & arr[i]) == cVal){
                    count++;
                }
            }
            
            /*
              If the count >= 2 we will 
              include the current bit to our result.
            */
            if ( count >= 2 ) {   
                res |= (1 << bit);    
            }
        }
      
        return res;
    }
};