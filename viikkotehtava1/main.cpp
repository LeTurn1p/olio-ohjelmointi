#include <iostream>

using namespace std;
int game(int max);

int main()
{
    int maximi;
    cout << "anna maximi luku: ";
    cin >> maximi;
    int arvausmaara = game(maximi);
    cout << "arvasit " << arvausmaara << " kertaa" << endl;
}
int game(int max)
{
    srand(static_cast<unsigned int>(time(0)));
    int luku = rand()%max+1;
    int arvaus;
    int arvaukset = 0;
    cout << "arvaa: ";
    cin >> arvaus;

    while(1)
    {
        if(arvaus == luku)
        {
            cout << "oikein meni" << endl;
            break;
        }
        else if(arvaus < luku)
        {
            cout << "liian pieni" << endl;
            cout << "yrita uudellee: ";
            cin >> arvaus;
        }
        else if(arvaus > luku)
        {
            cout << "liian suuri" << endl;
              cout << "yrita uudellee: ";
            cin >> arvaus;
        }
        arvaukset++;
    }

    return arvaukset;
}
