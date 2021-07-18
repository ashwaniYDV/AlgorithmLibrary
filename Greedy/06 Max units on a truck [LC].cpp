// https://leetcode.com/problems/maximum-units-on-a-truck/

/*
You are assigned to put some amount of boxes onto one truck. 
You are given a 2D array boxTypes, 
where boxTypes[i] = [noOfBoxes_i, noOfUnitsPerBox_i]:
    noOfBoxes_i = no of boxes of type i.
    noOfUnitsPerBox_i = no of units in each box of the type i.
You are also given an integer truckSize, which is the max no of boxes that can be put on the truck. 
You can choose any boxes to put on the truck as long as the number of boxes does not exceed truckSize.
Return the maximum total number of units that can be put on the truck.

Input: boxTypes = [[1,3],[2,2],[3,1]], truckSize = 4
Output: 8
Explanation: There are:
- 1 box of the first type that contains 3 units.
- 2 boxes of the second type that contain 2 units each.
- 3 boxes of the third type that contain 1 unit each.
You can take all the boxes of first and second types, and one box of third type.
Total no of units will be = (1 * 3) + (2 * 2) + (1 * 1) = 8.
*/


// Fractional knapsack concept
class Solution {
public:
    static bool compare(vector<int>& a, vector<int>& b) {
        return a[1] > b[1];
    }

    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        int n = boxTypes.size();
        sort(boxTypes.begin(), boxTypes.end(), compare);
        
        int res = 0;
        
        for(int i = 0; i < n; i++) {
            int noOfBoxes = boxTypes[i][0];
            int noOfUnitsPerBox = boxTypes[i][1];
            if(noOfBoxes <= truckSize) {
                truckSize -= noOfBoxes;
                res += noOfBoxes * noOfUnitsPerBox;
            } else {
                res += truckSize * noOfUnitsPerBox;
                break;
            }
        }
        
        return res;
    }
};