// https://www.geeksforgeeks.org/josephus-problem-set-1-a-on-solution/
// https://practice.geeksforgeeks.org/problems/josephus-problem/1


/*
In computer science and mathematics, the Josephus Problem (or Josephus permutation) is a theoretical problem. 
Following is the problem statement:

There are n people standing in a circle waiting to be executed. 
The counting out begins at some point in the circle and proceeds around the circle in a fixed direction. 
In each step, a certain number of people are skipped and the next person is executed. 
The elimination proceeds around the circle (which is becoming smaller and smaller as the executed people are removed), 
until only the last person remains, who is given freedom. 

Given the total number of person n and a number k which indicates that k-1 persons are skipped and the kth person is killed in a circle. 
The task is to choose the place in the initial circle so that you are the last one remaining and so survive.

For example, if n = 5 and k = 2, then the safe position is 3. 
Firstly, the person at position 2 is killed, then the person at position 4 is killed, then the person at position 1 is killed. 
Finally, the person at position 5 is killed. So the person at position 3 survives. 

If n = 7 and k = 3, then the safe position is 4. 
The persons at positions 3, 6, 2, 7, 5, and 1 are killed in order, and the person at position 4 survives.
*/






class Solution {
public:
    int res;
    
    void fun(int i, vector<int> person, int k) {
        // Base case , when only one person is left
        if (person.size() == 1) {
            res = person[0];
            return;
        }
     
        // find the index of first person which will die
        i = ((i + k) % person.size());
     
        // remove the first person which is going to be killed
        person.erase(person.begin() + i);
     
        // recursive call for n-1 persons
        fun(i, person, k);
    }
  
    int josephus(int n, int k) {
        // (k-1)th person will be killed
        k--;
        
        vector<int> person;
        for (int i = 1; i <= n; i++) {
            person.push_back(i);
        }
        
        fun(0, person, k);
        return res;
    }
};






/*
The problem has the following recursive structure.  

josephus(n, k) = (josephus(n - 1, k) + k-1) % n + 1
josephus(1, k) = 1
*/


class Solution {
public:
    int josephus(int n, int k) {
        if (n == 1) return 1;
      
        /* The position returned by josephus(n - 1, k) is adjusted 
        because the recursive call josephus(n - 1, k) 
        considers the original position k % n + 1 as position 1 */
        return (josephus(n - 1, k) + k - 1) % n + 1;
    }
};
