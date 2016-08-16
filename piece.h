#ifndef PIECE_H
#define PIECE_H


#include <QObject>
#include <QPoint>
#include <stdexcept>

class Board;

//абстрактный класс - шахматная фигура
class Piece
        : public QObject  //for using QPointer
{
    Q_OBJECT
/*-----------------------------------------------*/
protected:

    Piece( bool _isWhite, int _x, int _y );

    virtual void check_position( Board const & _b, QVector <QPoint> & _v, int _directI, int _directJ ) const;
    void tryAddPosition( Board const & _b, QVector <QPoint> & _v, int _i, int _j ) const;
    bool posIsValid( QPoint _p ) const;


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
    virtual QString const & getTitle() const = 0;

/*-------------------------------------------------------------------*/


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


inline bool Piece::posIsValid( QPoint _xy) const
{
    return _xy.x() >= 0 && _xy.x() < 8 &&
            _xy.y() >= 0 && _xy.y() < 8;
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
    if( !posIsValid( _xy ) )
        throw std::runtime_error( "Invalidate new position!" );

    m_x = _xy.x();
    m_y = _xy.y();
}

/**********************************************************************************/
#endif // PIECE_H
