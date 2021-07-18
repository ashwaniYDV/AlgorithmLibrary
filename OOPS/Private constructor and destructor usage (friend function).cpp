// https://www.geeksforgeeks.org/private-destructor/

#include<bits/stdc++.h>
using namespace std;


class Ash {
private:
    Ash() {
        cout << "Private Constructor\n";
    }
    ~Ash() {
        cout << "Private Destructor\n";
    }
public:
    int id = 5;
    Ash* getInstance() {
        Ash *tempInstance = new Ash;
        return tempInstance;
    }
    friend void fun(Ash*);
};

void fun(Ash *a) {
    delete a;
}
 
int main() {
   Ash *obj;
   obj = obj->getInstance();
   cout << obj->id << endl;
   fun(obj);
}


/*
Private Constructor
5
Private Destructor
*/
