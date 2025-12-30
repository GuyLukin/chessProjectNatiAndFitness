/*
This file servers as an example of how to use Pipe.h file.
It is recommended to use the following code in your project,
in order to read and write information from and to the Backend
*/

#include "Pipe.h"
#include "rook.h"
#include "bishop.h"
#include "queen.h"
#include "king.h"
#include "pawn.h"
#include "piece.h"
#include "knight.h"
#include <iostream>
#include <thread>
#include <stdlib.h>
#include <string.h>
#include <chrono>
#include "board.h"
#include "turnHandler.h"

using std::cout;
using std::endl;
using std::string;

int main()
{
	srand(time_t(NULL));
	Board board;
	Pipe p;
	TurnHandler turnSetter;
	bool isFirstRound = true;
	std::string moveCode = "";
	bool isConnect = p.connect();
	Point sourcePoint;
	Point destPoint;
	string ans;
	while (!isConnect)
	{
		cout << "cant connect to graphics" << endl;
		cout << "Do you try to connect again or exit? (0-try again, 1-exit)" << endl;
		std::cin >> ans;

		if (ans == "0")
		{
			cout << "trying connect again.." << endl;
			std::this_thread::sleep_for(std::chrono::milliseconds(5000));
			isConnect = p.connect();
		}
		else
		{
			p.close();
			return 0;
		}
	}


	char msgToGraphics[1024];
	// msgToGraphics should contain the board string accord the protocol
	// YOUR CODE

	strcpy_s(msgToGraphics, "rnbqkbnrpppppppp################################PPPPPPPPRNBQKBNR0"); // just example...

	p.sendMessageToGraphics(msgToGraphics);   // send the board string

	// get message from graphics
	string msgFromGraphics = p.getMessageFromGraphics();
	while (msgFromGraphics != "quit")
	{
		cout << msgFromGraphics << endl;
		// should handle the string the sent from graphics
		// according the protocol. Ex: e2e4           (move e2 to e4)
		//msgToGraphics
		// YOUR CODE
		if (msgFromGraphics.size() >= 4 &&
			msgFromGraphics[0] >= 'a' && msgFromGraphics[0] <= 'h' &&
			msgFromGraphics[1] >= '1' && msgFromGraphics[1] <= '8' &&
			msgFromGraphics[2] >= 'a' && msgFromGraphics[2] <= 'h' &&
			msgFromGraphics[3] >= '1' && msgFromGraphics[3] <= '8')
		{
			sourcePoint.setX(msgFromGraphics[0] - 'a');
			sourcePoint.setY(msgFromGraphics[1] - '1');   // rank -> 0..7
			destPoint.setX(msgFromGraphics[2] - 'a');
			destPoint.setY(msgFromGraphics[3] - '1');
		}
		if (isFirstRound)
		{
			if (board.getPieceAt(sourcePoint)->getColor() == "WHITE")
			{
				turnSetter.setTurn(0);
			}
			else
			{
				turnSetter.setTurn(1);
			}
		}
		moveCode = board.getPieceAt(sourcePoint)->chooseMoveCode(board, destPoint);
		strcpy_s(msgToGraphics, sizeof(msgToGraphics), moveCode.c_str());
		if (moveCode == "1" || moveCode == "0")
		{
			turnSetter.moveTurn();
		}
		// msgToGraphics should contain the result of the operation
		/*a
		int r = rand() % 10; // just for debugging......
		msgToGraphics[0] = (char)(1 + '0');
		msgToGraphics[1] = 0;
		*/

		// return result to graphics		
		p.sendMessageToGraphics(msgToGraphics);

		// get message from graphics
		msgFromGraphics = p.getMessageFromGraphics();
	}
	p.close();
	return 1;
}
// Correct function declaration and stub implementation