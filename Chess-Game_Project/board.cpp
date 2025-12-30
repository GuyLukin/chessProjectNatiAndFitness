#include "Board.h"
#include "Pipe.h"
#include "rook.h"
#include "bishop.h"
#include "queen.h"
#include "king.h"
#include "pawn.h"
#include "piece.h"
#include "knight.h"


Board::~Board()
{

}
Piece* (*Board::getBoard() const)[ROWS_SIZE]
{
    return (Piece * (*)[ROWS_SIZE])gameBoard;
}

Piece* Board::getPieceAt(const Point& p) const
{
    return getBoard()[p.getY()][p.getX()];
}

void Board::setPieceAt(const Point& p, Piece* piece)
{
    getBoard()[p.getY()][p.getX()] = piece;
}

bool Board::isCheck(std::string colorToCheck) const
{
	bool isCheck = false;
    int i = 0;
    int j = 0;
    Point kingLoc;
    for (i = 0; i < 8; i++)
    {
        for (j = 0; j < 8; j++)
        {
            if (getBoard()[i][j]->checkIsKing() && (getBoard()[i][j]->getColor() != colorToCheck))
            {
                kingLoc.setX(i);
                kingLoc.setY(j);
            }
        }
    }
    for (i = 0; i < 8; i++)
    {
        for (j = 0; j < 8; j++)
        {
            if (getBoard()[i][j]->isValidMove(*this, kingLoc) && (getBoard()[i][j]->getColor() == colorToCheck))
            {
				isCheck = true;
            }
        }
    }
	return isCheck;
}

Board::Board()
{
        // אתחול המערך ב-nullptr כדי למנוע זבל בזיכרון
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                gameBoard[i][j] = nullptr;
            }
        }

        // --- שחקן לבן (שורות 0 ו-1) ---
        setPieceAt(Point(0, 0), new Rook(Point(0, 0), "WHITE"));
        setPieceAt(Point(1, 0), new Knight(Point(1, 0), "WHITE"));
        setPieceAt(Point(2, 0), new Bishop(Point(2, 0), "WHITE"));
        setPieceAt(Point(3, 0), new King(Point(3, 0), "WHITE"));
        setPieceAt(Point(4, 0), new Queen(Point(4, 0), "WHITE"));
        setPieceAt(Point(5, 0), new Bishop(Point(5, 0), "WHITE"));
        setPieceAt(Point(6, 0), new Knight(Point(6, 0), "WHITE"));
        setPieceAt(Point(7, 0), new Rook(Point(7, 0), "WHITE"));

        for (int i = 0; i < 8; i++) {
            setPieceAt(Point(i, 1), new Pawn(Point(i, 1), "WHITE"));
        }

        // --- שחקן שחור (שורות 6 ו-7) ---
        for (int i = 0; i < 8; i++) {
            setPieceAt(Point(i, 6), new Pawn(Point(i, 6), "BLACK"));
        }

        setPieceAt(Point(0, 7), new Rook(Point(0, 7), "BLACK"));
        setPieceAt(Point(1, 7), new Knight(Point(1, 7), "BLACK"));
        setPieceAt(Point(2, 7), new Bishop(Point(2, 7), "BLACK"));
        setPieceAt(Point(3, 7), new King(Point(3, 7), "BLACK"));
        setPieceAt(Point(4, 7), new Queen(Point(4, 7), "BLACK "));
        setPieceAt(Point(5, 7), new Bishop(Point(5, 7), "BLACK"));
        setPieceAt(Point(6, 7), new Knight(Point(6, 7), "BLACK"));
        setPieceAt(Point(7, 7), new Rook(Point(7, 7), "BLACK"));
}