#ifndef ROOK_H
#define ROOK_H

#include "piece.h"

class Rook
        : public Piece
{
public:
    Rook( QWidget* _parent, bool _isWhite, int _x, int _y );
    ~Rook() = default;

    QVector < QPoint > getVectorOfPossibleMoves(const Board &_b) const override;
    void display() const override;

private:
    void check_position( Board const & _b, QVector <QPoint> & _v, int _directI, int _directJ ) const;
};

#endif // ROOK_H
