#include <iostream>
#include <set>

using namespace std;

int main() {
    int n;
    string pokemonName;
    set<string>pokemonCollected;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> pokemonName;
        pokemonCollected.insert(pokemonName);
    }

    cout << "Falta(m) " << 151 - pokemonCollected.size() << " pomekon(s).\n";

    return 0;
}