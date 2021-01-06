#include <iostream>

using namespace std;

int main() {
    int a, b, c;

    cin >> a >> b >> c;

    // If the temperature decreased from the 1st to the 2nd day, but increased or remained constant
    // from the 2nd to the 3rd, the people are happy (first figure).
    if (a > b && b <= c) cout << ":)" << endl;

    // If the temperature increased from the 1st to the 2nd day, but decreased or remained constant
    // from the 2nd to the 3rd, the people are sad (second figure).
    if (a < b && b >= c) cout << ":(" << endl;

    // If the temperature increased from the 1st to the 2nd day and from the 2nd to the 3rd, but increased
    // from the 2nd to the 3rd less than what had increased from the 1st to the 2nd, the people are sad (third figure).
    if ( (a < b && b < c) && ((c - b) < (b - a)))  cout << ":(" << endl;

    // If the temperature increased from the 1st to the 2nd day and from the 2nd to the 3rd, but increased
    // from the 2nd to the 3rd at least what had increased from the 1st to the 2nd, the people are happy (fourth figure).
    if ( (a < b && b < c) && ((c - b) >= (b - a)) ) cout << ":)" << endl;

    // If the temperature decreased from the 1st to the 2nd day and from the 2nd to the 3rd, but decreased
    // from the 2nd to the 3rd less than what had decreased from the 1st to the 2nd, the people are happy (fifth figure).
    if ( (a > b && b > c) && ((b - c) < (a - b)) ) cout << ":)" << endl;

    // If the temperature decreased from the 1st to the 2nd day and from the 2nd to the 3rd, but decreased
    // from the 2nd to the 3rd at least what had decreased from the 1st to the 2nd, the people are sad (sixth figure).
    if ( (a > b && b > c) && ((b - c) >= (a - b)) ) cout << ":(" << endl;

    // If the temperature remained constant from the 1st to the 2nd day, the people are happy if the temperature
    // increased from the 2nd to the 3rd or sad otherwise (respectively, seventh and eighth figures).
    if ((a == b && b < c)) cout << ":)" << endl;
    if ((a == b && b >= c)) cout << ":(" << endl;

    return EXIT_SUCCESS;
}