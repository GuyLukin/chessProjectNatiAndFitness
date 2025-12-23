#pragma once
#include <string>

class TurnHandler 
{
private:
    int _turn;
    std::string _firstPlayerColor;
    int _numOfTurn;

public:
    TurnHandler();
    void moveTurn();
    int turnGetter() const;
    int numOfTurnGetter() const;
};
