#ifndef BISHOP_H
#define BISHOP_H

#include "piece.h"

class Bishop
        : public Piece
{
public:
    Bishop( QString const & _title,  bool _isWhite, int _x, int _y );
    ~Bishop() = default;

    QVector < QPoint > getVectorOfPossibleMoves(const Board &_b) const override;

};

#endif // BISHOP_H
