#include <iostream>

using namespace std;

int main() {
    int n, r, mary = 0, john = 0;

    do {
        cin >> n;

        if (n != 0) {

            for (int i = 0; i < n; ++i) {
                cin >> r;

                if (r == 0) mary++;
                else john++;
            }

            cout << "Mary won " << mary << " times and John won " << john << " times" << endl;
            mary = 0;
            john = 0;
        }
    } while (n != 0);

    return EXIT_SUCCESS;
}