#ifndef KNIGHT_H
#define KNIGHT_H

#include "piece.h"

class Knight
        : public Piece
{
public:
    Knight( bool _isWhite, int _x, int _y );
    ~Knight() = default;

    QVector < QPoint > getVectorOfPossibleMoves(const Board &_b) const override;

protected:
    void check_position( Board const & _b, QVector < QPoint > _v, int _directI, int _directJ ) const;
};

#endif // KNIGHT_H
