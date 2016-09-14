#include "king.h"
#include <board.h>
#include <QVector>

King::King( bool _isWhite, int _x, int _y)
    :Piece( _isWhite, _x, _y), m_haveMoved( false )
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


void King::rightCastling( const Board & _b, QVector < QPoint > & _v ) const
{
    if( !_b.getCell( getX() + 1, getY() ) && !_b.getCell( getX() + 2, getY() ) )
    {
        Piece* p = _b.getCell( getX() + 3, getY() );
        if( p != nullptr )
        {
            if ( p->isMoved() == false )
            {
                _v.push_back( QPoint ( getX() + 1, getY() ) );
                _v.push_back( QPoint ( getX() + 2, getY() ) );
            }
        }
    }
}


void King::leftCastling( const Board &_b, QVector<QPoint> &_v ) const
{
    if( !_b.getCell( getX() - 1, getY() ) && !_b.getCell( getX() - 2, getY() ) && !_b.getCell( getX() - 3, getY() ) )
    {
        Piece* p = _b.getCell( 0, getY() );
        if( p != nullptr )
        {
            if ( p->isMoved() == false )
            {
                _v.push_back( QPoint ( getX() - 1, getY() ) );
                _v.push_back( QPoint ( getX() - 2, getY() ) );
            }
        }
    }
}



void King::makeACastling( const Board & _b, QVector < QPoint > & _v ) const
{
    if( isMoved() )
        return;

    rightCastling( _b, _v );
    leftCastling( _b, _v );
}


void King::moving( QPoint _to )
{
    if( isMoved() )
        return;

    if( _to.x() - getX() == 2 )
        emit right_castling_signal();
    else if ( getX() - _to.x() == 2 )
        emit left_castling_signal();

    m_haveMoved = true;
}

QVector < QPoint > King::getVectorOfPossibleMoves( const Board & _b )  const
{

    QVector < QPoint > moves;

    makeACastling( _b, moves);

    //check left-upper cell
    check_position( _b, moves, -1, -1 );

    //check upper
    check_position( _b, moves, 0, -1 );

    //check right-upper cell
    check_position( _b, moves, 1, -1 );
    check_position( _b, moves, 1, 0 );
    check_position( _b, moves, 1, 1 );
    check_position( _b, moves, 0, 1 );
    check_position( _b, moves, -1, 0 );
    check_position( _b, moves, -1, 1 );


    return moves;
}
