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
    m_pieces = new QScopedPointer < Piece >* [ Board::MAX_WIDTH ];

    for ( int i = 0; i < Board::MAX_WIDTH; i++ )
        m_pieces[i] = new QScopedPointer < Piece > [ Board::MAX_HEIGHT ];
}


void Board::right_castling_slot()
{
    if( whitesAreMoving() )
    {
        emit right_castling_signal( QPoint ( MAX_WIDTH - 1, MAX_HEIGHT - 1 )
                                    , QPoint( MAX_WIDTH - 3, MAX_HEIGHT - 1 )
                                    );

        move_figure(
                    m_pieces[ MAX_WIDTH - 1 ][ MAX_HEIGHT - 1 ].data()
                    , QPoint ( MAX_WIDTH - 3, MAX_HEIGHT - 1 )
                );        
    }
    else
    {
        emit right_castling_signal( QPoint ( MAX_WIDTH - 1, 0 )
                                    , QPoint( MAX_WIDTH - 3, 0 )
                                    );

        move_figure( m_pieces[ MAX_WIDTH - 1 ][ 0 ].data()
                , QPoint ( MAX_WIDTH - 3, 0 )
                );
    }
}

void Board::left_castling_slot()
{
    if( whitesAreMoving() )
    {
        emit left_castling_signal( QPoint ( 0, MAX_HEIGHT - 1 )
                                    , QPoint( 3, MAX_HEIGHT - 1 )
                                    );

        move_figure(
                    m_pieces[ 0 ][ MAX_HEIGHT - 1 ].data()
                    , QPoint ( 3, MAX_HEIGHT - 1 )
                );
    }
    else
    {
        emit left_castling_signal( QPoint ( 0, 0 )
                                    , QPoint( 3, 0 )
                                    );

        move_figure( m_pieces[ 0 ][ 0 ].data()
                , QPoint ( 3, 0 )
                );
    }
}


void Board::move_figure( Piece *_p, QPoint _c )    //отправлять сообщения о побитых фигурах
{
    if ( !posIsValid( _c ) )
        throw std::runtime_error( "Invalid position" );

    m_pieces[ _p->getX() ][ _p->getY() ].data()->moving( _c );

     m_pieces[ _c.x() ][ _c.y() ].reset( m_pieces[ _p->getX() ][ _p->getY() ].take() );
     Q_ASSERT( m_pieces[ _p->getX() ][ _p->getY() ].isNull() );

     _p->setPos( _c );
}


void Board::clear()
{
    for( int i = 0; i < Board::MAX_HEIGHT; i++ )
        for ( int j = 0; j < Board::MAX_WIDTH; j++ )
            m_pieces[i][j].reset();
}


Piece* Board::getCell( int _i, int _j ) const
{
    if( !posIsValid( QPoint(_i, _j) ) )
        throw std::runtime_error( "Invalidate position!" );

    return m_pieces[_i][_j].data();
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

    connect( m_pieces[ _xy.x() ][ _xy.y() ].data(), SIGNAL( right_castling_signal() )
                    , SLOT(right_castling_slot()) );

    connect( m_pieces[ _xy.x() ][ _xy.y() ].data(), SIGNAL( left_castling_signal() )
            , SLOT( left_castling_slot() )
            );

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

