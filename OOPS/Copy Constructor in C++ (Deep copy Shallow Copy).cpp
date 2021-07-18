// https://www.geeksforgeeks.org/copy-constructor-in-cpp/


// Following is a simple example of copy constructor. 

// Default Copy Constructor
#include<iostream>
using namespace std;

class Point {
private:
    int x, y;
public:
    Point(int x1, int y1) {
        x = x1;
        y = y1;
    }

    void setX(int _x) {
        x = _x;
    }
    void setY(int _y) {
        y = _y;
    }
    int getX() {
        return x;
    }
    int getY() {
        return y;
    }
};

int main() {
    Point p1(10, 15); // Normal constructor is called here
    Point p2 = p1; // Copy constructor is called here

    cout << "p1 {x, y} = {" << p1.getX() << ", " << p1.getY() << "}\n";
    cout << "p2 {x, y} = {" << p2.getX() << ", " << p2.getY() << "}\n";

    p2.setX(100);
    p2.setY(200);

    cout << "p1 {x, y} = {" << p1.getX() << ", " << p1.getY() << "}\n";
    cout << "p2 {x, y} = {" << p2.getX() << ", " << p2.getY() << "}\n";

    return 0;
}

/*
p1 {x, y} = {10, 15}
p2 {x, y} = {10, 15}
p1 {x, y} = {10, 15}
p2 {x, y} = {100, 200}
*/







// User-defined Copy Constructor
#include<iostream>
using namespace std;

class Point {
private:
    int x, y;
public:
    Point(int x1, int y1) {
        x = x1;
        y = y1;
    }

    // Copy constructor
    Point(const Point &p1) {
        x = p1.x;
        y = p1.y;
    }

    void setX(int _x) {
        x = _x;
    }
    void setY(int _y) {
        y = _y;
    }
    int getX() {
        return x;
    }
    int getY() {
        return y;
    }
};

int main() {
    Point p1(10, 15); // Normal constructor is called here
    Point p2 = p1; // Copy constructor is called here

    cout << "p1 {x, y} = {" << p1.getX() << ", " << p1.getY() << "}\n";
    cout << "p2 {x, y} = {" << p2.getX() << ", " << p2.getY() << "}\n";

    p2.setX(100);
    p2.setY(200);

    cout << "p1 {x, y} = {" << p1.getX() << ", " << p1.getY() << "}\n";
    cout << "p2 {x, y} = {" << p2.getX() << ", " << p2.getY() << "}\n";

    return 0;
}

/*
p1 {x, y} = {10, 15}
p2 {x, y} = {10, 15}
p1 {x, y} = {10, 15}
p2 {x, y} = {100, 200}
*/









/*
When is a user-defined copy constructor needed? 
If we don’t define our own copy constructor, the C++ compiler creates a default copy constructor for each class 
which does a member-wise copy between objects. The compiler created copy constructor works fine in general. 
We need to define our own copy constructor only if an object has pointers or any runtime allocation of the resource like filehandle, a network connection..etc.
The default constructor does only shallow copy. 

Deep copy is possible only with user defined copy constructor. 
In user defined copy constructor, we make sure that pointers (or references) of copied object point to new memory locations.
*/






/*
Write an example class where copy constructor is needed? 
Following is a complete C++ program to demonstrate use of Copy constructor. In the following String class, we must write copy constructor. 
*/

#include <bits/stdc++.h>
using namespace std;

class String {
private:
    char *s;
    int size;
public:
    // constructor
    String(const char *str = NULL) {
        size = strlen(str);
        s = new char[size + 1];
        strcpy(s, str);
    }
    // destructor
    ~String() {
        delete[] s;
    }
    // copy constructor
    String(const String& old_str) {
        size = old_str.size;
        s = new char[size + 1];
        strcpy(s, old_str.s);
    }
    // Function to change
    void change(const char *str) {
        delete [] s;
        size = strlen(str);
        s = new char[size + 1];
        strcpy(s, str);
    }
    void print() {
        cout << s << endl;
    }
};

int main() {
    String str1("GeeksQuiz");
    String str2 = str1;

    str1.print(); // what is printed ?
    str2.print();

    str2.change("GeeksforGeeks");

    str1.print(); // what is printed now ?
    str2.print();
    return 0;
}

/*
GeeksQuiz
GeeksQuiz
GeeksQuiz
GeeksforGeeks
*/










/*
What would be the problem if we remove copy constructor from above code? 
If we remove copy constructor from the above program, we don’t get the expected output. 
The changes made to str2 reflect in str1 as well which is never expected. 
*/

#include <bits/stdc++.h>
using namespace std;

class String {
private:
    char *s;
    int size;
public:
    // constructor
    String(const char *str) {
        size = strlen(str);
        s = new char[size + 1];
        strcpy(s, str);
    }
    // destructor
    ~String() {
        delete[] s;
    }
    // Function to change
    void change(const char *str) {
        delete [] s;
        size = strlen(str);
        s = new char[size + 1];
        strcpy(s, str);
    }
    void print() {
        cout << s << endl;
    }
};


int main() {
    String str1("GeeksQuiz");
    String str2 = str1;

    str1.print(); // what is printed ?
    str2.print();

    str2.change("GeeksforGeeks");

    str1.print(); // what is printed now ?
    str2.print();
    return 0;
}

/*
GeeksQuiz
GeeksQuiz
GeeksforGeeks
GeeksforGeeks
*/
