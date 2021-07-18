// https://www.geeksforgeeks.org/overloading-stream-insertion-operators-c/
// https://youtu.be/TwW2Nl45FvE


#include <iostream>
using namespace std;

class Complex {
private:
    int real, imag;
public:
    Complex(int r = 0, int i = 0) {
        real = r;
        imag = i;
    }
    friend ostream & operator << (ostream &out, const Complex &c);
    friend istream & operator >> (istream &in, Complex &c);
};

ostream & operator << (ostream &out, const Complex &c) {
    out << c.real << "+i" << c.imag << endl;
    return out;
}

istream & operator >> (istream &in, Complex &c) {
    cout << "Enter Real Part:\n";
    in >> c.real;
    cout << "Enter Imaginary Part:\n";
    in >> c.imag;
    return in;
}
/*
istream & operator >> (istream &in, Complex &c) {
    cout << "Enter Real and Imaginary Parts:\n";
    in >> c.real >> c.imag;
    return in;
}
*/

int main() {
    Complex c1;
    cin >> c1;
    cout << "The complex object is = " << c1;
    return 0;
}
