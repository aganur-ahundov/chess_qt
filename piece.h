#ifndef PIECE_H
#define PIECE_H

#include <QLabel>
#include <QMouseEvent>

class Board;

//абстрактный класс - шахматная фигура
class Piece
        : public QLabel //----> for mouse click event
{

/*-----------------------------------------------*/
protected:
    Piece( QWidget * _parent = 0, bool _isWhite, int _x = 0, int _y = 0 );
    virtual ~Piece() = default;



/*-----------------------------------------------*/
public:
    //явно выраженная сущность
    Piece( Piece const & _p ) = delete;
    Piece & operator = ( Piece const & _p ) = delete;


    //getters
    int getX() const;
    int getY() const;
    bool isWhite() const;


    void display() const = 0;
    //void hide() const;   //delete figure from board


    void mousePressEvent( QMouseEvent *_e );   //maybe it's correct choose

private:
    //function for moving ( all pieces have different 'steps' )
    void move( Board & _b ) = 0;
    //choose all cells for moving
    void check_steps( Board const & _b ) = 0;


/*-----------------------------------------------*/
private:
    int  m_x;       //координаты на доске
    int  m_y;
    bool m_white;   //цвет фигуры

};


/**********************************************************************************/

inline int Piece::getX() const
{
    return m_x;
}


inline int Piece::getY() const
{
    return m_y;
}


inline bool Piece::isWhite() const
{
    return m_white;
}


inline void Piece::mousePressEvent(QMouseEvent *_e)
{
    //?????????????????????/
}

/**********************************************************************************/
#endif // PIECE_H
