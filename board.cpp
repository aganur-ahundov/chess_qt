//##########################################
//##########################################
#include "board.h"
#include "igraphicscontroller.h"
#include "pawn.h"
#include "bishop.h"
#include "king.h"
#include "queen.h"
#include "rook.h"
#include "knight.h"
//##########################################
//##########################################



Board::Board( bool _whitesGoing )
    :m_whitesGoing ( _whitesGoing )
{
    m_pieces = new QSharedPointer < Piece >* [ Board::MAX_WIDTH ];

    for ( int i = 0; i < Board::MAX_WIDTH; i++ )
        m_pieces[i] = new QSharedPointer < Piece > [ Board::MAX_HEIGHT ];   //????????????
}


void Board::move_figure( Piece *_p, QPoint _c )    //отправлять сообщения о побитых фигурах
{
    if ( !posIsValid( _c ) )
        throw std::runtime_error( "Invalid position" );

    if( m_pieces[ _c.x() ][ _c.y() ].isNull() == false )
     {
        if ( m_pieces[ _c.x() ][ _c.y() ]->isWhite() == _p->isWhite() )
        {
            return;
        }
    }
    else
    {
        m_pieces[ _c.x() ][ _c.y() ].reset( _p );
        m_pieces[ _p->getX() ][ _p->getY() ].clear();
        _p->setPos( _c );
    }
}


void Board::clear()
{
    for( int i = 0; i < Board::MAX_HEIGHT; i++ )
        for ( int j = 0; j < Board::MAX_WIDTH; j++ )
            m_pieces[i][j].clear();

     // m_crushedPieces.clear();
}


void Board::restart()
{
    clear();

    create_rook( QPoint( 0, 0 ), false );
    create_knight( QPoint( 1, 0 ), false );
    create_bishop( QPoint( 2, 0 ), false );
    create_queen( QPoint( 3, 0 ), false );
    create_king( QPoint( 4, 0 ), false );
    create_bishop( QPoint( 5, 0 ), false );
    create_knight( QPoint( 6, 0 ), false );
    create_rook( QPoint( 7, 0 ), false );


    for( int i = 0; i < Board::MAX_WIDTH; i++ )
        create_pawn( QPoint( i, 1 ), false );


    create_rook( QPoint( 0, 7 ), true );
    create_knight( QPoint( 1, 7 ), true );
    create_bishop( QPoint( 2, 7 ), true );
    create_queen( QPoint( 3, 7 ), true );
    create_king( QPoint( 4, 7 ), true );
    create_bishop( QPoint( 5, 7 ), true );
    create_knight( QPoint( 6, 7 ), true );
    create_rook( QPoint( 7, 7 ), true );


    for( int i = 0; i < Board::MAX_WIDTH; i++ )
        create_pawn( QPoint( i, 6 ), true );
}


/*|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||*/
//                               methods for creation pieces                                     //
/*|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||*/
void Board::create_pawn( QPoint _xy, bool _isWhite )
{
    m_pieces[ _xy.x() ][ _xy.y() ].reset( new Pawn( _isWhite, _xy.x(), _xy.y() ) );
    emit create_piece( m_pieces[_xy.x()][_xy.y()]->getTitle(), _xy );
}


void Board::create_bishop( QPoint _xy, bool _isWhite )
{
    m_pieces[ _xy.x() ][ _xy.y() ].reset( new Bishop( _isWhite, _xy.x(), _xy.y() ) );
    emit create_piece( m_pieces[_xy.x()][_xy.y()]->getTitle(), _xy );
}


void Board::create_king( QPoint _xy, bool _isWhite )
{
    m_pieces[ _xy.x() ][ _xy.y() ].reset( new King( _isWhite, _xy.x(), _xy.y() ) );
    emit create_piece( m_pieces[_xy.x()][_xy.y()]->getTitle(), _xy );
}


void Board::create_queen( QPoint _xy, bool _isWhite )
{
    m_pieces[ _xy.x() ][ _xy.y() ].reset( new Queen( _isWhite, _xy.x(), _xy.y() ) );
    emit create_piece( m_pieces[_xy.x()][_xy.y()]->getTitle(), _xy );
}

void Board::create_knight( QPoint _xy, bool _isWhite )
{
    m_pieces[ _xy.x() ][ _xy.y() ].reset( new Knight( _isWhite, _xy.x(), _xy.y() ) );
    emit create_piece( m_pieces[_xy.x()][_xy.y()]->getTitle(), _xy );
}


void Board::create_rook( QPoint _xy, bool _isWhite )
{
    m_pieces[ _xy.x() ][ _xy.y() ].reset( new Rook( _isWhite, _xy.x(), _xy.y() ) );
    emit create_piece( m_pieces[_xy.x()][_xy.y()]->getTitle(), _xy );
}
/*|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||*/
/*|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||*/
