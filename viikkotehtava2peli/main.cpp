#include "Game.h"
#include <iostream>
using namespace std;

int main() {
    char choice;

    do {
        int maxnum;
        cout << "Esimies Antti: Anna suurin luku, jota haluat arvailla: ";
        cin >> maxnum;

        if (maxnum < 1) {
            cout << "Esimies Antti: Suurimman luvun tulee olla vahintaan 1.\n";
            return 1;
        }

        Game game(maxnum);
        game.play();
        game.printGameResult();

        cout << "Esimies Antti: Haluatko pelata uudelleen? (Y/N): ";
        cin >> choice;

    } while (choice == 'Y' || choice == 'y');

    cout << "Esimies Antti: Kiitos pelaamisesta!\n";
    return 0;
}
