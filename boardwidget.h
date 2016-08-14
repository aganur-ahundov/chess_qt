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

signals:
    void clicked_on_board( QPoint _xy ) const; // signal send window coordinates

public slots:


protected:
    void mousePressEvent( QMouseEvent* _e );
   // void paintEvent( QPaintEvent* _e );

private:
    QSharedPointer < QLabel > ** m_gameBoard;
};

#endif // BOARDWIDGET_H
