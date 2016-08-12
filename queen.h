#ifndef QUEEN_H
#define QUEEN_H

#include "piece.h"

class Queen : public Piece
{
public:
    Queen( QWidget* _parent, bool _isWhite, int _x, int _y );
    ~Queen() = default;

    QVector < QPoint > getVectorOfPossibleMoves(const Board &_b) const override;
    void display() const override;
};

#endif // QUEEN_H
