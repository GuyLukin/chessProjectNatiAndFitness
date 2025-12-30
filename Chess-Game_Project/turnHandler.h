#pragma once
#include <string>

class TurnHandler 
{
private:
    static int _turn;
    std::string _firstPlayerColor;
    int _numOfTurn;

public:
    void setTurn(int turn);
    void moveTurn();
    static std::string turnGetter();
    int numOfTurnGetter();
};
