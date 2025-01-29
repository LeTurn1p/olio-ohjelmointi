#include "Asiakas.h"
#include <iostream>

void naytaValikko() {
    cout << "\nValitse toiminto:" << endl;
    cout << "1 - Talletus" << endl;
    cout << "2 - Nosto" << endl;
    cout << "3 - Luoton nosto" << endl;
    cout << "4 - Luoton maksu" << endl;
    cout << "5 - Tilisiirto" << endl;
    cout << "6 - Valitse asiakas" << endl;
    cout << "7 - Nayta saldot" << endl;
    cout << "0 - Lopeta" << endl;
}

int main() {
    Asiakas asiakas1("Matti Meikalainen", 500.0);
    Asiakas asiakas2("Teppo Testaaja", 300.0);
    Asiakas* aktiivinenAsiakas = &asiakas1;

    int valinta;
    double summa;
    do {
        naytaValikko();
        cout << "Syota valintasi: ";
        cin >> valinta;

        switch (valinta) {
        case 1:
            cout << "Syota talletettava summa: ";
            cin >> summa;
            if (aktiivinenAsiakas->talletus(summa)) {
                cout << "Talletus onnistui. Uusi saldo: " << aktiivinenAsiakas->getBalance() << " euroa." << endl;
            } else {
                cout << "Talletus epaonnistui." << endl;
            }
            break;
        case 2:
            cout << "Syota nostettava summa: ";
            cin >> summa;
            if (aktiivinenAsiakas->nosto(summa)) {
                cout << "Nosto onnistui. Uusi saldo: " << aktiivinenAsiakas->getBalance() << " euroa." << endl;
            } else {
                cout << "Nosto epaonnistui." << endl;
            }
            break;
        case 3:
            cout << "Syota nostettava luottosumma: ";
            cin >> summa;
            if (aktiivinenAsiakas->luotonNosto(summa)) {
                cout << "Luoton nosto onnistui. Luottosaldo: " << aktiivinenAsiakas->getCreditBalance() << " euroa." << endl;
            } else {
                cout << "Luoton nosto epaonnistui." << endl;
            }
            break;
        case 4:
            cout << "Syota maksettava luoton summa: ";
            cin >> summa;
            if (aktiivinenAsiakas->luotonMaksu(summa)) {
                cout << "Luoton maksu onnistui. Uusi luottosaldo: " << aktiivinenAsiakas->getCreditBalance() << " euroa." << endl;
            } else {
                cout << "Luoton maksu epaonnistui." << endl;
            }
            break;
        case 5:
            cout << "Syota siirrettava summa: ";
            cin >> summa;
            cout << "Valitse vastaanottaja (1 - Matti, 2 - Teppo): ";
            int vastaanottajaValinta;
            cin >> vastaanottajaValinta;
            if (vastaanottajaValinta == 1) {
                aktiivinenAsiakas->tiliSiirto(summa, asiakas1);
            } else if (vastaanottajaValinta == 2) {
                aktiivinenAsiakas->tiliSiirto(summa, asiakas2);
            } else {
                cout << "Virheellinen valinta!" << endl;
            }
            break;
        case 6:
            cout << "Valitse asiakas (1 - Matti, 2 - Teppo): ";
            int asiakasValinta;
            cin >> asiakasValinta;
            if (asiakasValinta == 1) {
                aktiivinenAsiakas = &asiakas1;
            } else if (asiakasValinta == 2) {
                aktiivinenAsiakas = &asiakas2;
            } else {
                cout << "Virheellinen valinta!" << endl;
            }
            break;
        case 7:
            asiakas1.showSaldo();
            asiakas2.showSaldo();
            break;
        case 0:
            cout << "Ohjelma lopetetaan." << endl;
            break;
        default:
            cout << "Virheellinen valinta!" << endl;
        }
    } while (valinta != 0);

    return 0;
}
