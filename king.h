#ifndef KING_H
#define KING_H

#include "piece.h"

class King: public Piece
{
Q_OBJECT
/*----------------------------------------------------*/
public:
    King( QWidget* _parent, bool _isWhite, int _x, int _y );
    ~King() = default;

    QVector < QPoint > getVectorOfPossibleMoves( const Board &_b ) override;

    void display() const override;
};

#endif // KING_H
