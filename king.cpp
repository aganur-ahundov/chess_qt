#include "king.h"
#include "board.h"

King::King(QWidget *_parent, bool _isWhite, int _x, int _y)
    :Piece(_parent, _isWhite, _x, _y)
{

}


void King::display() const
{
//    QPainter p;
//    p.drawEllipse( 0,0,0,0);
}


void King::check_position(const Board &_b, QVector < QPoint > & _v, int _dispI, int _dispJ ) const
{

    int i = getX() + _dispI;
    int j = getY() + _dispJ;

    if ( i >= 0 && i < Board::MAX_WIDTH &&
         j >= 0 && i < Board::MAX_HEIGHT  )
    {
        if(  _b.getCell( i, j ) == nullptr )
            _v.push_back( QPoint( i, j ) );
        else if ( _b.getCell( i, j )->isWhite() != isWhite() )
            _v.push_back( QPoint( i, j ) );
    }
}



QVector< QPoint > King::getVectorOfPossibleMoves(const Board &_b)  const
{
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
