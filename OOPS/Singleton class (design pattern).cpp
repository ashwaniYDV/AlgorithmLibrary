// https://www.tutorialspoint.com/Explain-Cplusplus-Singleton-design-pattern
// sunny singleton class design pattern google doc

/*
Singleton design pattern is a software design principle that is used to restrict the instantiation of a class to one object. 
This is useful when exactly one object is needed to coordinate actions across the system. 
For example, if you are using a logger, that writes logs to a file, you can use a singleton class to create such a logger. 
You can create a singleton class using the following code −
*/

#include<bits/stdc++.h>
using namespace std;

class Singleton {
private:
    static Singleton *instance;
    int data;
 
   // Private constructor so that no objects can be created.
    Singleton() {
        data = 0;
    }

public:
    static Singleton *getInstance() {
        if (!instance) instance = new Singleton;
        return instance;
    }

    int getData() {
        return this -> data;
    }

    void setData(int data) {
        this -> data = data;
    }
};

//Initialize pointer to zero so that it can be initialized in first call to getInstance
Singleton *Singleton::instance = 0;

int main() {
   Singleton *s = s->getInstance();
   cout << s->getData() << endl;
   s->setData(100);
   cout << s->getData() << endl;

   Singleton *newS = newS->getInstance();
   cout << newS->getData() << endl;
   return 0;
}


/*
Output:
0
100
100
*/
