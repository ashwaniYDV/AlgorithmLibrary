// https://www.geeksforgeeks.org/virtual-functions-and-runtime-polymorphism-in-c-set-1-introduction/




// Real-life use case

#include <bits/stdc++.h>
using namespace std;

class Employee {
public:
    string name;
    int salary;
    int level;
    Employee(string n, int s, int l) {
        name = n;
        salary = s;
        level = l;
    }
    virtual void raiseSalary() {
        /* common raise salary code */
    }

    virtual void promote() { 
        /* common promote code */ 
    }
    void print() { 
        cout << "Name:\t" << name << endl;
        cout << "Salary:\t" << salary << endl;
        cout << "Level:\t" << level << endl;
        cout << endl;
    }
};

class Manager : public Employee {
public:
    Manager(string n, int s, int l) : Employee(n, s, l) {}
    virtual void raiseSalary() {
        /* Manager specific raise salary code, may contain increment of manager specific incentives*/
        cout << "Manager raise salary.\n";
        salary += 100;

    }
    virtual void promote() {
        /* Manager specific promote */
        cout << "Manager promote.\n";
        level += 2;
    }
};

class Developer : public Employee {
public:
    Developer(string n, int s, int l) : Employee(n, s, l) {}
    virtual void raiseSalary() {
        /* Developer specific raise salary code, may contain increment of developer specific incentives*/
        cout << "Developer raise salary.\n";
        salary += 50;
    }
    virtual void promote() {
        /* Developer specific promote */
        cout << "Developer promote.\n";
        level += 1;
    }
};

// Similarly, there may be other types of employees


// We need a very simple function to increment salary and promote of all employees
// Note that emp is a vector of pointers and actual pointed objects can be any type of employees.
// This function should ideally be in a class like Organization, we have made it global to keep things simple
void globalRaiseSalary(vector<Employee*> &emp) {
    for (int i = 0; i < emp.size(); i++) {
        // Polymorphic Call: Calls raiseSalary() and promote() according to the actual object, not according to the type of pointer
        emp[i]->raiseSalary();
        emp[i]->promote();
        emp[i]->print();
    }
}


int main(void) {
    Manager *m1 = new Manager("manager1", 200, 1);
    Manager *m2 = new Manager("manager2", 500, 3);
    Developer *d1 = new Developer("developer1", 100, 1);
    Developer *d2 = new Developer("developer1", 400, 2);
    
    vector<Employee*> a = {m1, m2, d1, d2};
    globalRaiseSalary(a);

    return 0;
}

/*
Manager raise salary.
Manager promote.
Name:	manager1
Salary:	300
Level:	3

Manager raise salary.
Manager promote.
Name:	manager2
Salary:	600
Level:	5

Developer raise salary.
Developer promote.
Name:	developer1
Salary:	150
Level:	2

Developer raise salary.
Developer promote.
Name:	developer1
Salary:	450
Level:	3
*/

















// Using Abstract Class

#include <bits/stdc++.h>
using namespace std;

class Employee {
public:
    string name;
    int salary;
    int level;
    Employee(string n, int s, int l) {
        name = n;
        salary = s;
        level = l;
    }
    
    virtual void raiseSalary() = 0;

    virtual void promote() = 0;

    void print() { 
        cout << "Name:\t" << name << endl;
        cout << "Salary:\t" << salary << endl;
        cout << "Level:\t" << level << endl;
        cout << endl;
    }
};

class Manager : public Employee {
public:
    Manager(string n, int s, int l) : Employee(n, s, l) {}
    virtual void raiseSalary() {
        /* Manager specific raise salary code, may contain increment of manager specific incentives*/
        cout << "Manager raise salary.\n";
        salary += 100;

    }
    virtual void promote() {
        /* Manager specific promote */
        cout << "Manager promote.\n";
        level += 2;
    }
};

class Developer : public Employee {
public:
    Developer(string n, int s, int l) : Employee(n, s, l) {}
    virtual void raiseSalary() {
        /* Developer specific raise salary code, may contain increment of developer specific incentives*/
        cout << "Developer raise salary.\n";
        salary += 50;
    }
    virtual void promote() {
        /* Developer specific promote */
        cout << "Developer promote.\n";
        level += 1;
    }
};

// Similarly, there may be other types of employees


// We need a very simple function to increment salary and promote of all employees
// Note that emp is a vector of pointers and actual pointed objects can be any type of employees.
// This function should ideally be in a class like Organization, we have made it global to keep things simple
void globalRaiseSalary(vector<Employee*> &emp) {
    for (int i = 0; i < emp.size(); i++) {
        // Polymorphic Call: Calls raiseSalary() and promote() according to the actual object, not according to the type of pointer
        emp[i]->raiseSalary();
        emp[i]->promote();
        emp[i]->print();
    }
}


int main(void) {
    Manager *m1 = new Manager("manager1", 200, 1);
    Manager *m2 = new Manager("manager2", 500, 3);
    Developer *d1 = new Developer("developer1", 100, 1);
    Developer *d2 = new Developer("developer1", 400, 2);
    
    vector<Employee*> a = {m1, m2, d1, d2};
    globalRaiseSalary(a);

    return 0;
}

































#include <iostream>
using namespace std;

// Base class
class Shape {
protected:
    int length, width;
public:
    Shape(int l, int w) {
        length = l;
        width = w;
    } 
    void get_Area() {
        cout << "Parent Class: Area = " << length * width << endl;
    }
};

// Derived class
class Square : public Shape {
public:
    // declaring and initializing derived class constructor
    Square(int l = 0, int w = 0): Shape(l, w) {}
    void get_Area() {
        cout << "Square area: " << length * width << endl;
    }
};

// Derived class
class Rectangle : public Shape {
public:
    // declaring and initializing derived class constructor
    Rectangle(int l = 0, int w = 0): Shape(l, w) {}
    void get_Area() {
        cout << "Rectangle area: " << length * width << endl;
    }
};

int main(void) {
    Shape* s;
    Square sq(5, 5); // making object of child class Square
    Rectangle rec(4, 5); // making object of child class Rectangle

    s = &sq;
    s->get_Area();
    s = &rec;
    s->get_Area();

    return 0;
}

/*
Parent Class: Area = 25
Parent Class: Area = 20
*/







#include <iostream>
using namespace std;

// Base class
class Shape {
protected:
    int length, width;
public:
    Shape(int l, int w) {
        length = l;
        width = w;
    } 
    virtual void get_Area() {
        cout << "Parent Class: Area = " << length * width << endl;
    }
};

// Derived class
class Square : public Shape {
public:
    // declaring and initializing derived class constructor
    Square(int l = 0, int w = 0): Shape(l, w) {}
    void get_Area() {
        cout << "Square area: " << length * width << endl;
    }
};

// Derived class
class Rectangle : public Shape {
public:
    // declaring and initializing derived class constructor
    Rectangle(int l = 0, int w = 0): Shape(l, w) {}
    void get_Area() {
        cout << "Rectangle area: " << length * width << endl;
    }
};

int main(void) {
    Shape* s;
    Square sq(5, 5); // making object of child class Square
    Rectangle rec(4, 5); // making object of child class Rectangle

    s = &sq;
    s->get_Area();
    s = &rec;
    s->get_Area();

    return 0;
}

/*
Square area: 25
Rectangle area: 20
*/
