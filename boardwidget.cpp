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


void BoardWidget::createPiece( const QString & _path, QPoint _xy )
{
    QLabel* newPiece = new QLabel( this );
    newPiece->setPixmap( QPixmap( _path ) );
    m_gameBoard[_xy.x()][_xy.y()].reset( newPiece );
}


void BoardWidget::move_piece( QPoint _from, QPoint _to )
{
    if( !m_gameBoard[ _to.x() ][ _to.y() ].isNull() ) ///?????
        throw std::runtime_error( "Cell isn't free" );

    m_gameBoard[ _to.x() ][ _to.y() ].reset( m_gameBoard[ _from.x() ][ _from.y() ].data() );
    m_gameBoard[ _from.x() ][ _from.y() ].clear();

    m_gameBoard[ _to.x() ][ _to.y() ]->move( _to.x() * size().width()/8, _to.y() * size().height()/8 );  //+/- some pixels
}


void BoardWidget::delete_piece( QPoint _xy )
{
    m_gameBoard[ _xy.x() ][ _xy.y() ].clear();  //будем удалять лейблы или хранить их до конца игры.
                                                //дабы при рестарте не загружать пиксмапы по новой????
}


void BoardWidget::mousePressEvent( QMouseEvent *_e )
{
    emit clicked_on_board( QPoint( _e->x(), _e->y() ) );
}



