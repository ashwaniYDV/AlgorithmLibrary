// https://youtu.be/LT7XhVdeRyg?si=eDV-BPCR4kxz8r06

/*
Input:
100

Output:
2, 2, 5, 5
*/


// Method 1.1
// O(sqrt(n))
#include <bits/stdc++.h>
using namespace std;

vector<int> getPrimeFactors(int n) {
    vector<int> primeFactors; 
    
    // Loop from 2 up to n
    for(int i = 2; i * i <= n; i++){
        // Check if n is divisible by i
        while(n % i == 0) {
            // If divisible, add i to the primeFactors vector
            primeFactors.push_back(i);
            n = n / i;
        }
    }

    // handle case when n itself is prime
    if(n != 1) primeFactors.push_back(n);
    return primeFactors; 
}

int main() {
    vector<int> v = getPrimeFactors(100);
    for(int i: v) cout << i << " ";
}







// Method 1.2
// O(sqrt(n))
#include <bits/stdc++.h>
using namespace std;

vector<int> getPrimeFactors(int n) {
    vector<int> primeFactors; 

    while(n % 2 == 0) {
        primeFactors.push_back(2);
        n = n / 2;
    }
    
    // Loop from 2 up to n
    for(int i = 3; i * i <= n; i += 2) {
        // Check if n is divisible by i
        while(n % i == 0) {
            // If divisible, add i to the primeFactors vector
            primeFactors.push_back(i);
            n = n / i;
        }
    }

    // handle case when n itself is prime
    if(n != 1) primeFactors.push_back(n);
    return primeFactors; 
}

int main() {
    vector<int> v = getPrimeFactors(100);
    for(int i: v) cout << i << " ";
}





// Method 2
// O(n)
#include <bits/stdc++.h>
using namespace std;

vector<int> getPrimeFactors(int n) {
    vector<int> primeFactors; 
    
    // Loop from 2 up to n
    for(int i = 2; i <= n; i++){
        // Check if n is divisible by i
        while(n % i == 0) {
            // If divisible, add i to the primeFactors vector
            primeFactors.push_back(i);
            n = n / i;
        }
    }

    return primeFactors; 
}

int main() {
    vector<int> v = getPrimeFactors(100);
    for(int i: v) cout << i << " ";
}
