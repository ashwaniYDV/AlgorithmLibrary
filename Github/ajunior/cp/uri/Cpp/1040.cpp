#include <iostream>
#include <iomanip>

using namespace std;

double mediaponderada (double a, double b, double c, double d);

int main() {
    double a, b, c, d, e, media;

    cin >> a >> b >> c >> d;

    media = mediaponderada(a,b,c,d);

    cout << setprecision(1) << fixed;

    if (media < 5.0) {
        cout << "Media: " << media << endl;
        cout << "Aluno reprovado.\n";
    }
    else if (media < 7.0) {
        cout << "Media: " << media << endl;
        cout << "Aluno em exame.\n";
        cin >> e;
        cout << "Nota do exame: " << e << endl;
        media = (media + e) / 2;
        if (media < 5.0) {
            cout << "Aluno reprovado.\n";
            cout << "Media final: " << media << endl;
        }
        else {
            cout << "Aluno aprovado.\n";
            cout << "Media final: " << media << endl;
        }

    } else {
        cout << "Media: " << media << endl;
        cout << "Aluno aprovado.\n";
    }

    return EXIT_SUCCESS;
}

double mediaponderada(double a, double b, double c, double d) {
    return (((a * 2) + (b * 3) + (c * 4) + (d * 1)) / (2+3+4+1));
}