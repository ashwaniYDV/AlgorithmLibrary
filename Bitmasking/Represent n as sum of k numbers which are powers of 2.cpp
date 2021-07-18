// https://www.geeksforgeeks.org/find-k-numbers-which-are-powers-of-2-and-have-sum-n/
/*
Find k numbers which are powers of 2 and have sum N | Set 1
*/

#include <bits/stdc++.h> 
using namespace std; 
  
// function to print numbers 
void printNum(int n, int k) 
{ 
    // Count the number of set bits 
    int x = __builtin_popcount(n); 
  
    // Not-possible condition 
    if (x > k || k > n) { 
        cout << "-1"; 
        return; 
    } 
  
    // Stores the number 
    priority_queue<int> pq; 
  
    // Get the set bits 
    int two = 1; 
    while (n) { 
        if (n & 1) { 
            pq.push(two); 
        } 
  
        two = two * 2; 
        n = n >> 1; 
    } 
  
    // Iterate till we get K elements 
    while (pq.size() < k) { 
  
        // Get the topmost element 
        int el = pq.top(); 
        pq.pop(); 
  
        // Push the elements/2 into  
        // priority queue 
        pq.push(el / 2); 
        pq.push(el / 2); 
    } 
  
    // Print all elements 
    int ind = 0; 
    while (ind < k) { 
        cout << pq.top() << " "; 
        pq.pop(); 
        ind++; 
    } 
} 
  
// Driver Code 
int main() 
{ 
    int n = 12, k = 6; 
    printNum(n, k); 
    return 0; 
}












// https://www.geeksforgeeks.org/represent-n-as-the-sum-of-exactly-k-powers-of-two-set-2/
/*
Represent n as the sum of exactly k powers of two | Set 2
*/

// C++ implementation of the above approach 
#include <iostream> 
using namespace std; 
  
// Function to print k numbers which are powers of two 
// and whose sum is equal to n 
void FindAllElements(int n, int k) 
{ 
    // Initialising the sum with k 
    int sum = k; 
  
    // Initialising an array A with k elements 
    // and filling all elements with 1 
    int A[k]; 
    fill(A, A + k, 1); 
  
    for (int i = k - 1; i >= 0; --i) { 
  
        // Iterating A[] from k-1 to 0 
        while (sum + A[i] <= n) { 
  
            // Update sum and A[i] 
            // till sum + A[i] is less than equal to n 
            sum += A[i]; 
            A[i] *= 2; 
        } 
    } 
  
    // Impossible to find the combination 
    if (sum != n) { 
        cout << "Impossible"; 
    } 
  
    // Possible solution is stored in A[] 
    else { 
        for (int i = 0; i < k; ++i) 
            cout << A[i] << ' '; 
    } 
} 
  
// Driver code 
int main() 
{ 
    int n = 12; 
    int k = 6; 
  
    FindAllElements(n, k); 
  
    return 0; 
} 
