#include "pawn.h"
#include "board.h"
#include <QVector>

Pawn::Pawn(  bool _isWhite, int _x, int _y )
    :Piece( _isWhite, _x, _y )
{
}


bool Pawn::newStep( const Board &_b, QVector < QPoint > &_v, short _dirJ ) const
{
    if( _b.getCell( getX(), getY() + _dirJ ) == nullptr )
    {
        _v.push_back( QPoint( getX(), getY() + _dirJ ) );
        return true;
    }

    return false;
}


void Pawn::check_position( const Board &_b, QVector <QPoint> &_v, int _directI, int _directJ) const
{
    int i = getX() + _directI;
    int j = getY() + _directJ;


    if( posIsValid( QPoint ( i, j ) ) )
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
    const static int START_POSITION_FOR_BLACKS = 1;      //0 then 1 (second row)
    const static int START_POSITION_FOR_WHITES = Board::MAX_HEIGHT - 2;

    QVector < QPoint > moves;

    //if this pawn is white
    if( isWhite() )
    {
        if (  getY()  == START_POSITION_FOR_WHITES ) //if it first step
          {
            if( newStep( _b, moves, -1 ) )
            {
                if( _b.getCell( getX(), getY() - 2 ) == nullptr )
                    moves.push_back( QPoint( getX(), getY() - 2 ) );
            }
          }
        else
        {
            newStep( _b, moves, -1 );
        }

        check_position( _b, moves, -1, -1 ); //check cell. if it enemy then we can bit
        check_position( _b, moves, 1, -1 );
    }
    else //if pawn is black
    {

        if (  getY()  == START_POSITION_FOR_BLACKS ) //if it first step
          {
            if( newStep( _b, moves, 1 ) )
            {
                if( _b.getCell( getX(), getY() + 2 ) == nullptr )
                    moves.push_back( QPoint( getX(), getY() + 2 ) );
            }
          }
        else
        {
            newStep( _b, moves, 1 );
        }

        check_position( _b, moves, -1, 1 ); //check cell. if it enemy then we can bit
        check_position( _b, moves, 1, 1 );
    }

    return moves;
}

