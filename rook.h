#ifndef ROOK_H
#define ROOK_H

#include "piece.h"
#include "pieces_title.h"

class Rook
        : public Piece
{
public:
    Rook( bool _isWhite, int _x, int _y );
    ~Rook() = default;

    QVector < QPoint > getVectorOfPossibleMoves(const Board &_b) const override;
    QString getTitle() const override;
    bool isMoved() const;

private:
    bool m_moved;

};

inline QString Rook::getTitle() const
{
    return ( isWhite() ) ? PiecesTitle::WhiteRook : PiecesTitle::BlackRook;
}

inline bool Rook::isMoved() const
{
    return m_moved;
}

#endif // ROOK_H
