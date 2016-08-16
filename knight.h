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
    QString const & getTitle() const override;

protected:
    void check_position( Board const & _b, QVector <QPoint> & _v, int _directI, int _directJ ) const override;
};


inline QString const & Knight::getTitle() const
{
    return ( isWhite() ) ? PiecesTitle::WhiteKnight : PiecesTitle::BlackKnight;
}

#endif // KNIGHT_H
