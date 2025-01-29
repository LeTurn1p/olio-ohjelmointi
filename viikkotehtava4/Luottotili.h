#ifndef LUOTTOTILI_H
#define LUOTTOTILI_H

#include "Pankkitili.h"

class Luottotili : public Pankkitili {
private:
    double luottoraja;
public:
    Luottotili(double raja);
    bool withdraw(double amount) override;
    bool payCredit(double amount);
};

#endif // LUOTTOTILI_H
