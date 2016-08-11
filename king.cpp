#include "king.h"
#include "board.h"

//King::King( QWidget* _parent, bool _isWhite, int _x, int _y )
//    :Piece(_parent, _isWhite, _x, _y)
//{

//}

King::King(QWidget *_parent, bool _isWhite, int _x, int _y)
    :Piece(_parent, _isWhite, _x, _y)
{

}

void King::display() const
{
//    QPainter p;
//    p.drawEllipse( 0,0,0,0);
}

QVector< QPoint > King::getVectorOfPossibleMoves(const Board &_b)
{
    QVector < QPoint > moves;

    //check left-upper cell
    if(  _b.getCell( getX() - 1, getY() - 1 ) == nullptr
            || _b.getCell( getX() - 1, getY() - 1 )->isWhite() != isWhite() )
        moves.push_back( QPoint( getX() - 1, getY() - 1 ) );

    //check upper
    if(  _b.getCell( getX(), getY() - 1 ) == nullptr
            || _b.getCell( getX(), getY() - 1 )->isWhite() != isWhite() )
        moves.push_back( QPoint( getX(), getY() - 1 ) );

    //check right-upper cell
    if(  _b.getCell( getX() + 1, getY() - 1 ) == nullptr
            || _b.getCell( getX() + 1, getY() - 1 )->isWhite() != isWhite() )
        moves.push_back( QPoint( getX() + 1, getY() - 1 ) );

    if(  _b.getCell( getX() + 1, getY() ) == nullptr
            || _b.getCell( getX() + 1, getY() )->isWhite() != isWhite() )
        moves.push_back( QPoint( getX() + 1, getY() ) );

    if(  _b.getCell( getX() + 1, getY() + 1 ) == nullptr
            || _b.getCell( getX() + 1, getY() + 1 )->isWhite() != isWhite() )
        moves.push_back( QPoint( getX() + 1, getY() + 1 ) );

    if(  _b.getCell( getX(), getY() + 1 ) == nullptr
            || _b.getCell( getX(), getY() + 1 )->isWhite() != isWhite() )
        moves.push_back( QPoint( getX(), getY() + 1 ) );

    if(  _b.getCell( getX() - 1, getY() + 1 ) == nullptr
            || _b.getCell( getX() - 1, getY() + 1 )->isWhite() != isWhite() )
        moves.push_back( QPoint( getX() - 1, getY() + 1 ) );


    return moves;
}
