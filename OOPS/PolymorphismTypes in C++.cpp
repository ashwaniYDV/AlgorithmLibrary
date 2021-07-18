/*
The word polymorphism means having many forms. In simple words, we can define polymorphism as the ability of a message to be displayed in more than one form. 
A real-life example of polymorphism, a person at the same time can have different characteristics. 
Like a man at the same time is a father, a husband, an employee. So the same person posses different behavior in different situations. 
This is called polymorphism. Polymorphism is considered as one of the important features of Object Oriented Programming.

In C++ polymorphism is mainly divided into two types:
1) Compile time Polymorphism
2) Runtime Polymorphism

                                
                                            Polymorphism
                                          /               \
                   Compile time Polymorphism               Runtime Polymorphism
                                    /                          \
                  a) Function Overloading                    a) Function overriding (Virtual Function)
                  b) Operator Overloading



1) Compile time polymorphism: This type of polymorphism is achieved by function overloading or operator overloading.

Function Overloading: When there are multiple functions with same name but different parameters then these functions are said to be overloaded. 
Functions can be overloaded by change in number of arguments or/and change in type of arguments.

Operator Overloading: C++ also provide option to overload operators. For example, we can make the operator (‘+’) for string class to concatenate two strings. 
We know that this is the addition operator whose task is to add two operands. 
So a single operator ‘+’ when placed between integer operands , adds them and when placed between string operands, concatenates them.

2) Runtime polymorphism: This type of polymorphism is achieved by Function Overriding.
Function overriding on the other hand occurs when a derived class has a definition for one of the member functions of the base class. 
That base function is said to be overridden.
*/










// C++ program for function overloading
#include <bits/stdc++.h>

using namespace std;
class Geeks {
    public:
    
    // function with 1 int parameter
    void func(int x) {
        cout << "value of x is " << x << endl;
    }
    
    // function with same name but 1 double parameter
    void func(double x) {
        cout << "value of x is " << x << endl;
    }
    
    // function with same name and 2 int parameters
    void func(int x, int y) {
        cout << "value of x and y is " << x << ", " << y << endl;
    }
};

int main() {
    Geeks obj1;
    
    // Which function is called will depend on the parameters passed
    // The first 'func' is called
    obj1.func(7);
    
    // The second 'func' is called
    obj1.func(9.132);
    
    // The third 'func' is called
    obj1.func(85,64);
    return 0;
}






















// CPP program to illustrate Operator Overloading
#include<iostream>
using namespace std;

class Complex {
private:
    int real, imag;
public:
    Complex(int r = 0, int i =0) {
        real = r; imag = i;
    }
    
    // This is automatically called when '+' is used with between two Complex objects
    Complex operator + (Complex const &obj) {
        Complex res;
        res.real = real + obj.real;
        res.imag = imag + obj.imag;
        return res;
    }
    void print() { 
        cout << real << " + i" << imag << endl; 
    }
};

int main() {
    Complex c1(10, 5), c2(2, 4);
    Complex c3 = c1 + c2; // An example call to "operator+"
    c3.print();
}






















// C++ program for function overriding
#include <bits/stdc++.h>
using namespace std;

class base {
public:
    virtual void print () {
        cout << "Print: base class" << endl;
    }

    void show () {
        cout << "Show: base class" << endl;
    }
};

class derived: public base {
public:
     //print () is already virtual function in derived class, we could also declared as virtual void print () explicitly
    void print () { 
        cout << "Print: derived class" << endl; 
    }

    void show () { 
        cout << "Show: derived class" << endl; 
    }
};

int main() {
    base *bptr;
    derived d;
    bptr = &d;

    //virtual function, binded at runtime (Runtime polymorphism)
    bptr->print();

    // Non-virtual function, binded at compile time
    bptr->show();

    return 0;
}
