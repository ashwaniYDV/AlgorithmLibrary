#include <bits/stdc++.h>
using namespace std;

class ash {
private:
    ash *instance;
    ash() {
        cout << "Private Constructor\n";
    }
public:
    int id = 5;
    ash* getInstance() {
        ash* temp_instance = new ash;
        return temp_instance;
    }    
};
 
int main() {
   ash *as;
   as = as->getInstance();
   cout << as->id << endl;
}








// Singleton class
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
        if(!instance) instance = new SingletonClass;
        return instance;
    }    
};

SingletonClass *SingletonClass::instance = NULL;
 
int main() {
   SingletonClass *obj;
   obj = obj->getInstance();
   cout << obj->id << endl;
}
