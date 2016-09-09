#include "boardwidget.h"
#include <QSharedPointer>
#include <QMouseEvent>
#include <QPainter>

BoardWidget::BoardWidget( QWidget *parent )
    : QWidget( parent )
{
    const int BOARD_SIZE = 8;

    m_gameBoard = new QSharedPointer < QLabel >* [BOARD_SIZE];

    for( int i = 0; i < BOARD_SIZE; i++ )
        m_gameBoard[i] = new QSharedPointer < QLabel > [BOARD_SIZE];
}


QPoint BoardWidget::toWidgetCoordinates( QPoint _xy ) const
{
    QPoint newPoint;
    newPoint.setX( _xy.x() *  ( size().width()/8 - 5 ) + 20  );  //+/- some pixels
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
}


void BoardWidget::move_piece( QPoint _from, QPoint _to )
{
    if( !m_gameBoard[ _to.x() ][ _to.y() ].isNull() ) ///?????
        throw std::runtime_error( "Cell isn't free" );

    m_gameBoard[ _to.x() ][ _to.y() ].reset( m_gameBoard[ _from.x() ][ _from.y() ].data() );
    m_gameBoard[ _to.x() ][ _to.y() ]->move( toWidgetCoordinates( _to ) );
    m_gameBoard[ _from.x() ][ _from.y() ].reset();          //delete pixmap from board

    Q_ASSERT ( m_gameBoard[ _to.x() ][ _to.y() ].isNull() == false );
    Q_ASSERT ( m_gameBoard[ _from.x() ][ _from.y() ].isNull() );

   // m_gameBoard[ _to.x() ][ _to.y() ]->show();     //problems. error from windows
}


void BoardWidget::delete_piece( QPoint _xy )
{
    m_gameBoard[ _xy.x() ][ _xy.y() ].clear();
}


QPoint BoardWidget::toMatrixCoordinates( int _x, int _y ) const
{
    QPoint newPoint;

    newPoint.setX( _x/( size().width()/8 + 5 ) );
    newPoint.setY( _y/( size().width()/8 + 5 ) );

    return newPoint;
}

void BoardWidget::mousePressEvent( QMouseEvent *_e )
{
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
            p.drawRect( ( pos.x() * 95 ) + 20, ( pos.y() * 95 ) + 25, 95, 95 );    //will be with out numbers after refactoring
        }

        m_framesForNextStep.clear();
    }

//    if ( m_frameOfCurrentPiece.x() != -1 )
//    {
//        p.setPen( QPen ( Qt::black, 5 ) );
//        p.setBrush( QBrush( Qt::NoBrush ) );
//        p.drawRect( m_frameOfCurrentPiece.x() * 95 + 20
//                    ,m_frameOfCurrentPiece.y() * 95 + 25
//                    , 95
//                    , 95
//                    );
//    }

    p.end();
}


