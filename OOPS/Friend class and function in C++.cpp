// https://www.geeksforgeeks.org/friend-class-function-cpp/

/*
Friend Class:
A friend class can access private and protected members of other class in which it is declared as friend. 
It is sometimes useful to allow a particular class to access private members of other class. 
For example, a LinkedList class may be allowed to access private members of Node. 
*/

class Node {
private:
    int key;
    Node* next;
    /* Other members of Node Class */

    // Now class LinkedList can access private members of Node
    friend class LinkedList;
};


/*
Friend Function: 
Like friend class, a friend function can be given a special grant to access private and protected members. 
A friend function can be: 
a) A member of another class 
b) A global function 
*/

class Node {
private:
    int key;
    Node* next;

    /* Other members of Node Class */
    friend int LinkedList::search();
    // Only search() of linkedList can access internal members
};



/*
Following are some important points about friend functions and classes: 
1) Friends should be used only for limited purpose. 
   If too many functions or external classes are declared as friends of a class with protected or private data, 
   it lessens the value of encapsulation of separate classes in object-oriented programming.
2) Friendship is not mutual. If class A is a friend of B, then B doesn’t become a friend of A automatically.
3) Friendship is not inherited (See this for more details)
4) The concept of friends is not there in Java. 
*/















// A simple and complete C++ program to demonstrate friend Class 

#include <bits/stdc++.h>
using namespace std;

class A {
private:
    int a;

public:
    A() {
        a = 0;
    }
    void set(int x) {
        a = x;
    }
    friend class B; // Friend Class
};

class B {
private:
    int b;

public:
    void showA(A& x) {
        // Since B is friend of A, it can access private members of A
        std::cout << "A::a = " << x.a;
    }
};

int main() {
    A a;
    a.set(5);
    B b;
    b.showA(a);
    return 0;
}













// A simple and complete C++ program to demonstrate friend function of another class 

#include <bits/stdc++.h>
using namespace std;

class B;

class A {
public:
    void showB(B&);
};

class B {
private:
    int b;

public:
    B() {
        b = 0;
    }
    void set(int x) {
        b = x;
    }
    // Friend function
    friend void A::showB(B& x);
};

void A::showB(B& x) {
    // Since showB() is friend of B, it can access private members of B
    std::cout << "B::b = " << x.b;
}

int main() {
    A a;
    B b;
    b.set(5);
    a.showB(b);
    return 0;
}












// A simple and complete C++ program to demonstrate global friend 

#include <bits/stdc++.h>
using namespace std;

class A {
    int a;

public:
    A() {
        a = 0;
    }
    void set(int x) {
        a = x;
    }

    // global friend function
    friend void showA(A&);
};

void showA(A& x) {
    // Since showA() is a friend, it can access private members of A
    std::cout << "A::a = " << x.a;
}

int main() {
    A a;
    a.set(5);
    showA(a);
    return 0;
}
