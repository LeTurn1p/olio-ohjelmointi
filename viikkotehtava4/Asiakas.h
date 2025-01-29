#ifndef ASIAKAS_H
#define ASIAKAS_H

#include <string>
using namespace std;

class Asiakas {
private:
    string nimi;
    double saldo;
    double luottoSaldo;

public:
    Asiakas(string nimi, double saldo);

    double getBalance() const;
    double getCreditBalance() const;

    bool talletus(double amount);
    bool nosto(double amount);

    bool luotonNosto(double amount);
    bool luotonMaksu(double amount);

    void tiliSiirto(double amount, Asiakas &vastaanottaja);
    void showSaldo() const;
};

#endif
