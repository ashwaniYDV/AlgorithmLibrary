#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main () {
    int n;
    string x, y;

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> x >> y;

        cout << "Caso " << i << ":\n";

        if (y == "bin") {
            cout << stoi(x,nullptr,2) << " dec\n";
            cout << hex << stoi(x,nullptr,2) << " hex\n";
        }
        else if (y == "dec") {
            cout << hex << stoi(x) << " hex\n";
            cout << stoi(x,nullptr,2) << " bin\n";
        }
        else {
            cout << setbase(16) << x << " hex\n";
            //cout << bin << x << " bin\n";
        }
    }



    return EXIT_SUCCESS;
}