#ifndef BOARDWIDGET_H
#define BOARDWIDGET_H

/*############################################*/
#include <QWidget>
#include <QLabel>
/*############################################*/



class BoardWidget
        : public QWidget
{
    Q_OBJECT
public:
    explicit BoardWidget( QWidget *parent = 0 );
    ~BoardWidget() = default;

    void createPiece( QString const & _path, QPoint _xy );
    void move_piece( QPoint _from, QPoint _to );
    void delete_piece( QPoint _xy );

    void setVectorOfPositions( QVector < QPoint > const & _v );
    void clearVectorOfPositions();
    void setPositionOfCurrentPiece( QPoint _xy );
    void clearPositionOfCurentPiece();

signals:
    void clicked_on_board( QPoint _xy ) const; // signal send window coordinates

protected:
    void mousePressEvent( QMouseEvent* _e );
    void paintEvent( QPaintEvent* _e );

private:
    QPoint toWidgetCoordinates( QPoint _xy ) const;
    QPoint toMatrixCoordinates( int _x, int _y ) const;

private:
    QPointer < QLabel > ** m_gameBoard;

    QVector < QPoint > m_framesForNextStep;
    QPoint m_frameOfCurrentPiece;

    static const int CELL_SIZE = 95;
};

inline void BoardWidget::setVectorOfPositions( const QVector < QPoint > &_v )
{
    m_framesForNextStep = _v;
}

inline void BoardWidget::clearVectorOfPositions()
{
    m_framesForNextStep.clear();
}

inline void BoardWidget::setPositionOfCurrentPiece(QPoint _xy)
{
    m_frameOfCurrentPiece = _xy;
}

inline void BoardWidget::clearPositionOfCurentPiece()
{
    m_frameOfCurrentPiece.rx() = -1;
    m_frameOfCurrentPiece.ry() = -1;
}

#endif // BOARDWIDGET_H
