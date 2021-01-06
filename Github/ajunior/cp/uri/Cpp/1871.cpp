#include <iostream>
#include <string>

using namespace std;

int main () {
    int a, b, tamanho;
    string result;

    while (cin >> a >> b) {
        if (a == b && (a+b) == 0) { continue; }
        result = to_string(a+b);

        tamanho = result.size();
        for(int i = 0; i < tamanho; i++) {
            if (result[i] != '0')
                cout << result[i];
        }
        cout << endl;
    }
    return 0;
}