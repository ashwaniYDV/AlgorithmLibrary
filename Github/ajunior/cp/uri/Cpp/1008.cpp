#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int number, hours;
    float value;

    cin >> number >> hours >> value;

    cout << setprecision(2) << fixed;
    cout << "NUMBER = " << number << endl;
    cout << "SALARY = U$ " << hours * value << endl;

    return EXIT_SUCCESS;
}