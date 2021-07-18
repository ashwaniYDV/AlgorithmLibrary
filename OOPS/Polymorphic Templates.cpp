// https://youtu.be/q_LUYLV3l44

#include <bits/stdc++.h>
using namespace std;

// abstract class
class Pizza {
public:
    virtual void MakePizza() = 0;
};

class NYStyleCrust {
public:
    string AddIngredients() {
        return "Crust so thin you can see through it!\n\n";
    }
};

class DeepDishCrust {
public:
    string AddIngredients() {
        return "Super awesome Chicago Deep Dish!\n\n";
    }
};

template<typename T>
class Meat: public T {
public:
    string AddIngredients() {
        return "Lots of Random Meat, " + T::AddIngredients();
    }
};

template<typename T>
class Vegan: public T {
public:
    string AddIngredients() {
        return "Lots of Veggies Cheese, " + T::AddIngredients();
    }
};

template<typename T>
class MeatNYStyle: public T, public Pizza {
public:
    void MakePizza() {
        cout << "Meat NY Style Pizza : " << T::AddIngredients();
    }
};

template<typename T>
class VeganDeepDish: public T, public Pizza {
public:
    void MakePizza() {
        cout << "Vegan Deep Dish Pizza : " << T::AddIngredients();
    }
};


int main() {
    vector<unique_ptr<Pizza>> pizzaOrders;
    pizzaOrders.emplace_back(new MeatNYStyle<Meat<NYStyleCrust>>());
    pizzaOrders.emplace_back(new VeganDeepDish<Vegan<DeepDishCrust>>());

    for (auto &pizza : pizzaOrders) {
        pizza->MakePizza();
    }

    return 0;
}


/*
Meat NY Style Pizza : Lots of Random Meat, Crust so thin you can see through it!

Vegan Deep Dish Pizza : Lots of Veggies Cheese, Super awesome Chicago Deep Dish!
*/
