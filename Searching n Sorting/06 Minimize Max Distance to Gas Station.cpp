// https://www.naukri.com/code360/problems/minimise-max-distance_7541449?leftPanelTabValue=PROBLEM
// https://youtu.be/kMSBvlZ-_HA?si=INTKF71GzGEJ-QrK

/*
On a horizontal number line, we have gas stations at positions stations[0], stations[1], ..., stations[N-1]
Now, we add K more gas stations so that D, the maximum distance between adjacent gas stations, is minimized.
Return the smallest possible value of D.

1.stations.length will be an integer in range [10, 2000].
2.stations[i] will be an integer in range [0, 10^8].
3.K will be an integer in range [1, 10^6].
4.Answers within 10^-6 of the true value will be accepted as correct.
*/

// Method 1 (Brute force)
// Time = k * n
double minimiseMaxDistance(vector<int> &stations, int k){
	int n = stations.size();
	// there are n-1 section bw these n stations
	// we will place new gas stations in these n-1 sections
	vector<int> howManyPlaced(n-1, 0);

    // we will place new gas stations one by one (greedily) in a section having maximum length
	for(int gasStation = 1; gasStation <= k; gasStation++) {
		long double maxSectionLength = -1;
		int maxIdx = -1;

        // there are n-1 section bw these n stations
		for(int i = 0; i < n-1; i++) {
			long double diff = stations[i+1] - stations[i];
            // sectionLength is calculated considering previously placed new gas stations
            // if we have to place x = 2 statons in a section then we divide length by 3 (=2 + 1)
			long double sectionLength = diff / (long double)(howManyPlaced[i] + 1);

			if(sectionLength > maxSectionLength) {
				maxSectionLength = sectionLength;
				maxIdx = i;
			}
		}

        // we will place current gasStation in maxIdx
		howManyPlaced[maxIdx]++;
	}

	long double  res = 0;
	for(int i = 0; i < n-1; i++) {
		long double diff = stations[i+1] - stations[i];
		long double sectionLength = diff / (long double)(howManyPlaced[i] + 1);
		res = max(res, sectionLength);
	}

	return res;
}





// Method 1 (priority_queue optimized)
// Time = n*logn + k*logn
// Space = n-1
double minimiseMaxDistance(vector<int> &stations, int k){
	int n = stations.size();
	// there are n-1 section bw these n stations
	// we will place new gas stations in these n-1 sections
	vector<int> howManyPlaced(n-1, 0);

	priority_queue<pair<long double, int>> pq;
	for(int i = 0; i < n-1; i++) {
		pq.push({stations[i+1] - stations[i], i});
	}

    // we will place new gas stations one by one (greedily) in a section having maximum length
	for(int gasStation = 1; gasStation <= k; gasStation++) {
		auto it = pq.top();
		pq.pop();

		int sectionIdx = it.second;
        // we will place current gasStation in sectionIdx
		howManyPlaced[sectionIdx]++;

		long double initialSectionLength = stations[sectionIdx+1] - stations[sectionIdx];
		long double currentSectionLength = initialSectionLength / (long double)(howManyPlaced[sectionIdx] + 1);

		pq.push({currentSectionLength, sectionIdx});

	}

	return pq.top().first;
}




// FFFFFFFTTTTTTT
// Method 3
bool check(double mid, int k, vector <int>& stations){
	int newStations = 0;
	for (int i = 0; i < stations.size() - 1; i++) {
		newStations += ceil((stations[i + 1] - stations[i]) / mid) - 1;
	}
	return newStations <= k;
}

double minimiseMaxDistance(vector<int> &stations, int k){
	int n = stations.size();
	long double lo = 0;
	long double hi = 0;
	for(int i = 0; i < n-1; i++) {
		hi = max(hi, (long double)(stations[i + 1] - stations[i]));
	}

	long double diff = 1e-6;
	while (hi - lo > diff) {
		long double mid = (lo + hi) / 2.0;
		if (check(mid, k, stations)) {
			hi = mid;
		} else {
			lo = mid;
		}
	}

    // Note: it is FFFFFTTTTTT form, but we will not return lo in this case, because here when while loop ends: 
    // hi != lo, or
    // lo !> hi (reverse parity) -> [due to 1e-6 factor (high - low > diff), lo will always be < hi]
	return hi;
}
