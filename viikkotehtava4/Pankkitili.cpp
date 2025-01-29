#include "Pankkitili.h"

Pankkitili::Pankkitili() : saldo(0.0) {}

bool Pankkitili::deposit(double amount) {
    if (amount <= 0) return false;
    saldo += amount;
    return true;
}

bool Pankkitili::withdraw(double amount) {
    if (amount <= 0 || amount > saldo) return false;
    saldo -= amount;
    return true;
}

double Pankkitili::getBalance() const {
    return saldo;
}
