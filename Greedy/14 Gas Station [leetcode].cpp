// https://leetcode.com/problems/gas-station/
// https://youtu.be/xmJZSYSvgfE

/*
There are n gas stations along a circular route, where the amount of gas at the ith station is gas[i].
You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from the ith station to its next (i + 1)th station. 
You begin the journey with an empty tank at one of the gas stations.
Given two integer arrays gas and cost, return the starting gas station's index if you can travel around the circuit once in the clockwise direction, 
otherwise return -1. If there exists a solution, it is guaranteed to be unique
*/


class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        
        int total_surplus = 0;
        for(int i = 0; i < n; ++i) {
            total_surplus += gas[i] - cost[i];
        }
        if(total_surplus < 0) return -1;
        
        int surplus = 0;
        int start = 0;
        for(int i = 0; i < n; ++i) {
            surplus += gas[i] - cost[i];
            if(surplus < 0) {
                surplus = 0;
                start = i+1;
            }
        }
        return start;
    }
};




// My method
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();

        int total = 0;
        for(int i = 0; i < n; i++) {
            gas[i] -= cost[i];
            total += gas[i];
        }
        if(total < 0) return -1;

        int i = 0;
        while(i < n) {
            int sum = 0, cnt = 0, j = i;
            while(1) {
                sum += gas[j];
                if(sum < 0) {
                    i = j + 1;
                    break;
                }
                cnt++;
                if(cnt == n) return i;
                j++;
                j %= n;
            }
        }

        return -1;
    }
};
