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
    void accept( IVisitor & _visitor ) override { _visitor.visit( *this ); }

private:
    void check_position( Board const & _b, QVector < QPoint > & _v, int _directI, int _directJ ) const override;
    QString getTitle() const override;
    bool newStep( const Board &_b, QVector < QPoint > & _v, short _dirJ ) const;
    void moving( QPoint _to ) override;
};


inline QString Pawn::getTitle() const
{
    return ( isWhite() ) ? PiecesTitle::WhitePawn : PiecesTitle::BlackPawn;
}


#endif // PAWN_H
