// https://leetcode.com/problems/product-of-the-last-k-numbers/description/

/*
Design an algorithm that accepts a stream of integers and retrieves the product of the last k integers of the stream.
Implement the ProductOfNumbers class:
* ProductOfNumbers() Initializes the object with an empty stream.
* void add(int num) Appends the integer num to the stream.
* int getProduct(int k) Returns the product of the last k numbers in the current list. You can assume that always the current list has at least k numbers.
The test cases are generated so that, at any time, the product of any contiguous sequence of numbers will fit into a single 32-bit integer without overflowing.

Input
["ProductOfNumbers","add","add","add","add","add","getProduct","getProduct","getProduct","add","getProduct"]
[[],[3],[0],[2],[5],[4],[2],[3],[4],[8],[2]]
Output
[null,null,null,null,null,null,20,40,0,null,32]
Explanation
ProductOfNumbers productOfNumbers = new ProductOfNumbers();
productOfNumbers.add(3);        // [3]
productOfNumbers.add(0);        // [3,0]
productOfNumbers.add(2);        // [3,0,2]
productOfNumbers.add(5);        // [3,0,2,5]
productOfNumbers.add(4);        // [3,0,2,5,4]
productOfNumbers.getProduct(2); // return 20. The product of the last 2 numbers is 5 * 4 = 20
productOfNumbers.getProduct(3); // return 40. The product of the last 3 numbers is 2 * 5 * 4 = 40
productOfNumbers.getProduct(4); // return 0. The product of the last 4 numbers is 0 * 2 * 5 * 4 = 0
productOfNumbers.add(8);        // [3,0,2,5,4,8]
productOfNumbers.getProduct(2); // return 32. The product of the last 2 numbers is 4 * 8 = 32 
 

Constraints:
0 <= num <= 100
1 <= k <= 4 * 10^4
At most 4 * 10^4 calls will be made to add and getProduct.
The product of the stream at any point in time will fit in a 32-bit integer.
*/


// Method 1
/*
* Keep all prefix products of numbers in an array, 
  then calculate the product of last K elements in O(1) complexity.
* When a zero number is added, clean the array of prefix products.
*/
class ProductOfNumbers {
public:
    vector<int> prefixProduct;

    ProductOfNumbers() {
        prefixProduct.clear();
    }

    void add(int num) {
        if (num == 0) {
            // If num is 0, reset the cumulative products since multiplication with 0 invalidates previous products
            prefixProduct = {};
        } else {
            // Append the cumulative product of the current number with the last product
            prefixProduct.push_back(num);
            
            int n = prefixProduct.size();
            if(n > 1) {
                prefixProduct[n - 1] *= prefixProduct[n - 2];
            }
        }
    }

    int getProduct(int k) {
        int n = prefixProduct.size();
        
        // Check if the requested product length exceeds the size of the valid product list
        if (k > n) return 0;

        if (k == n) return prefixProduct[n - 1];
        return prefixProduct[n - 1] / prefixProduct[n - 1 - k];
    }
};




// Method 2
class ProductOfNumbers {
public:
    vector<long long> prefProd, prefZeroSum;

    ProductOfNumbers() {
        prefProd.clear();
        prefZeroSum.clear();
    }
    
    void add(int num) {
        if (num == 0) {
                prefProd.push_back(1);
                prefZeroSum.push_back(1);
        } else {
            prefProd.push_back(num);
            prefZeroSum.push_back(0);
        }

        int n = prefProd.size();
        if(n > 1) {
            // this if else is added to prevent overflow of multiplication
            if (num == 0) {
                prefProd[n - 1] = 1;
            } else {
                prefProd[n - 1] *= prefProd[n - 2];
            }
            prefZeroSum[n - 1] += prefZeroSum[n - 2];
        }
    }
    
    int getProduct(int k) {
        int n = prefProd.size();

        if(k == n) {
            int noOfZeros = prefZeroSum[n - 1];
            if (noOfZeros > 0) return 0;
            return prefProd[n - 1];
        }

        int noOfZeros = (prefZeroSum[n - 1]) - ((n - 1 - k >= 0) ? prefZeroSum[n - 1 - k] : 0);
        if (noOfZeros > 0) return 0;
        return prefProd[n - 1] / prefProd[n - 1 - k];
    }
};