// https://www.geeksforgeeks.org/minimize-cash-flow-among-given-set-friends-borrowed-money/
// https://youtu.be/Vy5PLlpDoks


/*
Given a number of friends who have to give or take some amount of money from one another. 
Design an algorithm by which the total cash flow among all the friends is minimized. 
*/

/*
The following is detailed algorithm.
Do following for every person Pi where i is from 0 to n-1. 

1) Compute the net amount (balance) for every person. The net amount for person ‘i’ can be computed by subtracting sum of all debts from sum of all credits.
2) Find the two persons that are maximum creditor and maximum debtor. 
   Let the maximum amount to be credited maximum creditor be maxCredit and maximum amount to be debited from maximum debtor be maxDebit. 
   Let the maximum debtor be Pd and maximum creditor be Pc.
3) Find the minimum of maxDebit and maxCredit. Let minimum of two be x. Debit ‘x’ from Pd and credit this amount to Pc
4) If x is equal to maxCredit, then remove Pc from set of persons and recur for remaining (n-1) persons.
5) If x is equal to maxDebit, then remove Pd from set of persons and recur for remaining (n-1) persons.
*/



// Given the list of M transacations b/w N people, find out the minimum amount of cash flow required to settle it up!
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, u, v, w, poorValue, poorGuy, richValue, richGuy;
    cin >> n >> m;

    vector<int> balance(n+1, 0);

    for(int i = 0; i < m; i++) {
        cin >> u >> v >> w;
        //u has to pay v an amount w
        balance[u] -= w;
        balance[v] += w;
    }
    
    multiset<tuple<int, int>> st;
    for(int i = 1; i <= n; i++) {
        if(balance[i] != 0) st.insert(make_tuple(balance[i], i));
    }
       
    int transactions = 0;
    while(!st.empty()) {
        tie(poorValue, poorGuy) = *st.begin(); st.erase(st.begin());
        tie(richValue, richGuy) = *st.rbegin(); st.erase(prev(st.end()));
        // value of poor is negative
        int amount = min(-poorValue , richValue);
        
        transactions++;
        // poor pays amount "amount" to rich
        cout << poorGuy << " pays-> " << richGuy << " (amoutn = " << amount << ")" << endl;
        poorValue += amount;
        richValue -= amount;
        
        if (poorValue) st.insert(make_tuple(poorValue, poorGuy));
        if (richValue) st.insert(make_tuple(richValue, richGuy));
    }
    
    cout << "No of transactions: " << transactions << endl;
}










/*
Source GFG discuss
-------------------
Consider:
Input:
5 6
1 4 4
1 5 1
2 4 5
2 5 2
3 4 3
3 5 8

Our solution output:
3 pays-> 4 (amoutn = 11)
2 pays-> 5 (amoutn = 7)
1 pays-> 5 (amoutn = 4)
1 pays-> 4 (amoutn = 1)
No of transactions: 4


Minimum transcation output will look like this
3 pays-> 4 (amoutn = 11)
2 pays-> 5 (amoutn = 7)
1 pays-> 4 (amoutn = 5)
Minimum no of transactions: 3

Note: 
Cash Flow in greedy: 11 + 7 + 4 + 1 = 23
Optimal Solution: 11 + 7 + 5 = 23

The problem is looking to minimize cash flow and not necessarily minimize number of transactions.
The greedy solution is trying to minimize the cash flow 
while it may or may not find the most optimal way (min number of transactions) reach the optimal cash flow solution.
This problem is an overall cash flow minimization problem 
while OP's answer is looking for overall transaction minimization problem which is an NP-Complete problem.
*/
