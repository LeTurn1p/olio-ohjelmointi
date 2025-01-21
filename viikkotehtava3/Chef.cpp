#include "Chef.h"
#include <iostream>
using namespace std;

Chef::Chef(const string& name) : chefName(name) {
    cout << "Chef " << chefName << " konstruktori\n";
}

Chef::~Chef() {
    cout << "Chef " << chefName << " destruktori\n";
}

string Chef::getName() const {
    return chefName;
}

int Chef::makeSalad(int items) {
    int portions = items / 5;
    cout << "Chef " << chefName << " can make " << portions << " portions of salads with given " << items << " ingredient's\n";
    return portions;
}

int Chef::makeSoup(int items) {
    int portions = items / 3;
    cout << "Chef " << chefName << " can make " << portions << " portions of soups with given " << items << " ingredient's\n";
    return portions;
}
