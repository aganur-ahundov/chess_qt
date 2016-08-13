#include "king.h"
#include "board.h"

King::King( QString const & _title, bool _isWhite, int _x, int _y)
    :Piece( _title, _isWhite, _x, _y)
{

}


void King::check_position(const Board &_b, QVector < QPoint > & _v, int _dispI, int _dispJ ) const
{

    int i = getX() + _dispI;
    int j = getY() + _dispJ;

    if ( posIsValid( QPoint ( i,j ) ) )
    {
        tryAddPosition( _b, _v, i, j );
    }
}



QVector< QPoint > King::getVectorOfPossibleMoves(const Board &_b)  const
{
    //не реализована ракировка

    QVector < QPoint > moves;

    //check left-upper cell
    check_position( _b, moves, -1, -1 );

    //check upper
    check_position( _b, moves, 0, -1 );

    //check right-upper cell
    check_position( _b, moves, 1, -1 );
    check_position( _b, moves, 1, 0 );
    check_position( _b, moves, 1, 1 );
    check_position( _b, moves, 0, -1 );
    check_position( _b, moves, -1, 1 );


    return moves;
}
