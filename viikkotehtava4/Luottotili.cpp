#include "Luottotili.h"

Luottotili::Luottotili(double raja) : luottoraja(raja) {}

bool Luottotili::withdraw(double amount) {
    if (amount <= 0 || (saldo - amount) < -luottoraja) return false;
    saldo -= amount;
    return true;
}

bool Luottotili::payCredit(double amount) {
    if (amount <= 0 || saldo + amount > 0) return false;
    saldo += amount;
    return true;
}
