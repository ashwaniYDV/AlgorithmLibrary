// https://www.geeksforgeeks.org/maximum-xor-of-two-numbers-in-an-array/

#include <bits/stdc++.h> 
using namespace std; 
  

int max_xor(int arr[], int n) 
{ 
    int maxx = 0, mask = 0; 
  
    set<int> se; 
  
    for (int i = 30; i >= 0; i--) { 
  
        // set the i'th bit in mask 
        // like 100000, 110000, 111000.. 
        mask |= (1 << i); 
  
        for (int i = 0; i < n; ++i) { 
  
            // Just keep the prefix till 
            // i'th bit neglecting all 
            // the bit's after i'th bit 
            se.insert(arr[i] & mask); 
        } 
  
        int newMaxx = maxx | (1 << i); 
  
        for (int prefix : se) { 
  
            // find two pair in set 
            // such that a^b = newMaxx 
            // which is the highest 
            // possible bit can be obtained 
            if (se.count(newMaxx ^ prefix)) { 
                maxx = newMaxx; 
                break; 
            } 
        } 
  
        // clear the set for next iteration 
        se.clear(); 
    } 
  
    return maxx; 
} 
  
// Driver Code 
int main() 
{ 
  
    int arr[] = { 25, 10, 2, 8, 5, 3 }; 
    int n = sizeof(arr) / sizeof(arr[0]); 
  
    cout << max_xor(arr, n) << endl; 
  
    return 0; 
} 
