#ifndef PIECE_H
#define PIECE_H

#include <QLabel>
//#include <QObject>

class Board;

//абстрактный класс - шахматная фигура
class Piece
        //: public QObject  //for using QPointer
        : public QLabel //----> for mouse click event   ????????????????????????//

{
    Q_OBJECT
/*-----------------------------------------------*/
protected:
    Piece( QWidget* _parent, bool _isWhite, int _x, int _y )
        :QLabel(_parent), m_x(_x), m_y(_y), m_white(_isWhite)
    {
    }


/*-----------------------------------------------*/
public:
    virtual ~Piece() = default;

//    //явно выраженная сущность
//    Piece( Piece const & _p ) = delete;
//    Piece & operator = ( Piece const & _p ) = delete;


    //getters
    int getX() const;
    int getY() const;
    bool isWhite() const;


    virtual void display() const = 0;

    //choose all cells for moving
    virtual QVector <QPoint> getVectorOfPossibleMoves( Board const & _b ) = 0;


/*---------------------------------------------------------------------*/
private:
    //function for moving ( all pieces have different 'steps' )
    virtual void moving( Board const & _b ) = 0;


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


//inline void Piece::mousePressEvent(QMouseEvent *_e)
//{
//
//    //check_steps();
//}

/**********************************************************************************/
#endif // PIECE_H
