#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    string name, theGoodKid = "";
    //vector<string> kids;
    int posGoodKid = 0;

    while(getline(cin, name)) {
        //kids.push_back(name);
        if (to_upper(name) > to_upper(theGoodKid)) theGoodKid = name;
    }
//    sort(kids.begin(),kids.end());
//    cout << kids[kids.size()-1] << "\n";
    cout << theGoodKid << endl;

    return EXIT_SUCCESS;
}