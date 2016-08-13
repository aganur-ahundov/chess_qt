#include "igraphicscontroller.h"
#include "pieces_title.h"

IGraphicsController::IGraphicsController(QWidget *parent)
    : QWidget(parent)
{
    setBackground();
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
