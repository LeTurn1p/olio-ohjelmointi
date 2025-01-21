#include "ItalianChef.h"
#include <iostream>
#include <algorithm>
using namespace std;

ItalianChef::ItalianChef(const string& name, int flour, int water) : Chef(name), password("pizza"), flour(flour), water(water) {
}

ItalianChef::~ItalianChef() {
}

int ItalianChef::makePizza(int flour, int water) {
    int pizzas = min(flour / 5, water / 5);
    cout << "Chef " << chefName << " can make " << pizzas << " pizzas with given " << water << " water and " << flour << " flour's\n";
    return pizzas;
}

bool ItalianChef::askSecret(const string& inputPassword, int flour, int water) {
    if (inputPassword == password) {
        cout << "Password ok!\n";
        makePizza(flour, water);
        return true;
    } else {
        cout << "Wrong password!\n"<<"you don't get anymore food\n";
        return false;
    }
}
