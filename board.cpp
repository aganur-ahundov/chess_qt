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



Board::Board( IGraphicsController* _g, bool _whitesGoing )
    :m_whitesGoing ( _whitesGoing ), m_IGraphic( _g )
{
    m_pieces = new QSharedPointer < Piece >* [ Board::MAX_WIDTH ];

    for ( int i = 0; i < Board::MAX_WIDTH; i++ )
        m_pieces[i] = new QSharedPointer < Piece > [ Board::MAX_HEIGHT ];   //????????????

}


void Board::move_figure(Piece *_p, QPoint _c)    //отправлять сообщения о побитых фигурах
{
    if ( !posIsValid( _c ) )
        throw std::runtime_error( "Invalid position" );

    if( m_pieces[_c.x()][_c.y()].isNull() == false )
     {
        if ( m_pieces[_c.x()][_c.y()]->isWhite() != _p->isWhite() )
        {
            return; //The reaction on "fail" position. may be error or return false???
        }
    }
    else
    {
        m_pieces[ _c.x() ][ _c.y() ].reset( _p );
        m_pieces[ _p->getX() ][ _p->getY() ].clear();
        _p->setPos( _c );
    }
}

void Board::create_pawn( QPoint _xy, bool _isWhite )
{
    m_pieces[ _xy.x() ][ _xy.y() ].reset( new Pawn( _isWhite, _xy.x(), _xy.y() ) );

    QString _title = ( _isWhite ) ? PiecesTitle::WhitePawn : PiecesTitle::BlackPawn;
    m_IGraphic->create_piece( _title, _xy );
}


void Board::clear()
{
    for( int i = 0; i < Board::MAX_HEIGHT; i++ )
        for ( int j = 0; j < Board::MAX_WIDTH; i++ )
            m_pieces[i][j].clear();

      m_crushedPieces.clear();
}


void Board::restart()
{
    clear();

    create_rook( QPoint( 0, 0 ), false );
    create_knight( QPoint( 0, 1 ), false );
    create_bishop( QPoint( 0, 2 ), false );
    create_queen( QPoint( 0, 3 ), false );
    create_king( QPoint( 0, 4 ), false );
    create_bishop( QPoint( 0, 5 ), false );
    create_knight( QPoint( 0, 6 ), false );
    create_rook( QPoint( 0, 7 ), false );


    for( int i = 0; i < Board::MAX_WIDTH; i++ )
        create_pawn( QPoint( 1, i ), false );


    create_rook( QPoint( 7, 0 ), true );
    create_knight( QPoint( 7, 1 ), true );
    create_bishop( QPoint( 7, 2 ), true );
    create_queen( QPoint( 7, 3 ), true );
    create_king( QPoint( 7, 4 ), true );
    create_bishop( QPoint( 7, 5 ), true );
    create_knight( QPoint( 7, 6 ), true );
    create_rook( QPoint( 7, 7 ), true );


    for( int i = 0; i < Board::MAX_WIDTH; i++ )
        create_pawn( QPoint( 6, i ), true );
}


/*|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||*/
//                               methods for creation pieces                                     //
/*|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||*/
void Board::create_bishop( QPoint _xy, bool _isWhite )
{
    m_pieces[ _xy.x() ][ _xy.y() ].reset( new Bishop( _isWhite, _xy.x(), _xy.y() ) );

    QString _title = ( _isWhite ) ? PiecesTitle::WhiteBishop : PiecesTitle::BlackBishop;
    m_IGraphic->create_piece( _title, _xy );
}


void Board::create_king( QPoint _xy, bool _isWhite )
{
    m_pieces[ _xy.x() ][ _xy.y() ].reset( new King( _isWhite, _xy.x(), _xy.y() ) );

    QString _title = ( _isWhite ) ? PiecesTitle::WhiteKing : PiecesTitle::BlackKing;
    m_IGraphic->create_piece( _title, _xy );
}


void Board::create_queen( QPoint _xy, bool _isWhite )
{
    m_pieces[ _xy.x() ][ _xy.y() ].reset( new Queen( _isWhite, _xy.x(), _xy.y() ) );

    QString _title = ( _isWhite ) ? PiecesTitle::WhiteQueen : PiecesTitle::BlackQueen;
    m_IGraphic->create_piece( _title, _xy );
}

void Board::create_knight( QPoint _xy, bool _isWhite )
{
    m_pieces[ _xy.x() ][ _xy.y() ].reset( new Knight( _isWhite, _xy.x(), _xy.y() ) );

    QString _title = ( _isWhite ) ? PiecesTitle::WhiteKnight : PiecesTitle::BlackKnight;
    m_IGraphic->create_piece( _title, _xy );
}


void Board::create_rook( QPoint _xy, bool _isWhite )
{
    m_pieces[ _xy.x() ][ _xy.y() ].reset( new Rook( _isWhite, _xy.x(), _xy.y() ) );

    QString _title = ( _isWhite ) ? PiecesTitle::WhiteRook : PiecesTitle::BlackRook;
    m_IGraphic->create_piece( _title, _xy );
}
/*|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||*/
/*|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||*/
