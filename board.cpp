#include "board.h"
#include "piece.h"

Board::Board( bool _whitesGoing )
    :m_whitesGoing ( _whitesGoing )
{

}


void Board::move_figure(Piece *_p, QPoint _c)    //отправлять сообщения о побитых фигурах
{
    if ( !posIsValid( _c ) )
        throw std::runtime_error( "Invalid position" );

    if( m_pieces[_c.x()][_c.y()] != nullptr && m_pieces[_c.x()][_c.y()]->isWhite() != _p->isWhite() )
    {
        return; //The reaction on "fail" position. may be error or return false???
    }
    else
    {
        m_pieces[ _p->getX() ][ _p->getY() ] = nullptr;
        m_pieces[ _c.x() ][ _c.y() ] = _p;
        _p->setPos( _c );
    }
}
