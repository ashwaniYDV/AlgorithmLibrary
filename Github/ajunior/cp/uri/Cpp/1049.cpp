#include <iostream>

using namespace std;

int main() {
    string wordOne, wordTwo, wordThree;

    cin >> wordOne >> wordTwo >> wordThree;

    if (wordOne == "vertebrado") {
        if (wordTwo == "ave") {
            if (wordThree == "carnivoro") cout << "aguia" << endl;
            else cout << "pomba" << endl;
        } else {
            if (wordThree == "onivoro") cout << "homem" << endl;
            else cout << "vaca" << endl;
        }
    } else {
        if (wordTwo == "inseto") {
            if (wordThree == "hematofago") cout << "pulga" << endl;
            else cout << "lagarta" << endl;
        } else {
            if (wordThree == "hematofago") cout << "sanguessuga" << endl;
            else cout << "minhoca" << endl;
        }
    }
}
