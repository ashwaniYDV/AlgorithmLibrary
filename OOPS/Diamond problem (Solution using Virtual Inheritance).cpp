// https://youtu.be/7Zpuz4T4SGw

#include<bits/stdc++.h>
using namespace std;

class Animal {
public:
    int age;
    void walk() {
        cout << "Animal walks.\n";
    }
};

class Lion : public Animal {
};

class Tiger : public Animal {
};

class Liger : public Lion, public Tiger {
};

int main() {
    Liger ash;
    ash.walk();
    return 0;
}

// We get error - 
// error: request for member ‘walk’ is ambiguous


















// Solution using Virtual Inheritance
#include<bits/stdc++.h>
using namespace std;

class Animal {
public:
    int age;
    void walk() {
        cout << "Animal walks.\n";
    }
};

class Lion : virtual public Animal {
};

class Tiger : virtual public Animal {
};

class Liger : public Lion, public Tiger {
};

int main() {
    Liger ash;
    ash.walk();
    return 0;
}

/*
Output:
Animal walks.
*/












#include<bits/stdc++.h>
using namespace std;

class Animal {
public:
    int age;
    Animal() {
        cout << "Animal constructor.\n";
    }
    void walk() {
        cout << "Animal walks.\n";
    }
};

class Lion : virtual public Animal {
public:
    Lion() {
        cout << "Lion constructor.\n";
    }
};

class Tiger : virtual public Animal {
public:
    Tiger() {
        cout << "Tiger constructor.\n";
    }
};

class Liger : public Lion, public Tiger {
public:
    Liger() {
        cout << "Liger constructor.\n";
    }
};

int main() {
    Liger ash;
    ash.walk();
    return 0;
}

/*
Output:
Animal constructor.
Lion constructor.
Tiger constructor.
Liger constructor.
Animal walks.
*/




















#include<bits/stdc++.h>
using namespace std;

class Animal {
public:
    int age;
    Animal() {
        cout << "Animal constructor.\n";
    }
    void walk() {
        cout << "Animal walks.\n";
    }
};

class Lion : public Animal {
public:
    Lion() {
        cout << "Lion constructor.\n";
    }
};

class Tiger : public Animal {
public:
    Tiger() {
        cout << "Tiger constructor.\n";
    }
};

class Liger : public Lion, public Tiger {
public:
    Liger() {
        cout << "Liger constructor.\n";
    }
};

int main() {
    Liger ash;
    return 0;
}

/*
Output:
Animal constructor.
Lion constructor.
Animal constructor.
Tiger constructor.
Liger constructor.
*/
