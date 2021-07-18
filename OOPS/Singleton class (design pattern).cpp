// https://www.tutorialspoint.com/Explain-Cplusplus-Singleton-design-pattern
// sunny singleton class design pattern google doc
// https://youtu.be/OlHJ-uhEoKM

/*
Singleton design pattern is a software design principle that is used to restrict the instantiation of a class to one object. 
This is useful when exactly one object is needed to coordinate actions across the system. 
For example, if you are using a logger, that writes logs to a file, you can use a singleton class to create such a logger. 
You can create a singleton class using the following code −
*/


/*
Private Constructor allows us to create objects of that class only inside the class. 
So outside any class we cant create object of that class.
This type of constructor is used in Singleton class. 
In which the class variable is created only inside a class or inside a public member function of that class. 
So that if we want to access a member of a class using that public member function we can access it.
*/


#include<bits/stdc++.h>
using namespace std;

class Singleton {
private:
    static Singleton *instance;
    int data;

    Singleton() {
        data = 0;
        cout << "Private Constructor called.\n";
    }

public:
    // Static method to create instance of Singleton class
    static Singleton *getInstance() {
        if (!instance) instance = new Singleton;
        return instance;
    }

    void setData(int data) {
        this -> data = data;
    }

    int getData() {
        return this -> data;
    }
};

// Initialize pointer to NULL so that it can be initialized in first call to getInstance
Singleton* Singleton::instance = NULL;

int main() {
    Singleton *s;
    s = s->getInstance();
    cout << s->getData() << endl;
    s->setData(100);
    cout << s->getData() << endl;

    Singleton *newS = newS->getInstance();
    newS->setData(200);
    cout << newS->getData() << endl;
    cout << s->getData() << endl;
    return 0;
}

// Note that constructor is called only once.

/*
Output:
Private Constructor called.
0
100
200
200
*/
















#include<bits/stdc++.h>
using namespace std;

class SingletonClass {
private:
    static SingletonClass *instance;
    SingletonClass() {
        cout << "Private Constructor\n";
    }
public:
    int id = 5;
    SingletonClass* getInstance() {
        if (!instance) instance = new SingletonClass;
        return instance;
    }
};

SingletonClass* SingletonClass::instance = NULL;

int main() {
    SingletonClass *obj;
    obj = obj->getInstance();
    cout << obj->id << endl;
}
