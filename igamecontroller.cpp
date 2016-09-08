#include "igamecontroller.h"
#include "board.h"
#include "piece.h"


IGameController::~IGameController() = default;


IGameController::IGameController()
{

    m_selectedPiece = nullptr;
    m_board = QSharedPointer < Board > ( new Board() ) ;


    connect( m_board.data(), SIGNAL(create_piece(QString,QPoint))
             , SLOT( boared_create_piece_slot( QString,QPoint ) ) );

}


bool IGameController::failClick( QPoint _xy ) const
{
    Piece* p = m_board->getCell( _xy.x(), _xy.y() );

    if( ( p == nullptr ) )
        return true;

    if( ( p->isWhite() != m_board->whitesAreMoving() ) && ( m_selectedPiece == nullptr ) ) //if selected != nullptr, it can be move for bit
        return true;

    return false;
}



void IGameController::boardHaveBeenClicked( QPoint _xy )   //координаты не корректные. фэйл клик не работает. выбивает ошибку
{
    if ( isThatColor( _xy ) )
    {
        m_selectedPiece = m_board->getCell( _xy.x(), _xy.y() );
        m_posForMoving = m_selectedPiece->getVectorOfPossibleMoves( *m_board );
    }
    else if( isMoving( _xy ) )
    {
        emit moved( QPoint( m_selectedPiece->getX(), m_selectedPiece->getY() ), _xy );

        m_board->move_figure( m_selectedPiece, _xy );
        clear_data();
    }
    else
        clear_data();


}

bool IGameController::isThatColor( QPoint _xy ) const
{
    Piece* p = m_board->getCell( _xy.x(), _xy.y() );

    if( p == nullptr )
        return false;

    return p->isWhite() == m_board->whitesAreMoving();
}

void IGameController::boared_create_piece_slot(const QString &_title, QPoint _xy)
{
    emit boared_create_piece_signal( _title, _xy );
}

void IGameController::start() const
{
    m_board->restart();
}
