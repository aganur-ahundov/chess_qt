#include "igraphicscontroller.h"
#include "pieces_title.h"
#include "piece.h"
#include "boardwidget.h"
#include <QPointer>

IGraphicsController::IGraphicsController()
{
    m_gameBoard = QSharedPointer < BoardWidget > ( new BoardWidget() );
    setBackground();\
    loadPiecesInfo();


    connect( m_gameBoard.data(), SIGNAL(clicked_on_board(QPoint))
             , SLOT(clicked_point(QPoint)) );
}


void IGraphicsController::setBackground()
{
    m_gameBoard->setFixedSize( 800, 800 );

    QPixmap background ( "../Chess/resources/board.png" );  //load pixmap
    Q_ASSERT( background.isNull() == false );
    background = background.scaled( 1415, 900 );   //for "good looking"

    QPalette p;
    p.setBrush( m_gameBoard->backgroundRole(), QBrush( background ) ); //set like background
    m_gameBoard->setPalette( p ); //set
}


void IGraphicsController::loadPiecesInfo()
{
    m_piecesAndRoutes.insert( PiecesTitle::BlackBishop, "../Chess/resources/bishop_black.png" );
    m_piecesAndRoutes.insert( PiecesTitle::BlackKing, "../Chess/resources/king_black.png" );
    m_piecesAndRoutes.insert( PiecesTitle::BlackQueen, "../Chess/resources/queen_black.png" );
    m_piecesAndRoutes.insert( PiecesTitle::BlackKnight, "../Chess/resources/knight_black.png" );
    m_piecesAndRoutes.insert( PiecesTitle::BlackRook, "../Chess/resources/rook_black.png" );
    m_piecesAndRoutes.insert( PiecesTitle::BlackPawn, "../Chess/resources/pawn_black.png" );


    m_piecesAndRoutes.insert( PiecesTitle::WhiteBishop, "../Chess/resources/bishop_white.png" );
    m_piecesAndRoutes.insert( PiecesTitle::WhiteKing, "../Chess/resources/king_white.png" );
    m_piecesAndRoutes.insert( PiecesTitle::WhiteQueen, "../Chess/resources/queen_white.png" );
    m_piecesAndRoutes.insert( PiecesTitle::WhiteKnight, "../Chess/resources/knight_white.png" );
    m_piecesAndRoutes.insert( PiecesTitle::WhiteRook, "../Chess/resources/rook_white.png" );
    m_piecesAndRoutes.insert( PiecesTitle::WhitePawn, "../Chess/resources/pawn_white.png" );
}


QPoint IGraphicsController::toBoardCoordinates( QPoint _xy ) const
{
    const static int NUM_CELL = 8;
    int pixByCell = m_gameBoard->size().width()/NUM_CELL;

    return QPoint( _xy.x()/pixByCell, _xy.y()/pixByCell );
}


void IGraphicsController::move_piece(QPoint _from, QPoint _to)
{
    m_gameBoard->move_piece( _from, _to );
}


void IGraphicsController::delete_piece(QPoint _xy)
{
    m_gameBoard->delete_piece( _xy );
}


void IGraphicsController::repaint_board() const
{
    m_gameBoard->repaint();
}

void IGraphicsController::create_piece(const QString &_title, QPoint _xy) const
{
    auto it = m_piecesAndRoutes.constFind( _title );
    if ( it == m_piecesAndRoutes.end() )
        throw std::runtime_error( "Piece with this title hasn't been find" );

    m_gameBoard->createPiece( it.value(), _xy );
}

void IGraphicsController::show() const
{
    m_gameBoard->show();
}


void IGraphicsController::clicked_point(QPoint _xy)
{
    emit clicked_on_board( _xy );
}
