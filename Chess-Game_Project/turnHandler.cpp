#include "turnHandler.h"
/*a constructor
*/
/*a function that handels the turn switch
* input:none
* output:the turn switched
*/
int TurnHandler::_turn = 0;

void TurnHandler::moveTurn()
{
	_turn = (_turn + 1) % 2; //first player starts at 0 second player at 1
	_numOfTurn++;
}
/*returns whose turn it is
* input:none
* output:whose turn it is
*/
std::string TurnHandler::turnGetter()
{
    std::string strTurn = "WHITE";
    if (_turn == 1)
    {
        strTurn = "BLACK";
    }
    return strTurn;
}
/*function that returns the number of the turn that is played at the moment
* input:none
* output:the turn
*/
int TurnHandler::numOfTurnGetter()
{
    return _numOfTurn;
}

void TurnHandler::setTurn(int turn)
{
    _turn = turn;
}