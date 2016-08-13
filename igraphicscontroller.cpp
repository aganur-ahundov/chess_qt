#include "igraphicscontroller.h"
#include "pieces_title.h"
#include "piece.h"
#include <QPointer>

IGraphicsController::IGraphicsController(QWidget *parent)
    : QWidget(parent)
{
    setBackground();\
    loadPiecesInfo();
}


void IGraphicsController::setBackground()
{
    setFixedSize( 800, 800 );

    QPixmap background ( "../Chess/resources/board.png" );  //load pixmap
    Q_ASSERT( background.isNull() );
    background = background.scaled( 1415, 900 );   //for "good looking"

    QPalette p;
    p.setBrush( this->backgroundRole(), QBrush( background ) ); //set like background
    this->setPalette( p ); //set
}


void IGraphicsController::loadPiecesInfo()
{
    m_piecesAndRoutes.insert( PiecesTitle::BlackBishop, "../Chess/resources/bishop_black.png" );
    m_piecesAndRoutes.insert( PiecesTitle::BlackKing, "../Chess/resources/king_black.png" );
    m_piecesAndRoutes.insert( PiecesTitle::BlackQueen, "../Chess/resources/queen_black.png" );
    ///............
}


void IGraphicsController::createPiece( const Piece &_p, QPoint _xy )
{
    QLabel* newPiece = new QLabel( this );
    newPiece->setPixmap( QPixmap( m_piecesAndRoutes.constFind( _p.getTitle() ).value() ) );
    m_gameBoard[_xy.x()][_xy.y()] = newPiece;
}


QPoint IGraphicsController::toBoardCoordinates( QPoint _xy ) const
{
    const static int NUM_CELL = 8;
    int pixByCell = this->size().width()/NUM_CELL;

    return QPoint( _xy.x()/pixByCell, _xy.y()/pixByCell );
}
