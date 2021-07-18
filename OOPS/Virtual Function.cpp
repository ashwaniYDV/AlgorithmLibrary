// https://youtu.be/cUCy2ENJjW8
// https://youtu.be/Z_FiER8aAqM

/*
Notes:
1) Parent class pointer can point to any of its descendant class but not vice versa.
*/

#include <bits/stdc++.h>
using namespace std;

class Car {
public:
    Car() {

    }
    void shiftGear() {
        cout << "Car shift gear\n";
    }
};

class SportsCar: public Car {
public:
    SportsCar() {

    }
    void shiftGear() {
        cout << "Sports car shift gear\n";
    }
};


int main() {
    Car *ptr, maruti;
    SportsCar ferrari;

    // early binding
    maruti.shiftGear();
    
    // early binding
    ferrari.shiftGear();

    ptr = &ferrari;

    // early binding
    
    /*
    Function ke call ko dekhkar compiler uske sahi version ko bind karta hai by looking at its type
    (i.e. whether Car or SportsCar) aur isko early binding kehte hai.

    Thus function overriding ke case me child class wala shiftGear chal raha hai.
    Kyuki compiler ne ferrari ka type (SportsCar) dekh ke early binding kar di thi.

    Ab early binding tab bhi hogi jab aap pointer ke through shiftGear ko call kar rahe ho because ptr type is Car.

    Jab early binding hoti hai by compiler tab use ye nai maloom hota ki pointer me adress kiska hai.
    Isilie compiler shiftGear ke sahi version (whether Car or SportsCar) ko dhoodne ke lie
    ye nahi jaan paega ki ptr ke andar Car ka adress hai ya SportsCar ka adress hai kyuki compile time pe adresses nahi pata chalte. 
    Vo to jab memory allocate hogi runtime pe tab pata chalega.
    To compile time pe to pointer ka type hi compiler ko samajh aa sakta hai.

    Thus early binding karte waqt compiler pointer ke type ko dekhta hai.

    Function ko call agar object ke through kia ja raha hai to object ke type ko dekhte hai 
    and pointer ke through agar function ko call kia ja raha hai to pointer ke type ko dekhte hai.

    Isi wajah se parent class ka function chal jaega in case of pointer.
    */
    ptr->shiftGear();
}


/*
Car shift gear
Sports car shift gear
Car shift gear
*/











/*
The issue in above problem was that inspite of using adress of ferrari, maruti shiftGear ki called due to early binding.
But we want that if we are using adress of ferrari then ferrari shiftGear should be called.

Solution of above problem:
-------------------------------
Early binding ki jagah late binding (dynamic binding) ho. Runtime pe pointer ka content se decide krke late binding kia jae. 
Jab program execute ho rha hai tab shiftgear function ki binding ho.

Late binding karne ke lie compiler ko batane ke lie parent class me jo function hai uske pehle "virtual" keyword use kia jata hai.

Thus ek shiftGear parent class me hai and ek shiftGear child class me hai. 
And ye funcion overriding hi hai and funcion overriding ke case me hi aapko virtual keyword lagane ki zaroorat padegi.
*/

#include <bits/stdc++.h>
using namespace std;

class Car {
public:
    Car() {

    }
    virtual void shiftGear() {
        cout << "Car shift gear\n";
    }
};

class SportsCar: public Car {
public:
    SportsCar() {

    }
    void shiftGear() {
        cout << "Sports car shift gear\n";
    }
};


int main() {
    Car *ptr, maruti;
    SportsCar ferrari;

    maruti.shiftGear();
    
    ferrari.shiftGear();

    ptr = &ferrari;
    ptr->shiftGear();
}

/*
Car shift gear
Sports car shift gear
Sports car shift gear
*/






/*
Note:
Agar parent class me shiftGear ko virtual declare kar dia hai to child class ke shiftGear me aapko alag se virtual likhne ki zaroorat nahi hai.
shiftGear function child class me bhi virtual function hi hai.
Infact Car class ki kisi bhi descendant class me agar shiftGear function kisi prototype ke sath banaya jaega to vo virtual function hi mana jaega.
Ek class me kai virtual function ho sakte hai.
*/

// This code also works fine
#include <bits/stdc++.h>
using namespace std;

class Car {
public:
    Car() {

    }
    virtual void shiftGear() {
        cout << "Car shift gear\n";
    }
};

class SportsCar: public Car {
public:
    SportsCar() {

    }
    virtual void shiftGear() {
        cout << "Sports car shift gear\n";
    }
};


int main() {
    Car *ptr, maruti;
    SportsCar ferrari;

    maruti.shiftGear();
    
    ferrari.shiftGear();

    ptr = &ferrari;

    // late binding
    ptr->shiftGear();
}

/*
Car shift gear
Sports car shift gear
Sports car shift gear
*/
