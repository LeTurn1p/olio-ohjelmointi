#include <iostream>
#include <string>
using namespace std;

class Seuraaja {
public:
    string nimi;
    Seuraaja* next;

    Seuraaja(string n) : nimi(n), next(nullptr) {}

    void paivitys(const string& viesti) {
        cout << nimi << " Vastaanotti viestin: " << viesti << endl;
    }

    string getNimi() {
        return nimi;
    }
};

class Notifikaattori {
private:
    Seuraaja* seuraajat;

public:
    Notifikaattori() : seuraajat(nullptr) {}

    void lisaa(string nimi) {
        Seuraaja* uusi = new Seuraaja(nimi);
        uusi->next = seuraajat;
        seuraajat = uusi;
    }

    void poista(string nimi) {
        Seuraaja* nykyinen = seuraajat;
        Seuraaja* edellinen = nullptr;

        while (nykyinen != nullptr && nykyinen->getNimi() != nimi) {
            edellinen = nykyinen;
            nykyinen = nykyinen->next;
        }

        if (nykyinen != nullptr) {
            if (edellinen == nullptr) {
                seuraajat = nykyinen->next;
            } else {
                edellinen->next = nykyinen->next;
            }
            delete nykyinen;
        }
    }

    void tulosta() {
        Seuraaja* nykyinen = seuraajat;
        while (nykyinen != nullptr) {
            cout << nykyinen->getNimi() << endl;
            nykyinen = nykyinen->next;
        }
    }

    void postita(string viesti) {
        Seuraaja* nykyinen = seuraajat;
        while (nykyinen != nullptr) {
            nykyinen->paivitys(viesti);
            nykyinen = nykyinen->next;
        }
    }

    ~Notifikaattori() {
        while (seuraajat != nullptr) {
            Seuraaja* poistettava = seuraajat;
            seuraajat = seuraajat->next;
            delete poistettava;
        }
    }
};

int main() {
    Notifikaattori n;
    n.lisaa("Liisa");
    n.lisaa("Tuomo");
    n.lisaa("Kari");

    cout << "Seuraajat:\n";
    n.tulosta();

    cout << "\nLahetetaan viesti:\n";
    n.postita("Tama on testiviesti!");

    cout << "\nPoistetaan Tuomo...\n";
    n.poista("Tuomo");

    cout << "\nSeuraajat jaljella:\n";
    n.tulosta();

    return 0;
}
