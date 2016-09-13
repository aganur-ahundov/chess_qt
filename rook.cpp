#include "rook.h"
#include <QVector>

Rook::Rook( bool _isWhite, int _x, int _y )
    :Piece( _isWhite, _x, _y ), m_moved(false)
{
}


QVector < QPoint > Rook::getVectorOfPossibleMoves(const Board &_b) const
{
    QVector < QPoint > moves;

    check_position( _b, moves, 0, -1);
    check_position( _b, moves, 0, 1);
    check_position( _b, moves, 1, 0);
    check_position( _b, moves, -1, 0);

    return moves;
}
