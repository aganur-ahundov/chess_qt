#ifndef KING_H
#define KING_H

#include "piece.h"

class King: public Piece
{
/*----------------------------------------------------*/
public:
    King( QWidget* _parent, bool _isWhite, int _x, int _y );
    ~King() = default;

    QVector < QPoint > getVectorOfPossibleMoves( const Board &_b ) const override;
    void display() const override;

private:
    void check_position( Board const & _b, QVector < QPoint > & _v, int _i, int _j ) const;
};

#endif // KING_H
