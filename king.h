#ifndef KING_H
#define KING_H

#include "piece.h"
#include "pieces_title.h"

class King: public Piece
{
/*----------------------------------------------------*/
public:
    King( bool _isWhite, int _x, int _y );
    ~King() = default;

    QVector < QPoint > getVectorOfPossibleMoves( const Board &_b ) const override;
    QString getTitle() const override;
    bool isMoved() const override;
    void moving( QPoint _to ) override;

signals:
    void left_castling_signal();
    void right_castling_signal();

private:
    void makeACastling( const Board & _b, QVector < QPoint > & _v ) const;
    void rightCastling( const Board & _b, QVector < QPoint > & _v ) const;
    void leftCastling( const Board & _b, QVector < QPoint > & _v ) const;

protected:
   void check_position( Board const & _b, QVector <QPoint> & _v, int _directI, int _directJ ) const override;

private:
   bool m_haveMoved;
};

inline QString King::getTitle() const
{
    return ( isWhite() ) ? PiecesTitle::WhiteKing : PiecesTitle::BlackKing;
}

inline bool King::isMoved() const
{
    return m_haveMoved;
}



#endif // KING_H
