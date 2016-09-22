#ifndef QUEEN_H
#define QUEEN_H

#include "piece.h"
#include "pieces_title.h"

class Queen
        : public Piece
{
public:
    Queen( bool _isWhite, int _x, int _y );
    ~Queen() = default;

    QVector < QPoint > getVectorOfPossibleMoves(const Board &_b) const override;
    QString getTitle() const;
    void accept( IVisitor & _visitor ) override { _visitor.visit( *this ); }
};


inline QString Queen::getTitle() const
{
    return ( isWhite() ) ? PiecesTitle::WhiteQueen : PiecesTitle::BlackQueen;
}

#endif // QUEEN_H
