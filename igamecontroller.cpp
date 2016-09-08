#include "igamecontroller.h"
#include "board.h"
#include "piece.h"
#include <QSet>

IGameController::IGameController()
{
    m_selectedPiece = nullptr;
    m_board = QSharedPointer < Board > ( new Board() ) ;
}


bool IGameController::failClick( QPoint _xy ) const
{
    Piece* p = m_board->getCell( _xy.x(), _xy.y() );

    if( ( p == nullptr ) && ( p->isWhite() != m_board->whitesAreMoving() ) )
        return true;

    return false;
}




void IGameController::boardHaveBeenClicked( QPoint _xy )
{
    if ( failClick( _xy ) )
    {
        m_selectedPiece = nullptr;
        m_posForMoving.clear();
    }


}
