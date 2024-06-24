// https://www.scaler.com/problems/hotel-bookings-possible/

/*
A hotel manager has to process N advance bookings of rooms for the next season. 
His hotel has K rooms.
Bookings contain an arrival date and a departure date.
He wants to find out whether there are enough rooms in the hotel to satisfy the demand.

Problem Constraints
1 <= N <= 10^6
1 <= K <= 10^6
0 <= arrive[i] <= depart[i] <= 10^8
*/

bool Solution::hotel(vector<int> &arr, vector<int> &dep, int K) {
    int n = arr.size();
    // Sort arrival and departure vectors
    sort(arr.begin(), arr.end());
    sort(dep.begin(), dep.end());

    // room_needed indicates number of rooms needed at a time
    int room_needed = 1, result = 1;
    int i = 1, j = 0;

    // Similar to merge in merge sort to process all events in sorted order
    while (i < n && j < n) {
        // If next event in sorted order is arrival, increment count of room_needed
        if (arr[i] <= dep[j]) {
            room_needed++;
            i++;
        }
        // Else decrement count of room_needed
        else {
            room_needed--;
            j++;
        }

        result = max(result, room_needed);
    }

    return result <= K;
}
