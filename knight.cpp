#include "knight.h"
#include <QVector>

Knight::Knight( bool _isWhite, int _x, int _y )
    :Piece( _isWhite, _x, _y )
{

}


void Knight::check_position( Board const & _b, QVector <QPoint> & _v, int _directI, int _directJ ) const
{
    int i = getX() + _directI;
    int j = getY() + _directJ;

    if( posIsValid( QPoint ( i, j ) ) )
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
