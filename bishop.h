#ifndef BISHOP_H
#define BISHOP_H

#include "piece.h"
#include "pieces_title.h"

class Bishop
        : public Piece
{
public:
    Bishop( bool _isWhite, int _x, int _y );
    ~Bishop() = default;

    QVector < QPoint > getVectorOfPossibleMoves(const Board &_b) const override;
    QString getTitle() const override;

};

inline QString Bishop::getTitle() const
{
    return ( isWhite() ) ? PiecesTitle::WhiteBishop : PiecesTitle::BlackBishop;
}

#endif // BISHOP_H
