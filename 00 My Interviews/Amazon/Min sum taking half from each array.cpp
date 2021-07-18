// https://stackoverflow.com/questions/47830379/minimum-sum-of-two-arrays-choosing-half-of-the-elements-in-each

/*
You have two arrays a1 and a2 of integers with same length n (n is even). 
Find the minimum total sum of elements in a1 and a2 by selecting one element for each index 
and half of the selected elements should reside in a1 and the rest is in a2.

Example:

 a1 = [36, 72];  
 a2 = [35, 61];
 
The result should be 97 since we should choose 36 from a1 and 61 from a2. 
One solution would be choosing all possible n/2 elements in a1 and a2 and computing their results. Can a more efficient solution be found?
*/

/*
Solution:

Let's represent arrays a1 and a2
    a1 = [36, 72];  
    a2 = [35, 61];
    
In a different way: we combine i-th indexes and compute a penalty = a1[i] - a2[i]:
Here penalty is a price we have to pay when we choose a1 value instead of a2. 

Let's sort by penalty

Now let's choose n/2 items with the lowest penalties and take a1 items; choose n/2 items with highest penalties and take a2 items:
*/




/*
Amazon has hired n new employees (n is even). You have to send half of these employees to Bangalore and other half to Hyderabad. 
The cost for each employee for each city is given in a form of array. Find the minimum cost.

Example 1:

         BLR       HYD
         -------------
Emp1     10        30
Emp2     40        20 
Emp3     30        60
Emp4     90        70


Example 2:

         BLR       HYD
         -------------
Emp1     100       300
Emp2     700       1000 

Ans = 1000
*/




bool compare(vector<int>& a, vector<int>& b) {
    return (a[0] - a[1]) < (b[0] - b[1]);
}

void solve() {
    cin >> n;
    vector<int> BLR(n), HYD(n);

    for(int i = 0; i < n; i++) {
        cin >> BLR[i] >> HYD[i];
    }

    vector<vector<int>> cost(n, vector<int>(2));
    for(int i = 0; i < n; i++) {
        cost[i][0] = BLR[i]; 
        cost[i][1] = HYD[i];
    }
    
    sort(cost.begin(), cost.end(), compare);

    int sum = 0;
    for(int i = 0; i < n/2; i++) {
        sum += cost[i][0];
    }
    for(int i = n/2; i < n; i++) {
        sum += cost[i][1];
    }
    cout << sum;
}










int n;

int dpfun(int i, int cntOfBLR, vector < vector < int > >& cost) {
    if(i == n) return 0;

    int x = 1e9, y = 1e9;
    
    if(cntOfBLR < n/2) {
        x = cost[i][0] + dpfun(i + 1, cntOfBLR + 1, cost);
    }
    
    int cntOfHyd = i - cntOfBLR;
    if(cntOfHyd < n/2) {
        y = cost[i][1] + dpfun(i + 1, cntOfBLR, cost);
    }

    return min(x, y);
}



bool compare(vector<int>& a, vector<int>& b) {
    return (a[0] - a[1]) < (b[0] - b[1]);
}
int greedyfun(vector<vector<int> > cost) {
    sort(cost.begin(), cost.end(), compare);

    int sum = 0;
    for(int i = 0; i < n/2; i++) {
        sum += cost[i][0];
    }
    for(int i = n/2; i < n; i++) {
        sum += cost[i][1];
    }
    return sum;
}

void solve() {
    cin >> n;
    vector<int> BLR(n), HYD(n);

    for(int i = 0; i < n; i++) {
        cin >> BLR[i] >> HYD[i];
    }

    vector<vector<int> > cost(n, vector<int>(2));
    for(int i = 0; i < n; i++) {
        cost[i][0] = BLR[i]; 
        cost[i][1] = HYD[i];
    }
    
    cout << dpfun(0, 0, cost) << endl; 
    cout << greedyfun(cost) << endl; 
}
