#ifndef ROOK_H
#define ROOK_H

#include "piece.h"

class Rook
        : public Piece
{
public:
    Rook( bool _isWhite, int _x, int _y );
    ~Rook() = default;

    QVector < QPoint > getVectorOfPossibleMoves(const Board &_b) const override;

};

#endif // ROOK_H
