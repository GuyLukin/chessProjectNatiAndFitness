#include "piece.h"
#include "point.h"
#include "board.h"
#include "turnHandler.h"


Piece::Piece(Point source, std::string color, bool isKingFlag)
{
    _currLocation = source;
    _color = color;
    _isKingFlag = isKingFlag;
}

Piece::~Piece()
{
}

std::string Piece::getColor() const
{
	return _color;
}

Point Piece::getLoc() const
{
	return _currLocation;
}

void Piece::setLoc(Point inputPoint)
{
	_currLocation = inputPoint;
}

/*
std::string Piece::chooseMoveCode(Board& board, Point destPoint)
{
    std::string str_code = "";
    if (board.getPieceAt(_currLocation)->getColor() != TurnHandler::turnGetter())
    {
        str_code = "2";
    }
    if (board.getPieceAt(destPoint)->getColor() == this->getColor())
    {
        str_code = "3";
    }
    if (board.getPieceAt(destPoint)->getColor() == this->getColor())
    {
        str_code = "3";
    }
    if ( (_currLocation.getX() < 0 || _currLocation.getX() >= 8 || _currLocation.getY() < 0 || _currLocation.getY() >= 8) || 
        (destPoint.getX() < 0 || destPoint.getX() >= 8 || destPoint.getY() < 0 || destPoint.getY() >= 8)) 
    {
        str_code = "5";
    }
    if (!isValidMove(board, destPoint))
    {
        str_code = "6";
    }
    if (isValidMove(board, destPoint))
    {
       // Point preLoc(_currLocation.getX(), _currLocation.getY());
        Piece* preSourcePiece = board.getPieceAt(_currLocation);
        Piece* preDestPiece = board.getPieceAt(destPoint);
        //setPieceAt(const Point & p, Piece * piece)
        board.setPieceAt(destPoint, board.getPieceAt(_currLocation));
        board.setPieceAt(_currLocation, NULL);
        std::string enemyColor = "";
        if (getColor() == "WHITE")
        {
            enemyColor = "BLACK";
        }
        else
        {
            enemyColor = "WHITE";
        }
        /*
        if (board.isCheck(enemyColor))
        {
            str_code = "4";
        }
        else if (board.isCheck(getColor()))
        {
            str_code = "1";
        }
        /
        
            str_code = "0";
        if (str_code != "0" && str_code != "1")
        {
            board.setPieceAt(destPoint, preDestPiece);
            board.setPieceAt(_currLocation, preSourcePiece);
        }
    }
    return str_code;
}
*/
// C++
std::string Piece::chooseMoveCode(Board& board, Point destPoint)
{
    std::string str_code = "";

    // Validate source and destination are on board first
    if (_currLocation.getX() < 0 || _currLocation.getX() >= 8 ||
        _currLocation.getY() < 0 || _currLocation.getY() >= 8 ||
        destPoint.getX() < 0 || destPoint.getX() >= 8 ||
        destPoint.getY() < 0 || destPoint.getY() >= 8)
    {
        return "5";
    }

    Piece* src = board.getPieceAt(_currLocation);
    Piece* dst = board.getPieceAt(destPoint);

    if (!src) return "2";           // no source piece
    if (TurnHandler::turnGetter() != src->getColor()) return "2";

    if (dst && dst->getColor() == src->getColor()) return "3";

    if (!isValidMove(board, destPoint)) return "6";

    // perform tentative move safely (dst may be nullptr)
    Piece* preSourcePiece = src;
    Piece* preDestPiece = dst;
    board.setPieceAt(destPoint, src);
    board.setPieceAt(_currLocation, nullptr);

    // ... check for checks etc. ...

    // finalize result or undo if needed
    // (use preDestPiece/preSourcePiece to restore if not allowed)
    return "0";
}
bool Piece::checkIsKing()
{
    return _isKingFlag;
}

/*
   if (!(sourcePoint == this->getLoc()))
   {
       str_code = "2";
   }
   if ((*board.getPieceAt(destPoint)).getColor() == this->getColor())
   {
       str_code = "3";
   }
   else if (isCheck())
   {
       str_code = "4";
   }
   else if ((sourcePoint.getX() < 0 || sourcePoint.getX() >= 8 || sourcePoint.getY() < 0 || sourcePoint.getY() >= 8) ||
       (destPoint.getX() < 0 || destPoint.getX() >= 8 || destPoint.getY() < 0 || destPoint.getY() >= 8))
   {
       str_code = "5";
   }
   */