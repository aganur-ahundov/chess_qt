#include "boardwidget.h"
#include <QPointer>
#include <QMouseEvent>
#include <QPainter>



BoardWidget::BoardWidget( QWidget *parent )
    : QWidget( parent )
{

    m_gameBoard = new QScopedPointer < QLabel >* [BOARD_SIZE];

    for( int i = 0; i < BOARD_SIZE; i++ )
       m_gameBoard[i] = new QScopedPointer < QLabel > [BOARD_SIZE];

    clearPositionOfCurentPiece();
}


QPoint BoardWidget::toWidgetCoordinates( QPoint _xy ) const
{
    QPoint newPoint;
    newPoint.setX( _xy.x() *  ( size().width()/8 - 5 ) + 20  );  // +/- some pixels
    newPoint.setY( _xy.y() *  ( size().height()/8 - 3) + 20  );

    return newPoint;
}


void BoardWidget::createPiece( const QString & _path, QPoint _xy )
{
    QLabel* newPiece = new QLabel( this );
    QPixmap p( _path );

    if ( p.isNull() )
        throw std::runtime_error( "Pixmap wasn't loaded" );

    p = p.scaled( 80, 80 );
    newPiece->setPixmap( p );

    m_gameBoard[_xy.x()][_xy.y()].reset( newPiece );
    newPiece->move( toWidgetCoordinates( _xy ) );

    newPiece->show();
}


void BoardWidget::move_piece( QPoint _from, QPoint _to )
{
    m_gameBoard[ _to.x() ][ _to.y() ].reset( m_gameBoard[ _from.x() ][ _from.y() ].take() );
    m_gameBoard[ _to.x() ][ _to.y() ]->move( toWidgetCoordinates( _to ) );
   // m_gameBoard[ _from.x() ][ _from.y() ].reset();


    Q_ASSERT ( m_gameBoard[ _to.x() ][ _to.y() ].isNull() == false );
    Q_ASSERT ( m_gameBoard[ _from.x() ][ _from.y() ].isNull() );
}


void BoardWidget::delete_piece( QPoint _xy )
{
    m_gameBoard[ _xy.x() ][ _xy.y() ].reset();
}


QPoint BoardWidget::toMatrixCoordinates( int _x, int _y ) const
{
    QPoint newPoint;

    newPoint.setX( ( _x - 20 )/CELL_SIZE );
    newPoint.setY( ( ( _y - 30 )/CELL_SIZE ) ) ;

    return newPoint;
}

void BoardWidget::mousePressEvent( QMouseEvent *_e )
{
     m_framesForNextStep.clear();
    emit clicked_on_board( toMatrixCoordinates( _e->x(), _e->y() ) );
}


void BoardWidget::paintEvent( QPaintEvent *_e )
{
    QPainter p;

    p.begin( this );
    p.setRenderHint( QPainter::Antialiasing, true );


    if( m_framesForNextStep.empty() == false )
    {
        p.setPen( QPen ( Qt::blue, 5 ) );
        p.setBrush( QBrush( Qt::NoBrush ) );

        short size = m_framesForNextStep.size();
        for( short i = 0; i < size; i++ )
        {
            QPoint pos = m_framesForNextStep[i];
            p.drawRect( ( pos.x() * CELL_SIZE ) + 20
                        , ( pos.y() * CELL_SIZE ) + 25
                        , CELL_SIZE, CELL_SIZE );    //will be with out numbers after refactoring
        }
    }

    if ( pieceSelected() )
    {
        p.setPen( QPen ( Qt::black, 5 ) );
        p.setBrush( QBrush( Qt::NoBrush ) );
        p.drawRect( m_frameOfCurrentPiece.x() * CELL_SIZE + 20
                    ,m_frameOfCurrentPiece.y() * CELL_SIZE + 30
                    , CELL_SIZE
                    , CELL_SIZE
                    );
    }

    p.end();
}


void BoardWidget::clearBoard()
{
    for( int i = 0; i < BOARD_SIZE; i++ )
    {
        for( int j = 0; j < BOARD_SIZE; j++ )
            m_gameBoard[i][j].reset();
    }
}
