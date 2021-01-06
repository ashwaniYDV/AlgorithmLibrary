#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    vector<int> v;

    for (int i = 0; i < 4; i++) {
        cin >> n;
        v.push_back(n);
    }
    sort(v.begin(), v.end());

    do {
        for (int k = 1; k <= v.size(); k++) {
            if (k % 4 == 0)
                cout << v[k] << endl;
            else
                cout << v[k] << " ";
        }

    } while (next_permutation(v.begin(),v.end()));


    //for (vector<int>::iterator i = v.begin(); i <= v.end() -1; i++)
        //cout << next_permutation(v.begin(),) << endl;
    //if (a+b <= c || a+b <= d || a+c <= b || a+c <= d || a+d <= b || a+d <= c)

    return EXIT_SUCCESS;
}