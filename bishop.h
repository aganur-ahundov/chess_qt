#ifndef BISHOP_H
#define BISHOP_H

#include "piece.h"

class Bishop
        : public Piece
{
public:
    Bishop( QWidget* _parent, bool _isWhite, int _x, int _y );
    ~Bishop() = default;

    QVector < QPoint > getVectorOfPossibleMoves(const Board &_b) const override;
    void display() const override;

private:
    void check_position( Board const & _b, QVector < QPoint > & _v, int _directI, int _directJ ) const;

};

#endif // BISHOP_H
