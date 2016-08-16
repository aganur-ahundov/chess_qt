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
    QString const & getTitle() const override;
    bool isMoved() const;

protected:
   void check_position( Board const & _b, QVector <QPoint> & _v, int _directI, int _directJ ) const override;

private:
   bool m_moved;
};

inline QString const & King::getTitle() const
{
    return ( isWhite() ) ? PiecesTitle::WhiteKing : PiecesTitle::BlackKing;
}

inline bool King::isMoved() const
{
    return m_moved;
}

#endif // KING_H
