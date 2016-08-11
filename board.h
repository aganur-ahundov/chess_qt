#ifndef BOARD_H
#define BOARD_H

#include <QWidget>
#include <QPointer>

class Piece;

class Board
        //: public QWidget
{

public:
/*---------------------------------------------------------------*/
    Board();
    ~Board() = default;

    void display() const;
    void move_figure( Piece* _p, QPoint _c );

    Piece* getCell( int _i, int j) const;

protected:
    void mousePressEvent(QMouseEvent * _e);
    void paintEvent(QPaintEvent* _e);


/*---------------------------------------------------------------*/
private:
    QPointer < Piece >** m_pieces;

};

inline Piece* Board::getCell(int _i, int _j) const
{
    return m_pieces[_i][_j].data();
}

#endif // BOARD_H
