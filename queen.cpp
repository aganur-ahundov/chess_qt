#include "queen.h"
#include <QVector>

Queen::Queen( bool _isWhite, int _x, int _y )
    :Piece( _isWhite, _x, _y )
{
}


QVector < QPoint > Queen::getSetOfPossibleMoves( const Board & _b ) const
{
    QVector < QPoint > moves;

    check_position( _b, moves, -1, -1 );
    check_position( _b, moves, 0, -1 );
    check_position( _b, moves, 1, -1 );
    check_position( _b, moves, 1, 0 );
    check_position( _b, moves, 1, 1 );
    check_position( _b, moves, 0, 1 );
    check_position( _b, moves, -1, 1 );
    check_position( _b, moves, -1, 0 );

    return moves;

}

