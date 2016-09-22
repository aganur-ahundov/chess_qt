#ifndef KNIGHT_H
#define KNIGHT_H

#include "piece.h"
#include "pieces_title.h"

class Knight
        : public Piece
{
public:
    Knight( bool _isWhite, int _x, int _y );
    ~Knight() = default;

    QVector < QPoint > getVectorOfPossibleMoves(const Board &_b) const override;
    QString getTitle() const override;
    void accept( IVisitor & _visitor ) override { _visitor.visit( *this ); }

protected:
    void check_position( Board const & _b, QVector <QPoint> & _v, int _directI, int _directJ ) const override;
};


inline QString Knight::getTitle() const
{
    return ( isWhite() ) ? PiecesTitle::WhiteKnight : PiecesTitle::BlackKnight;
}

#endif // KNIGHT_H
