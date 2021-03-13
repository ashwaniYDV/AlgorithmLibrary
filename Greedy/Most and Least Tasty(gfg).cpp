// https://practice.geeksforgeeks.org/contest-problem/most-and-least-testy/1/

/*
It is necessary to include all the chocolates in one partition or another.
There will be a partition starting at 0 and one partition ending at N-1 position.

Rest there will be K-1 partioning adjacent elements (i.e a[i] and a[i+1]) 
where a[i] is the ending of (j)th partition and a[i+1] is the starting of (j+1)th partition 
*/

class Solution{
    public:
        long long diffInTaste(int N, int K, int Arr[]){
            long long max, min;
            max = min = Arr[0] + Arr[N-1];
            priority_queue<int> q1;
            priority_queue<int, vector<int>, greater<int>> q2;
            for(int i = 0; i < N-1; i++) {
                q1.push(Arr[i] + Arr[i+1]);
                q2.push(Arr[i] + Arr[i+1]);
            }
            for(int i = 0; i < K-1; i++){
                max += q1.top(); 
                q1.pop();
                min += q2.top(); 
                q2.pop();
            }
            return max - min;
        }
};
