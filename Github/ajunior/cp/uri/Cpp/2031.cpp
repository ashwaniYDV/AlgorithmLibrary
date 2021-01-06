#include <iostream>

using namespace std;

int main() {
    int n;
    string p1Choice, p2Choice;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> p1Choice >> p2Choice;

        // Airstrike vs Rock
        if (p1Choice == "ataque" && p2Choice == "pedra") cout << "Jogador 1 venceu\n";
        else if (p2Choice == "ataque" && p1Choice == "pedra") cout << "Jogador 2 venceu\n";

        // Rock vs Paper
        else if (p1Choice == "pedra" && p2Choice == "papel") cout << "Jogador 1 venceu\n";
        else if (p2Choice == "pedra" && p1Choice == "papel") cout << "Jogador 2 venceu\n";

        // Airstrike vs Paper
        else if (p1Choice == "ataque" && p2Choice == "papel") cout << "Jogador 1 venceu\n";
        else if (p2Choice == "ataque" && p1Choice == "papel") cout << "Jogador 2 venceu\n";

        // Paper vs Paper
        else if (p1Choice == "papel" && p2Choice == "papel") cout << "Ambos venceram\n";

        // Rock vs Rock
        else if (p1Choice == "pedra" && p2Choice == "pedra") cout << "Sem ganhador\n";

        // Airstrike vs Airstrike
        else if (p1Choice == "ataque" && p2Choice == "ataque")cout << "Aniquilacao mutua\n";
    }

    return 0;
}