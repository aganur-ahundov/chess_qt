#ifndef PAWN_H
#define PAWN_H

#include "piece.h"

class Pawn : public Piece
{
public:
    Pawn( QString const & _title, bool _isWhite, int _x, int _y );
    ~Pawn() = default;

    QVector < QPoint > getVectorOfPossibleMoves(const Board &_b) const override;

private:
    void check_position( Board const & _b, QVector < QPoint > & _v, int _directI, int _directJ ) const override;
};

#endif // PAWN_H
