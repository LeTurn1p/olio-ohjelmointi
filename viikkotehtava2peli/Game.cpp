#include "Game.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

Game::Game(int maxNum) : maxNumber(maxNum), numOfGuesses(0)
{
    srand(static_cast<unsigned>(time(nullptr)));
    randomNumber = rand() % maxNumber + 1;
    cout << "Raksaukko jorma: Rakensin pelin pelaajan antamalla arvolla " << maxNumber << ".\n";
}

Game::~Game()
{
    cout << "Bulldozer: jorman tekema alustus ja tyot tuhottu.\n";
}

void Game::play()
{
    int lowerBound = 1;
    int upperBound = maxNumber;

    cout << "DEBUG: Aloitetaan peli, pelaajan tulee arvata luku valilta " << lowerBound << " ja " << upperBound << ".\n";

    do {
        cout << "ApuriKeijo: Arvaappa poeka luku sheuraavaks valilta " << lowerBound << " - " << upperBound << ": ";
        cin >> playerGuess;
        numOfGuesses++;
        cout << "ApuriKeijo: Arvasit luvun " << playerGuess << "\n";

        if (playerGuess < lowerBound || playerGuess > upperBound)
        {
            cout << "ApuriKeijo: Arvaukshen tulleepi olla valilta " << lowerBound << " ja " << upperBound << ". Yrita uudelleen.\n";
            continue;
        }

        if (playerGuess < randomNumber)
        {
            cout << "Lukusi on suurempi.\n";
            lowerBound = playerGuess + 1;
        }
        else if (playerGuess > randomNumber)
        {
            cout << "Lukusi on pienempi.\n";
            upperBound = playerGuess - 1;
        }
        else
        {
            cout << "Esimies Antti: Voitit pelin! Oikea vastaus oli " << randomNumber << ".\n";
            break;
        }
    } while (true);
}

void Game::printGameResult() const
{
    cout << "DEBUG: Peli on paattynyt. Arvauksia tehtiin: " << numOfGuesses << "\n";
    cout << "Luku oli " << randomNumber << ", ja arvasit oikein " << numOfGuesses << " yrityksella.\n";
}
