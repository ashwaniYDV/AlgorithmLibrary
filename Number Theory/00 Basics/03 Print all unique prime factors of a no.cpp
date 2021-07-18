// https://youtu.be/LT7XhVdeRyg?si=eDV-BPCR4kxz8r06

/*
Input:
100

Output:
2, 5
*/



// O(sqrt(n))
vector<int> getPrimeFactors(int n) {
    vector<int> primeFactors; 
    
    // Loop from 2 up to n
    for(int i = 2; i * i <= n; i++){
        // Check if n is divisible by i
        if(n % i == 0){
            // If divisible, add i to the primeFactors vector
            primeFactors.push_back(i);
        }
        // Continue dividing n by i until it's no longer divisible
        while(n % i == 0){
            n = n / i;
        }
    }

    // handle case when n itself is prime
    if(n != 1) primeFactors.push_back(n);
    return primeFactors; 
}


// O(n)
vector<int> getPrimeFactors(int n) {
    vector<int> primeFactors; 
    
    // Loop from 2 up to n
    for(int i = 2; i <= n; i++){
        // Check if n is divisible by i
        if(n % i == 0){
            // If divisible, add i to the primeFactors vector
            primeFactors.push_back(i);
        }
        // Continue dividing n by i until it's no longer divisible
        while(n % i == 0){
            n = n / i;
        }
    }
    return primeFactors; 
}
