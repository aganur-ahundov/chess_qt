#include "knight.h"
#include "board.h"

Knight::Knight( bool _isWhite, int _x, int _y )
    :Piece(  _isWhite, _x, _y )
{

}


void Knight::check_position(const Board &_b, QVector<QPoint> _v, int _directI, int _directJ) const
{
    int i = getX() + _directI;
    int j = getY() + _directJ;

    if( i > 0 && i < Board::MAX_WIDTH &&
            j > 0 && j < Board::MAX_HEIGHT )
    {
        tryAddPosition( _b, _v, i, j );
    }
}


QVector < QPoint > Knight::getVectorOfPossibleMoves(const Board &_b) const
{
    QVector < QPoint > moves;

    check_position( _b, moves, -1, -2 );
    check_position( _b, moves, 1, -2 );
    check_position( _b, moves, 2, -1 );
    check_position( _b, moves, 2, 1 );
    check_position( _b, moves, -1, 2 );
    check_position( _b, moves, 1, 2 );
    check_position( _b, moves, -2, 1 );
    check_position( _b, moves, -2, -1 );

    return moves;
}
