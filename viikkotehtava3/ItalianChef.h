#ifndef ITALIANCHEF_H
#define ITALIANCHEF_H

#include "Chef.h"
using namespace std;

class ItalianChef : public Chef {
private:
    string password;
    int flour;
    int water;

    int makePizza(int flour, int water);

public:
    ItalianChef(const string& name, int flour, int water);
    ~ItalianChef();

    bool askSecret(const string& inputPassword, int flour, int water);
};

#endif // ITALIANCHEF_H
