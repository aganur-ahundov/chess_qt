#ifndef QUEEN_H
#define QUEEN_H

#include "piece.h"
#include "pieces_title.h"

class Queen : public Piece
{
public:
    Queen( bool _isWhite, int _x, int _y );
    ~Queen() = default;

    QVector < QPoint > getSetOfPossibleMoves(const Board &_b) const override;
    QString const & getTitle() const;

};


inline QString const & Queen::getTitle() const
{
    return ( isWhite() ) ? PiecesTitle::WhiteQueen : PiecesTitle::BlackQueen;
}

#endif // QUEEN_H
