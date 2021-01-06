#include <iostream>

using namespace std;

int main() {
    float otavio, bruno, ian;
    cin >> otavio >> bruno >> ian;

    if (otavio < bruno && bruno <= ian) cout << "Otavio\n";
    else if (bruno < ian && ian <= otavio) cout << "Bruno\n";
    else if (ian < otavio && otavio <= bruno) cout << "Ian\n";

    else if (otavio == bruno && bruno <= ian) cout << "Empate\n";
    else if (bruno == ian && ian <= otavio) cout << "Empate\n";
    else if (ian == otavio && otavio <= bruno) cout << "Empate\n";

    return 0;
}