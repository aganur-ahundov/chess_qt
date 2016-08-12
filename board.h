#ifndef BOARD_H
#define BOARD_H

#include <QWidget>
#include <QPointer>

class Piece;

class Board
        : public QWidget
{

public:
/*---------------------------------------------------------------*/
    Board( bool _whitesGoing = 1, QWidget* _parent = 0 );
    ~Board() = default;

    void display() const;
    void move_figure( Piece* _p, QPoint _c );

    Piece* getCell( int _i, int j) const;


    const static int MAX_WIDTH = 8;
    const static int MAX_HEIGHT = 8;

protected:
    void mousePressEvent( QMouseEvent * _e );
    void paintEvent(QPaintEvent* _e);


/*---------------------------------------------------------------*/
private:
    QPointer < Piece >** m_pieces;
    bool m_whitesGoing;

};

inline Piece* Board::getCell( int _i, int _j ) const
{
    if( _i < 0 || _i >= MAX_WIDTH ||
        _j < 0 || _j >= MAX_HEIGHT )
        throw std::runtime_error( "Invalidate position!" );

    return m_pieces[_i][_j].data();
}

#endif // BOARD_H
