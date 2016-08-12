#include "pawn.h"
#include "board.h"

Pawn::Pawn( QWidget* _parent, bool _isWhite, int _x, int _y )
    :Piece( _parent, _isWhite, _x, _y )
{
}


void Pawn::check_position(const Board &_b, QVector<QPoint> &_v, int _directI, int _directJ) const
{
    int i = getX() + _directI;
    int j = getY() + _directJ;


    if( i >= 0 && i < Board::MAX_WIDTH &&
            j >= 0 && j < Board::MAX_HEIGHT )
    {   //check for enemys
        if ( _b.getCell( i, j ) != nullptr )
        {
            if( _b.getCell( i, j )->isWhite() != isWhite()  )
                _v.push_back( QPoint ( i, j ) );
        }
    }
}



QVector < QPoint > Pawn::getVectorOfPossibleMoves( const Board & _b ) const
{
    //start position fot first step
    const static int START_POSITION_FOR_BLACKS = 2;
    const static int START_POSITION_FOR_WHITES = Board::MAX_HEIGHT - 2;

    QVector < QPoint > moves;

    //if this pawn is white
    if( isWhite() )
    {
        if ( ( getY() + 1 ) == START_POSITION_FOR_WHITES ) //if it first step
          {
              moves.push_back( QPoint( getX(), getY() - 1 ) );
              moves.push_back( QPoint( getX(), getY() - 2 ) );
          }

        check_position( _b, moves, -1, -1 ); //check cell. if it enemy then we can bit
        check_position( _b, moves, 1, -1 );
    }
    else //if pawn is black
    {

        if ( ( getY() + 1 ) == START_POSITION_FOR_BLACKS ) //if it first step
          {
              moves.push_back( QPoint( getX(), getY() + 1 ) );
              moves.push_back( QPoint( getX(), getY() + 2 ) );
          }

        check_position( _b, moves, -1, 1 ); //check cell. if it enemy then we can bit
        check_position( _b, moves, 1, 1 );
    }

    return moves;
}


void Pawn::display() const
{

}
