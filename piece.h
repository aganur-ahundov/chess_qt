#ifndef PIECE_H
#define PIECE_H


//абстрактный класс - шахматная фигура
class Piece
{

/*-----------------------------------------------*/
protected:
    Piece( bool _isWhite, int _x = 0, int _y = 0 );
    ~Piece() = default;



/*-----------------------------------------------*/
public:
    //явно выраженная сущность
    Piece( Piece const & _p ) = delete;
    Piece & operator = ( Piece const & _p ) = delete;


    //getters
    int getX() const;
    int getY() const;
    bool isWhite() const;


    //function for moving ( all pieces have different 'steps' )
    void move() = 0;

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

/**********************************************************************************/
#endif // PIECE_H