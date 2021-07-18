/*
Note: Base class pointer can point to the objet of derived class but not vice versa
*/

// Not correct behaviour due to early binding

#include <bits/stdc++.h>
using namespace std;

class base {
public:
    void fun() {
        cout << "base fun\n";
    }
};

class derived: public base {
public:
    void fun() {
        cout << "derived fun\n";
    }
};

int main() {
    derived d;
    base *b = &d;
    b->fun();
}

/*
base fun
*/









// Correct behaviour by late binding

#include <bits/stdc++.h>
using namespace std;

class base {
public:
    virtual void fun() {
        cout << "base fun\n";
    }
};

class derived: public base {
public:
    void fun() {
        cout << "derived fun\n";
    }
};

int main() {
    derived d;
    base *b = &d;
    b->fun();
}

/*
derived fun
*/
