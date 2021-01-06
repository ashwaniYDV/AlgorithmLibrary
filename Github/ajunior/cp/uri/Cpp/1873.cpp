#include <iostream>

using namespace std;

int main() {
    int c;
    string rajeshChoice, sheldonChoice;

    cin >> c;

    for (int i = 0; i < c; i++) {
        cin >> rajeshChoice >> sheldonChoice;

        if (rajeshChoice == sheldonChoice) {
            cout << "empate" << endl;
            continue;
        }

        // Scissors cuts paper
        if (rajeshChoice == "tesoura" && sheldonChoice == "papel") {
            cout << "rajesh" << endl;
            continue;
        }
        if (rajeshChoice == "papel" && sheldonChoice == "tesoura") {
            cout << "sheldon" << endl;
            continue;
        }

        // Paper covers rock
        if (rajeshChoice == "papel" && sheldonChoice == "pedra") {
            cout << "rajesh" << endl;
            continue;
        }
        if (rajeshChoice == "pedra" && sheldonChoice == "papel") {
            cout << "sheldon" << endl;
            continue;
        }

        // Rock tips lizard
        if (rajeshChoice == "pedra" && sheldonChoice == "lagarto") {
            cout << "rajesh" << endl;
            continue;
        }
        if (rajeshChoice == "lagarto" && sheldonChoice == "pedra") {
            cout << "sheldon" << endl;
            continue;
        }

        // Lizard Spock falls asleep
        if (rajeshChoice == "lagarto" && sheldonChoice == "spock") {
            cout << "rajesh" << endl;
            continue;
        }
        if (rajeshChoice == "spock" && sheldonChoice == "lagarto") {
            cout << "sheldon" << endl;
            continue;
        }

        // Spock melts scissors
        if (rajeshChoice == "spock" && sheldonChoice == "tesoura") {
            cout << "rajesh" << endl;
            continue;
        }
        if (rajeshChoice == "tesoura" && sheldonChoice == "spock") {
            cout << "sheldon" << endl;
            continue;
        }

        // Scissors holds lizard
        if (rajeshChoice == "tesoura" && sheldonChoice == "lagarto") {
            cout << "rajesh" << endl;
            continue;
        }
        if (rajeshChoice == "lagarto" && sheldonChoice == "tesoura") {
            cout << "sheldon" << endl;
            continue;
        }

        // lizard eats paper
        if (rajeshChoice == "lagarto" && sheldonChoice == "papel") {
            cout << "rajesh" << endl;
            continue;
        }
        if (rajeshChoice == "papel" && sheldonChoice == "lagarto") {
            cout << "sheldon" << endl;
            continue;
        }

        // Paper disproves spock
        if (rajeshChoice == "papel" && sheldonChoice == "spock") {
            cout << "rajesh" << endl;
            continue;
        }
        if (rajeshChoice == "spock" && sheldonChoice == "papel") {
            cout << "sheldon" << endl;
            continue;
        }

        // Spock vaporizes rock
        if (rajeshChoice == "spock" && sheldonChoice == "pedra") {
            cout << "rajesh" << endl;
            continue;
        }
        if (rajeshChoice == "pedra" && sheldonChoice == "spock") {
            cout << "sheldon" << endl;
            continue;
        }

        // Rock crushes scissors
        if (rajeshChoice == "pedra" && sheldonChoice == "tesoura") {
            cout << "rajesh" << endl;
            continue;
        }
        if (rajeshChoice == "tesoura" && sheldonChoice == "pedra") {
            cout << "sheldon" << endl;
            continue;
        }
    }

    return EXIT_SUCCESS;
}