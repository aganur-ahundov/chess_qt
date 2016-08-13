#ifndef IGRAPHICSCONTROLLER_H
#define IGRAPHICSCONTROLLER_H

#include <QWidget>
#include <QLabel>
#include <QMap>


class Piece;


class IGraphicsController
        : public QWidget
{
    Q_OBJECT
public:
    explicit IGraphicsController( QWidget *parent = 0 );
    ~IGraphicsController() = default;

//    void createPiece( Piece const & _p, QPoint _xy );
//    QPoint toBoardCoordinates( QPoint _xy ) const;

signals:


public slots:
//    void move_piece( QPoint _from, QPoint _to );
//    void delete_piece( QPoint _xy );


protected:
//    void mousePressEvent( QMouseEvent* _e );
//    void paintEvent( QPaintEvent* _e );

private:
    void setBackground();
    void loadPiecesInfo();

private:
    QPointer < QLabel > ** m_gameBoard;
    QPainter* m_painter;                            //may be it will be need
    QMap < QString, QString > m_piecesAndRoutes;    //pieces title and routes for pictures
};

#endif // IGRAPHICSCONTROLLER_H
