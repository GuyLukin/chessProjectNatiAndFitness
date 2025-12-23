#include "turnHandler.h"
/*a constructor
*/
TurnHandler::TurnHandler()	: _turn(0), _numOfTurn(1), _firstPlayerColor("WHITE")
{
}
/*a function that handels the turn switch
* input:none
* output:the turn switched
*/
void TurnHandler::moveTurn()
{
	_turn = (_turn + 1) % 2; //first player starts at 0 second player at 1
	_numOfTurn++;
}
/*returns whose turn it is
* input:none
* output:whose turn it is
*/
int TurnHandler::turnGetter() const
{
	return _turn;
}
/*function that returns the number of the turn that is played at the moment
* input:none
* output:the turn
*/
int TurnHandler::numOfTurnGetter() const
{
	return _numOfTurn;
}
