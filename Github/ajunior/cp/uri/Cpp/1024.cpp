#include <iostream>

using namespace std;

int main() {
    string word;
    int size, half, n;
    char tmp;

    cin >> n;
    cin.ignore(); // para descartar o \n

    for (int i = 0; i < n; i++) {
        getline(cin, word);

        size = (int)word.size();

        for (int j = 0; j < size; j++) {
            if (isalpha(word[j])) word[j] += 3;
        }

        for (int k = 0; k < (size/2); k++)
            swap(word[k],word[(size-1) - k]);

        half = size/2;

        for (int l = half; l < size; l++)
            word[l] -= 1;

        cout << word << endl;
    }

    return EXIT_SUCCESS;
}