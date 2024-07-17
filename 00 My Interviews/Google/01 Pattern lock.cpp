// https://adamoudad.github.io/posts/lock_pattern/
// https://www.geeksforgeeks.org/number-of-ways-to-make-mobile-lock-pattern/

#include <bits/stdc++.h>
using namespace std;

unordered_map<string, char> INTERMEDIATE_POINT = {
    {"13", '2'}, 
    {"46", '5'}, 
    {"79", '8'},
    {"17", '4'}, 
    {"28", '5'}, 
    {"39", '6'},
    {"19", '5'}, 
    {"37", '5'}
};

bool is_pattern_valid(string& pattern) {
    for (auto& [sequence, point] : INTERMEDIATE_POINT) {
        if (pattern.find(sequence) != string::npos || pattern.find(string(sequence.rbegin(), sequence.rend())) != string::npos) {
            if (pattern.find(point) == string::npos || pattern.find(point) > pattern.find(sequence[1])) {
                return false;
            }
        }
    }
    return true;
}

int count_patterns(string pattern, string points, int max_length = 9, int min_length = 4) {
    if (!is_pattern_valid(pattern))
        return 0;

    int count = 0;
    if (pattern.length() >= min_length) {
        count += 1;
    }

    if (pattern.length() == max_length || points.empty()) {
        return count;
    }
    
    for (char p : points) {
        string new_points = points;
        new_points.erase(new_points.find(p), 1);
        count += count_patterns(pattern + p, new_points, max_length, min_length);
    }
    return count;
}

int main() {
    string points = "123456789";
    int res = count_patterns("", points, 9, 4);
    cout << res << endl;
    return 0;
}
