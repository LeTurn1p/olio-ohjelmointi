/* #include "Chef.h"
#include "ItalianChef.h"

int main() {
    // tama luo tavallisen kokin
    Chef chefGordon("Gordon");
    chefGordon.makeSalad(11);
    chefGordon.makeSoup(14);

    // tama luo italialaisen kokin
    ItalianChef chefMario("Mario", 12, 12);
    chefMario.askSecret("pizza", 12, 12);

    return 0;
}
*/
#include "Chef.h"
#include "ItalianChef.h"
#include <iostream>
#include <string>
using namespace std;

int main() {
    // Tavallinen kokki
    string chefName;
    cout << "Anna tavallisen kokin nimi: ";
    cin >> chefName;

    Chef chef(chefName);

    int saladItems, soupItems;
    cout << "Anna raaka-aineiden maara salaatille: ";
    cin >> saladItems;
    chef.makeSalad(saladItems);

    cout << "Anna raaka-aineiden maara keitolle: ";
    cin >> soupItems;
    chef.makeSoup(soupItems);

    // Italialainen kokki
    string italianChefName, passwordInput;
    int flour, water;

    cout << "\nAnna italialaisen kokin nimi: ";
    cin >> italianChefName;

    cout << "Anna jauhojen maara: ";
    cin >> flour;

    cout << "Anna veden maara: ";
    cin >> water;

    ItalianChef italianChef(italianChefName, flour, water);

    cout << "Syota salasana pizzan valmistamiseen: ";
    cin >> passwordInput;

    italianChef.askSecret(passwordInput, flour, water);

    return 0;
}
