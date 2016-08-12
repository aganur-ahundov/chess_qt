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
        :QLabel(_parent), m_white(_isWhite)
    {
        setX(_x);
        setY(_y);
    }


/*-----------------------------------------------*/
public:
    virtual ~Piece() = default;

    //явно выраженная сущность
    Piece( Piece const & _p ) = delete;
    Piece & operator = ( Piece const & _p ) = delete;


    //getters
    int getX() const;
    int getY() const;
    bool isWhite() const;
    void setX( int _x );
    void setY( int _y );
    void setPos( QPoint _xy );

/*-------------------------------------------------------------------*/

    virtual void display() const = 0;

    //choose all cells for moving
    virtual QVector <QPoint> getVectorOfPossibleMoves( Board const & _b ) const = 0;


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


inline void Piece::setX(int _x)
{
    if( _x < 0 || _x >= 8 )
        throw std::runtime_error( "Invalidate new position!" );

    m_x = _x;
}


inline void Piece::setY( int _y )
{
    if( _y < 0 || _y >= 8 )
        throw std::runtime_error( "Invalidate new position!" );

    m_y = _y;
}


inline void Piece::setPos( QPoint _xy )
{
    if( _xy.x() < 0 || _xy.x() >= 8 ||
        _xy.y() < 0 || _xy.y() >= 8 )
        throw std::runtime_error( "Invalidate new position!" );

    m_x = _xy.x();
    m_y = _xy.y();
}
//inline void Piece::mousePressEvent(QMouseEvent *_e)
//{
//
//    //check_steps();
//}

/**********************************************************************************/
#endif // PIECE_H
