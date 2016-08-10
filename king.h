#ifndef KING_H
#define KING_H

#include "piece.h"

class King
        : public Piece
{

/*----------------------------------------------------*/
public:
    King( QWidget* _parent, bool _isWhite, int _x, int _y );
    ~King() = default;

    void move( Board & _b ) override;
    void check_steps( Board const & _b ) override;
    void display() const override;
};

#endif // KING_H
