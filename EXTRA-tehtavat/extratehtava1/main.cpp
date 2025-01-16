#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Pankkitili {
private:
    string tilinumero;
    string tilinomistaja;
    double saldo;

public:
    Pankkitili(const string& tilinumero, const string& tilinomistaja, double saldo)
        : tilinumero(tilinumero), tilinomistaja(tilinomistaja), saldo(saldo) {}

    void talleta(double maara) {
        saldo += maara;
        cout << "Talletettu " << maara << " euroa tilille " << tilinumero << "." << endl;
    }

    bool nosta(double maara) {
        if (maara > saldo) {
            cout << "Virhe: Saldo ei riitä nostoon!" << endl;
            return false;
        } else {
            saldo -= maara;
            cout << "Nostettu " << maara << " euroa tililta " << tilinumero << "." << endl;
            return true;
        }
    }

    void tulostaTilitiedot() const {
        cout << "Tilinumero: " << tilinumero << endl;
        cout << "Tilinomistaja: " << tilinomistaja << endl;
        cout << "Saldo: " << saldo << " euroa" << endl;
    }

    string getTilinumero() const {
        return tilinumero;
    }

    double getSaldo() const {
        return saldo;
    }

    bool siirra(Pankkitili& toinenTili, double maara) {
        if (nosta(maara)) {
            toinenTili.talleta(maara);
            cout << "Siirretty " << maara << " euroa tililta " << tilinumero
                 << " tilille " << toinenTili.getTilinumero() << "." << endl;
            return true;
        }
        return false;
    }
};

int main() {
    vector<Pankkitili> tilit;
    int tiliLkm;
    cout << "Kuinka monta pankkitilia haluat luoda? ";
    cin >> tiliLkm;

    for (int i = 0; i < tiliLkm; i++) {
        string tilinumero, tilinomistaja;
        double saldo;

        cout << "\nAnna tiedot tilille " << i + 1 << ":" << endl;
        cout << "Tilinumero: ";
        cin >> tilinumero;
        cout << "Tilinomistaja: ";
        cin.ignore();  // Tyhjentää syötteen
        getline(cin, tilinomistaja);
        cout << "Alkusaldo: ";
        cin >> saldo;

        tilit.emplace_back(tilinumero, tilinomistaja, saldo);
    }

    for (const auto& tili : tilit) {
        cout << "\nTilitiedot:\n";
        tili.tulostaTilitiedot();
    }

    int valinta;
    do {
        cout << "\nValitse toiminto:\n";
        cout << "1 - Talleta rahaa\n2 - Nosta rahaa\n3 - Siirra rahaa\n0 - Lopeta\n";
        cin >> valinta;

        if (valinta == 1) {
            int tiliIdx;
            double maara;
            cout << "Syota talletuksen kohdetilin numero (1-" << tiliLkm << "): ";
            cin >> tiliIdx;
            cout << "Syota talletettava summa: ";
            cin >> maara;
            if (tiliIdx >= 1 && tiliIdx <= tiliLkm) {
                tilit[tiliIdx - 1].talleta(maara);
            } else {
                cout << "Virheellinen tilinumero!" << endl;
            }
        } else if (valinta == 2) {
            int tiliIdx;
            double maara;
            cout << "Syota noston kohdetilin numero (1-" << tiliLkm << "): ";
            cin >> tiliIdx;
            cout << "Syota nostettava summa: ";
            cin >> maara;
            if (tiliIdx >= 1 && tiliIdx <= tiliLkm) {
                tilit[tiliIdx - 1].nosta(maara);
            } else {
                cout << "Virheellinen tilinumero!" << endl;
            }
        } else if (valinta == 3) {
            int lahettajaIdx, vastaanottajaIdx;
            double maara;
            cout << "Syota siirron lähettävän tilin numero (1-" << tiliLkm << "): ";
            cin >> lahettajaIdx;
            cout << "Syota siirron vastaanottavan tilin numero (1-" << tiliLkm << "): ";
            cin >> vastaanottajaIdx;
            cout << "Syota siirrettävä summa: ";
            cin >> maara;
            if (lahettajaIdx >= 1 && lahettajaIdx <= tiliLkm &&
                vastaanottajaIdx >= 1 && vastaanottajaIdx <= tiliLkm) {
                tilit[lahettajaIdx - 1].siirra(tilit[vastaanottajaIdx - 1], maara);
            } else {
                cout << "Virheellinen tilinumero!" << endl;
            }
        }
    } while (valinta != 0);

    cout << "\nLopulliset tilitiedot:\n";
    for (const auto& tili : tilit) {
        tili.tulostaTilitiedot();
    }

    return 0;
}
