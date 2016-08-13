#ifndef BOARD_H
#define BOARD_H

//////////////////////////////////////////////////
#include <QWidget>
#include <QPointer>
//////////////////////////////////////////////////


class Piece;
class IGraphicController;



class Board
{

public:
/*---------------------------------------------------------------*/
    Board( bool _whitesGoing = 1 );
    ~Board() = default;
/*---------------------------------------------------------------*/


    void move_figure( Piece* _p, QPoint _c );
    Piece* getCell( int _i, int j) const;
    QVector < QPoint > & getVectorOfPossiblePieceMoves( const Piece* _p ) const;


    const static int MAX_WIDTH = 8;
    const static int MAX_HEIGHT = 8;

signals: //signals for controller ///argumants can be changed
    void piece_have_moved( Piece* _p, QPoint _from, QPoint _to ) const;
    void piece_have_beaten( Piece* _p ) const;


/*---------------------------------------------------------------*/
private:
    bool posIsValid( QPoint _pos ) const;

/*---------------------------------------------------------------*/
private:
    QPointer < Piece >** m_pieces;
    IGraphicController*  m_IGraphic;
    bool m_whitesGoing;

};
/***********************************************************************************/


inline bool Board::posIsValid(QPoint _pos) const
{
    return _pos.x() >= 0 && _pos.x() < MAX_WIDTH
            && _pos.y() >= 0 && _pos.y() < MAX_HEIGHT;
}


inline Piece* Board::getCell( int _i, int _j ) const
{
    if( !posIsValid( QPoint(_i, _j) ) )
        throw std::runtime_error( "Invalidate position!" );

    return m_pieces[_i][_j].data();
}

#endif // BOARD_H
