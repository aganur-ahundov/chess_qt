#include "igamecontroller.h"
#include "board.h"
#include "piece.h"
#include "pieces_title.h"


IGameController::~IGameController() = default;


IGameController::IGameController()
{

    m_selectedPiece = nullptr;
    m_board = QSharedPointer < Board > ( new Board() ) ;


    connect( m_board.data(), SIGNAL( create_piece( QString,QPoint ) )
             , SLOT( boared_create_piece_slot( QString,QPoint ) ) );

    connect( m_board.data(), SIGNAL( right_castling_signal( QPoint,QPoint ) )
             , SIGNAL( moved(QPoint,QPoint) )
                );

    connect( m_board.data(), SIGNAL( left_castling_signal( QPoint,QPoint ) )
             , SIGNAL( moved( QPoint,QPoint ) )
                );

    connect( m_board.data(), SIGNAL( pawn_last_step_signal( QPoint ) )
             , SLOT( pawn_transformation_slot( QPoint ) )
             );
}


void IGameController::pawn_transformation_slot( QPoint _xy )
{
    m_pawnTransormPos = _xy;
    emit pawn_transformation_signal();
}


void IGameController::pawn_transformed_slot( PiecesTitle::Piece_ID _id )
{
    switch ( _id )
    {
    case PiecesTitle::Bishop_ID:
        m_board->create_bishop( m_pawnTransormPos, !m_board->whitesAreMoving() );
        break;
    case PiecesTitle::Rook_ID:
        m_board->create_rook( m_pawnTransormPos, !m_board->whitesAreMoving() );
        break;
    case PiecesTitle::Knight_ID:
        m_board->create_knight( m_pawnTransormPos, !m_board->whitesAreMoving() );
        break;
    case PiecesTitle::Queen_ID:
        m_board->create_queen( m_pawnTransormPos, !m_board->whitesAreMoving() );
        break;
    default:
        Q_ASSERT(0);
        break;
    }
}


void IGameController::boardHaveBeenClicked( QPoint _xy )
{
    if ( isThatColor( _xy ) )
    {
        m_selectedPiece = m_board->getCell( _xy.x(), _xy.y() );
        m_posForMoving = m_selectedPiece->getVectorOfPossibleMoves( *m_board );

        if(! m_posForMoving.empty() )
            emit have_some_cells_for_moving( m_posForMoving
                                             , QPoint ( m_selectedPiece->getX(), m_selectedPiece->getY() ) );
    }
    else if( isMoving( _xy ) )
    {
        emit moved( QPoint( m_selectedPiece->getX(), m_selectedPiece->getY() ), _xy );

        m_board->move_figure( m_selectedPiece, _xy );
        clear_data();

        m_board->switchTurn();
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

void IGameController::boared_create_piece_slot( const QString &_title, QPoint _xy )
{
    emit boared_create_piece_signal( _title, _xy );
}

void IGameController::start() const
{
    m_board->restart();
}
