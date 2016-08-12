#include "bishop.h"

Bishop::Bishop( QWidget* _parent, bool _isWhite, int _x, int _y )
    :Piece(_parent, _isWhite, _x, _y)
{
}


void Bishop::check_position(const Board &_b, QVector<QPoint> &_v, int _directI, int _directJ) const
{
    int i = getX() + _directI;
    int j = getY() + _directJ;


    while( i >= 0 && i < Board::MAX_WIDTH &&
           j >= 0 && j < Board::MAX_HEIGHT )
    {
        if ( _b.getCell( i, j ) == nullptr )
            _v.push_back( QPoint( i, j ) );
        else if( _b.getCell( i, j )->isWhite() != isWhite() )
        {
            _v.push_back( QPoint ( i, j ) );
            return;
        }
        else
            return;

        i += _directI;
        j += _directJ;
    }
}


void Bishop::getVectorOfPossibleMoves(const Board &_b) const
{
    QVector < QPoint > moves;

    check_position ( _b, moves, -1, -1 );
    check_position ( _b, moves, 1, -1 );
    check_position ( _b, moves, -1, 1 );
    check_position ( _b, moves, 1, 1 );

    return moves;
}
