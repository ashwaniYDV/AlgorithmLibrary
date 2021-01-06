#include <iostream>

using namespace std;

int main() {
    int c;
    string rajeshChoice, sheldonChoice;

    cin >> c;

    for (int i = 1; i <= c; i++) {
        cin >> sheldonChoice >> rajeshChoice;

        if (rajeshChoice == sheldonChoice) {
            cout << "Caso #" << i << ": De novo!" << endl;
            continue;
        }
        // Scissors cuts paper
        if (rajeshChoice == "tesoura" && sheldonChoice == "papel") cout << "Caso #" << i << ": Raj trapaceou!" << endl;
        if (rajeshChoice == "papel" && sheldonChoice == "tesoura") cout << "Caso #" << i << ": Bazinga!" << endl;
        // Paper covers rock
        if (rajeshChoice == "papel" && sheldonChoice == "pedra") cout << "Caso #" << i << ": Raj trapaceou!" << endl;
        if (rajeshChoice == "pedra" && sheldonChoice == "papel") cout << "Caso #" << i << ": Bazinga!" << endl;
        // Rock tips lizard
        if (rajeshChoice == "pedra" && sheldonChoice == "lagarto") cout << "Caso #" << i << ": Raj trapaceou!" << endl;
        if (rajeshChoice == "lagarto" && sheldonChoice == "pedra") cout << "Caso #" << i << ": Bazinga!" << endl;
        // Lizard Spock falls asleep
        if (rajeshChoice == "lagarto" && sheldonChoice == "Spock") cout << "Caso #" << i << ": Raj trapaceou!" << endl;
        if (rajeshChoice == "Spock" && sheldonChoice == "lagarto") cout << "Caso #" << i << ": Bazinga!" << endl;
        // Spock melts scissors
        if (rajeshChoice == "Spock" && sheldonChoice == "tesoura") cout << "Caso #" << i << ": Raj trapaceou!" << endl;
        if (rajeshChoice == "tesoura" && sheldonChoice == "Spock") cout << "Caso #" << i << ": Bazinga!" << endl;
        // Scissors holds lizard
        if (rajeshChoice == "tesoura" && sheldonChoice == "lagarto") cout << "Caso #" << i << ": Raj trapaceou!" << endl;
        if (rajeshChoice == "lagarto" && sheldonChoice == "tesoura") cout << "Caso #" << i << ": Bazinga!" << endl;
        // lizard eats paper
        if (rajeshChoice == "lagarto" && sheldonChoice == "papel") cout << "Caso #" << i << ": Raj trapaceou!" << endl;
        if (rajeshChoice == "papel" && sheldonChoice == "lagarto") cout << "Caso #" << i << ": Bazinga!" << endl;
        // Paper disproves spock
        if (rajeshChoice == "papel" && sheldonChoice == "Spock") cout << "Caso #" << i << ": Raj trapaceou!" << endl;
        if (rajeshChoice == "Spock" && sheldonChoice == "papel") cout << "Caso #" << i << ": Bazinga!" << endl;
        // Spock vaporizes rock
        if (rajeshChoice == "Spock" && sheldonChoice == "pedra") cout << "Caso #" << i << ": Raj trapaceou!" << endl;
        if (rajeshChoice == "pedra" && sheldonChoice == "Spock") cout << "Caso #" << i << ": Bazinga!" << endl;
        // Rock crushes scissors
        if (rajeshChoice == "pedra" && sheldonChoice == "tesoura") cout << "Caso #" << i << ": Raj trapaceou!" << endl;
        if (rajeshChoice == "tesoura" && sheldonChoice == "pedra") cout << "Caso #" << i << ": Bazinga!" << endl;
    }

    return EXIT_SUCCESS;
}