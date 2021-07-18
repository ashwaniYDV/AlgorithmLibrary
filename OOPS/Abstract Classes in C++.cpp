// https://youtu.be/0IR_D1qZy2g

#include <bits/stdc++.h>
using namespace std;

// Abstract class => iska koi object nahi ban sakta but can be inherited
class Person {
public:
    string name;
    int age;
    // pure virtual function
    virtual void fun() = 0;
};

class Student: public Person {
public:
    int rollNo;
    Student(string n, int a, int r) {
        name = n;
        age = a;
        rollNo = r;
    }
    void getStudent() {
        cout << name << " " << age << " " << rollNo << endl;
    }
    // overriding of pure virtual function is necessary
    void fun() {

    }
};

class Faculty: public Person {
public:
    int facNo;
    Faculty(string n, int a, int f) {
        name = n;
        age = a;
        facNo = f;
    }
    void getFaculty() {
        cout << name << " " << age << " " << facNo << endl;
    }
    // overriding of pure virtual function is necessary
    void fun() {
        
    }
};

int main() {
    Student ash("ashwani", 21, 13);
    ash.getStudent();
    Faculty shiva("shiva", 40, 1111);
    shiva.getFaculty();
}


/*
ashwani 21 13
shiva 40 1111
*/
