#include "igraphicscontroller.h"
#include "pieces_title.h"
#include "piece.h"
#include "boardwidget.h"
#include <QSharedPointer>
#include <QDialog>
#include <QPushButton>



IGraphicsController::IGraphicsController()
{
    m_gameBoard = QSharedPointer < BoardWidget > ( new BoardWidget() );
    m_pawnDialog = QSharedPointer < PawnTransformationDialog > ( new PawnTransformationDialog() );

    setBackground();\
    loadPiecesInfo();
    createGameOverWindow();

    connect( m_gameBoard.data(), SIGNAL(clicked_on_board(QPoint))
             , SLOT(clicked_point(QPoint)) );

    connect( m_pawnDialog.data(), SIGNAL( clicked( PiecesTitle::Piece_ID ) )
             , SIGNAL(pawn_transformed_signal(PiecesTitle::Piece_ID))  );
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
    m_gameBoard->clearPositionOfCurentPiece();
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
    m_gameBoard->repaint();
    m_gameBoard->clearPositionOfCurentPiece();
}


void IGraphicsController::paint_cells_for_moving( const QVector < QPoint > & _v, QPoint _xy )
{
    m_gameBoard->setVectorOfPositions( _v );
    m_gameBoard->setPositionOfCurrentPiece( _xy );
}


void IGraphicsController::pawn_transformation_slot()
{
    m_pawnDialog->show();
}


void IGraphicsController::createGameOverWindow()
{
    m_gameOverWindow = QSharedPointer < QLabel > ( new QLabel() );
    m_gameOverWindow->resize( 200, 200 );

    QPushButton* restart = new QPushButton( "Restart", m_gameOverWindow.data() );
    restart->move( 70, 130 );

    QPushButton* close = new QPushButton( "Exit", m_gameOverWindow.data() );
    close->move( 70, 160 );

    connect( close, SIGNAL( clicked(bool) ), m_gameOverWindow.data(), SLOT( close() ) );
    connect( close, SIGNAL( clicked(bool) ), m_gameBoard.data(), SLOT( close() ) );

    connect( restart, SIGNAL( clicked(bool) ), m_gameOverWindow.data(), SLOT( close() ) );
    connect( restart, SIGNAL( clicked( bool )), SLOT( reset_board() ) );
}


void IGraphicsController::game_over_slot( bool _winner )
{
    QString winnerName = ( _winner ) ? "\tWhite's" : "\tBlack's";
    winnerName += " won";
    m_gameOverWindow->setText( winnerName );
    m_gameOverWindow->setFocus();
    m_gameOverWindow->show();
}


void IGraphicsController::draw_slot()
{
    m_gameOverWindow->setText( "It's draw" );
    m_gameOverWindow->setFocus();
    m_gameOverWindow->show();

}

void IGraphicsController::reset_board()
{
    m_gameBoard->clearBoard();
    emit restart_signal();
}
