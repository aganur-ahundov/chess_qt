#include "queen.h"
#include "board.h"

Queen::Queen( QString const & _title, bool _isWhite, int _x, int _y )
    :Piece( _title, _isWhite, _x, _y )
{
}


QVector < QPoint > Queen::getVectorOfPossibleMoves( const Board & _b ) const
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

