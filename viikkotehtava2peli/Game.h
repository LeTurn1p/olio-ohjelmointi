#ifndef GAME_H
#define GAME_H

class Game {
private:
    int maxNumber;
    int playerGuess;
    int randomNumber;
    int numOfGuesses;

public:
    Game(int maxNum);   // pelin oma raksamies eli rakentaja
    ~Game();            // pelin bulldoser eli tuhoaja
    void play();        // pelaamisfunktio
    void printGameResult() const;  // printtitulos :D
};

#endif
