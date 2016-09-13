#include "piece.h"
#include "board.h"

Piece::Piece( bool _isWhite, int _x, int _y )
    :m_white( _isWhite )
{
    setX(_x);
    setY(_y);
}


bool Piece::tryAddPosition(const Board &_b, QVector <QPoint> &_v, int i, int j) const
{
    if ( _b.getCell( i, j ) == nullptr )
        _v.push_back( QPoint( i, j ) );
    else if( _b.getCell( i, j )->isWhite() != isWhite() )
    {
        _v.push_back( QPoint( i, j ) );
        return false;
    }
    else
        return false;


    return true;
}


void Piece::check_position( Board const & _b, QVector <QPoint> & _v, int _directI, int _directJ ) const
{
    int i = getX() + _directI;
    int j = getY() + _directJ;


    while( posIsValid( QPoint(i,j) ) )
    {
        if ( tryAddPosition( _b, _v, i, j ) == false )
            break;

        i += _directI;
        j += _directJ;
    }


}
