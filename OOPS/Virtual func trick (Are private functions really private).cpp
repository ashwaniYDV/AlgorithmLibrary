// https://github.com/rachitiitr/DataStructures-Algorithms/blob/master/Tricks/tricky-oops-problem.cpp
// Checkout video at: https://youtu.be/TVKsaq7Bohs

// g++  5.4.0
// Are private functions really private? Well...

/*
Note: Base class pointer can point to the objet of derived class but not vice versa
*/

#include <bits/stdc++.h>
using namespace std;

class SocialWebsite{
public:
    virtual void secret() {
    }
};

class Facebook: public SocialWebsite{
private:
    string fbPassword;
    void secret() {
        cout << "The Facebook password is: " << fbPassword << endl;
        cout << "Its risky, but its fine to print here as it's a private function\n";
    }
public:
    Facebook(string pwd) {
        fbPassword = pwd;
    }
};

int main() {
    Facebook f("Rachit95@fb");
    
    SocialWebsite *ptr = &f;
    ptr->secret();
}

/*
The Facebook password is: Rachit95@fb
Its risky, but its fine to print here as it's a private function
*/
