#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main() {
    string name;
    double salary, sold;

    cin >> name >> salary >> sold;

    cout << setprecision(2) << fixed;
    cout << "TOTAL = U$ " << salary + (sold * 0.15) << endl;

    return EXIT_SUCCESS;
}