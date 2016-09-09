#ifndef PAWN_H
#define PAWN_H

#include "piece.h"
#include "pieces_title.h"

class Pawn : public Piece
{
public:
    Pawn( bool _isWhite, int _x, int _y );
    ~Pawn() = default;

    QVector < QPoint > getVectorOfPossibleMoves( const Board &_b ) const override;

private:
    void check_position( Board const & _b, QVector < QPoint > & _v, int _directI, int _directJ ) const override;
    QString getTitle() const override;
};


inline QString Pawn::getTitle() const
{
    return ( isWhite() ) ? PiecesTitle::WhitePawn : PiecesTitle::BlackPawn;
}


#endif // PAWN_H
