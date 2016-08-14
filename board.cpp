#include "board.h"
#include "piece.h"
#include "pieces_title.h"
#include "igraphicscontroller.h"
#include <QSharedPointer>

Board::Board( IGraphicController* _g, bool _whitesGoing )
    :m_whitesGoing ( _whitesGoing ), m_IGraphic( g )
{
    m_pieces = new QSharedPointer < Piece >* [Board::MAX_WIDTH];

    for ( int i = 0; i < Board::MAX_WIDTH; i++ )
        m_pieces[i] = new QSharedPointer < Piece > [Board::MAX_HEIGHT];   //????????????

    //method reset()
    m_pieces[0][0].reset( new Piece( PiecesTitle::BlackRook, false, 0, 0 ) );
    m_pieces[0][1].reset( new Piece( PiecesTitle::BlackBishop, false, 0, 1 ) );
    m_pieces[0][2].reset( new Piece( PiecesTitle::BlackKnight, false, 0, 2 ) );
    m_pieces[0][3].reset( new Piece( PiecesTitle::BlackQueen, false, 0, 3 ) );  //or King???

}


void Board::move_figure(Piece *_p, QPoint _c)    //отправлять сообщения о побитых фигурах
{
    if ( !posIsValid( _c ) )
        throw std::runtime_error( "Invalid position" );

    if( m_pieces[_c.x()][_c.y()].isNull() == false )
        if ( m_pieces[_c.x()][_c.y()]->isWhite() != _p->isWhite() )
    {
        return; //The reaction on "fail" position. may be error or return false???
    }
    else
    {
        m_pieces[ _c.x() ][ _c.y() ].reset( _p );
        m_pieces[ _p->getX() ][ _p->getY() ].clear();
        _p->setPos( _c );
    }
}
