#include "Asiakas.h"
#include <iostream>

const double KORKOPROSENTTI = 0.05;

Asiakas::Asiakas(string nimi, double saldo) : nimi(nimi), saldo(saldo), luottoSaldo(0) {}

double Asiakas::getBalance() const {
    return saldo;
}

double Asiakas::getCreditBalance() const {
    return luottoSaldo;
}

bool Asiakas::talletus(double amount) {
    if (amount > 0) {
        saldo += amount;
        return true;
    }
    return false;
}

bool Asiakas::nosto(double amount) {
    if (amount > 0 && saldo >= amount) {
        saldo -= amount;
        return true;
    }
    return false;
}

bool Asiakas::luotonNosto(double amount) {
    if (amount > 0) {
        luottoSaldo += amount;
        saldo += amount;
        return true;
    }
    return false;
}

bool Asiakas::luotonMaksu(double amount) {
    double takaisinMaksettava = amount + (amount * KORKOPROSENTTI);
    if (takaisinMaksettava > 0 && saldo >= takaisinMaksettava && luottoSaldo >= amount) {
        saldo -= takaisinMaksettava;
        luottoSaldo -= amount;
        return true;
    }
    return false;
}

void Asiakas::tiliSiirto(double amount, Asiakas &vastaanottaja) {
    if (amount > 0 && saldo >= amount) {
        saldo -= amount;
        vastaanottaja.saldo += amount;
        cout << "Tilisiirto onnistui! " << nimi << " siirsi " << amount
                  << " euroa asiakkaalle " << vastaanottaja.nimi << "." << endl;
    } else {
        cout << "Tilisiirto epaonnistui!" << endl;
    }
}

void Asiakas::showSaldo() const {
    cout << "Asiakas: " << nimi << endl;
    cout << "Tavallinen saldo: " << saldo << " euroa." << endl;
    cout << "Luottosaldo: " << luottoSaldo << " euroa." << endl;
}
