#ifndef CHEF_H
#define CHEF_H

#include <string>
using namespace std;

class Chef {
protected:
    string chefName;

public:
    Chef(const string& name);
    virtual ~Chef();

    string getName() const;
    int makeSalad(int items);
    int makeSoup(int items);
};

#endif // CHEF_H
