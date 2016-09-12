#ifndef BOARD_H
#define BOARD_H

#include <QVector>
#include <QPointer>
#include <QPoint>
#include <QObject>

class Piece;
class IGraphicsController;



class Board
        : public QObject
{
    Q_OBJECT

public:

    const static int MAX_WIDTH = 8;
    const static int MAX_HEIGHT = 8;

/*---------------------------------------------------------------*/
    Board( bool _whitesGoing = true );
    ~Board() = default;
/*---------------------------------------------------------------*/

    bool whitesAreMoving() const;
    void switchTurn();             //after moving time for changing side
    void move_figure( Piece* _p, QPoint _c );
    Piece* getCell( int _i, int j) const;
    void restart(); //all pieces on default positions
    void clear();   //clear all data

signals:
    //signals for controller ///argumants can be changed
    void piece_have_moved( Piece* _p, QPoint _from, QPoint _to ) const;
    void piece_have_beaten( Piece* _p ) const;
    void create_piece( QString const & _title, QPoint _pos );

public:
    void create_pawn( QPoint _xy, bool _isWhite );
    void create_bishop( QPoint _xy, bool _isWhite );
    void create_king( QPoint _xy, bool _isWhite );
    void create_queen( QPoint _xy, bool _isWhite );
    void create_knight( QPoint _xy, bool _isWhite );
    void create_rook( QPoint _xy, bool _isWhite );


private:
    bool posIsValid( QPoint _pos ) const;

private:
    QPointer < Piece >** m_pieces;
    bool m_whitesGoing;

};
/***********************************************************************************/


inline bool Board::whitesAreMoving() const
{
    return m_whitesGoing;
}


inline bool Board::posIsValid( QPoint _pos ) const
{
    return _pos.x() >= 0 && _pos.x() < MAX_WIDTH
            && _pos.y() >= 0 && _pos.y() < MAX_HEIGHT;
}


//inline Piece* Board::getCell( int _i, int _j ) const
//{
//    if( !posIsValid( QPoint(_i, _j) ) )
//        throw std::runtime_error( "Invalidate position!" );

//    return m_pieces[_i][_j].data();
//}


inline void Board::switchTurn()
{
    m_whitesGoing = !m_whitesGoing;
}

#endif // BOARD_H
