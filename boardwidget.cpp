#include "boardwidget.h"
#include <QSharedPointer>
#include <QMouseEvent>
//#include <QPaintEvent>

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
    m_gameBoard[ _from.x() ][ _from.y() ].clear();

    m_gameBoard[ _to.x() ][ _to.y() ]->move( toWidgetCoordinates( _to ) );
}


void BoardWidget::delete_piece( QPoint _xy )
{
    m_gameBoard[ _xy.x() ][ _xy.y() ].clear();  //будем удалять лейблы или хранить их до конца игры.
                                                //дабы при рестарте не загружать пиксмапы по новой????
}


QPoint BoardWidget::toMatrixCoordinates( int _x, int _y ) const
{
    QPoint newPoint;

    newPoint.setX( _x/80 );
    newPoint.setY( _y/80 );

    return newPoint;
}

void BoardWidget::mousePressEvent( QMouseEvent *_e )
{
    emit clicked_on_board( toMatrixCoordinates( _e->x(), _e->y() ) );
}



