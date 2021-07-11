// https://www.lintcode.com/problem/minimize-max-distance-to-gas-station/

/*
On a horizontal number line, we have gas stations at positions stations[0], stations[1], ..., stations[N-1]
Now, we add K more gas stations so that D, the maximum distance between adjacent gas stations, is minimized.
Return the smallest possible value of D.

1.stations.length will be an integer in range [10, 2000].
2.stations[i] will be an integer in range [0, 10^8].
3.K will be an integer in range [1, 10^6].
4.Answers within 10^-6 of the true value will be accepted as correct.
*/

// FFFFFFFTTTTTTT

class Solution {
public:
    /**
     * @param stations: an integer array
     * @param k: an integer
     * @return: the smallest possible value of D
     */

    bool check(double x, int k, vector <int>& stations){
        int newStations = 0;
        for (int i = 0; i < stations.size() - 1; i++) {
            newStations += ceil((stations[i + 1] - stations[i]) / x) - 1;
        }
        return newStations <= k;
    }
    
    double minmaxGasDist(vector<int> &stations, int k) {
        int n = stations.size();
        double low = 0;
        double high = stations[n - 1] - stations[0];
        while (high - low >= 1e-6) {
            double mid = (low + high) / 2.0;
            if (check(mid, k, stations)) {
                high = mid;
            } else {
                low = mid;
            }
        }
        return low;
    }
};
