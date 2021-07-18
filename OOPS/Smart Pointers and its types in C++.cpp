// https://www.geeksforgeeks.org/smart-pointers-cpp/
// https://youtu.be/UOB7-B2MfwA


/*
Types of Smart Pointers
1. unique_ptr
2. shared_ptr
3. weak_ptr 
*/


#include <bits/stdc++.h>
using namespace std;

class Entity {
public:
    Entity() {
        cout << "Constructor\n";
    }
    ~Entity() {
        cout << "Destructor\n";
    }
};

int main() {
    unique_ptr<Entity> pUnique0 = make_unique<Entity>();
    // we cannot copy it (below line will throw an error)
    // unique_ptr<Entity> pUnique1 = pUnique0;
}

/*
Constructor
Destructor
*/








#include <bits/stdc++.h>
using namespace std;

class Entity {
public:
    Entity() {
        cout << "Constructor\n";
    }
    ~Entity() {
        cout << "Destructor\n";
    }
};

int main() {
    shared_ptr<Entity> pShared0 = make_shared<Entity>();
    shared_ptr<Entity> pShared1 = pShared0;
    cout << pShared0.use_count() << endl;
}

/*
Constructor
2
Destructor
*/








#include <bits/stdc++.h>
using namespace std;

class Entity {
public:
    Entity() {
        cout << "Constructor\n";
    }
    ~Entity() {
        cout << "Destructor\n";
    }
};

int main() {
    shared_ptr<Entity> pShared0 = make_shared<Entity>();
    weak_ptr<Entity> pWeak1 = pShared0;
    cout << pShared0.use_count() << endl;
}

/*
Constructor
1
Destructor
*/

















#include <iostream>
using namespace std;

class SmartPtr {
    // Actual pointer
    int* ptr;
public:
    // Refer https:// www.geeksforgeeks.org/g-fact-93/
    // for use of explicit keyword
    explicit SmartPtr(int* p = NULL) {
        ptr = p;
    }

    // Destructor
    ~SmartPtr() {
        delete (ptr);
    }

    // Overloading dereferencing operator
    int& operator*() {
        return *ptr;
    }
};

int main() {
    SmartPtr ptr(new int());
    *ptr = 20;
    cout << *ptr;

    // We don't need to call delete ptr:
    // when the object ptr goes out of scope, the destructor for it is automatically called
    // and destructor does delete ptr.
    return 0;
}






#include <iostream>
using namespace std;

// A generic smart pointer class
template <typename T>
class SmartPtr {
    // Actual pointer
    T* ptr;
public:
    explicit SmartPtr(T* p = NULL) {
        ptr = p;
    }

    ~SmartPtr() {
        delete (ptr);
    }

    // Overloading dereferncing operator
    T& operator*() {
        return *ptr;
    }

    // Overloading arrow operator so that members of T can be accessed like a pointer
    // (useful if T represents a class or struct or union type)
    T* operator->() {
        return ptr;
    }
};

int main() {
    SmartPtr<int> ptr(new int());
    *ptr = 20;
    cout << *ptr;
    return 0;
}






#include <iostream>
using namespace std;

class Entity {
public:
    Entity() {
        cout << "Constructor\n";
    }
    ~Entity() {
        cout << "Destructor\n";
    }
    void fun() {
        cout << "Fun called\n";
    }
};

// A generic smart pointer class
template <typename T>
class SmartPtr {
    // Actual pointer
    T* ptr;
public:
    explicit SmartPtr(T* p = NULL) {
        ptr = p;
    }

    ~SmartPtr() {
        delete (ptr);
    }

    // Overloading dereferncing operator
    T& operator*() {
        return *ptr;
    }

    // Overloading arrow operator so that members of T can be accessed like a pointer
    // (useful if T represents a class or struct or union type)
    T* operator->() {
        return ptr;
    }
};

int main() {
    SmartPtr<Entity> ptr(new Entity());
    ptr->fun();
    return 0;
}
