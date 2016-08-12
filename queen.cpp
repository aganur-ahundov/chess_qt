#include "queen.h"
#include "board.h"

Queen::Queen( QWidget* _parent, bool _isWhite, int _x, int _y )
    :Piece( _parent, _isWhite, _x, _y )
{
}


QVector < QPoint > Queen::getVectorOfPossibleMoves( const Board & _b ) const
{
    QVector < QPoint > moves;
    int i = getX();
    int j = getY();


    i++; j--;  //direction
    while( _b.getCell( i, j ) == nullptr
           && i >= 0
           && i < 8
           && j >= 0
           && j < 8
           )
    {
        moves.push_back( QPoint( i, j ) );

        i++; j--;

        if( _b.getCell( i, j ) != nullptr
                && _b.getCell( i, j)->isWhite() != isWhite() )
        {
            moves.push_back( QPoint ( i, j ) );
            break;
        }
    }
}
