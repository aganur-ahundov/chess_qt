#include "bishop.h"
#include <QVector>

Bishop::Bishop(bool _isWhite, int _x, int _y )
    :Piece( _isWhite, _x, _y)
{
}


QVector < QPoint > Bishop::getVectorOfPossibleMoves(const Board &_b) const
{
    QVector < QPoint > moves;

    check_position ( _b, moves, -1, -1 );
    check_position ( _b, moves, 1, -1 );
    check_position ( _b, moves, -1, 1 );
    check_position ( _b, moves, 1, 1 );

    return moves;
}
