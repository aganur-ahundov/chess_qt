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
    void moving( QPoint _to ) override;
    void accept( IVisitor & _visitor ) override { _visitor.visit( *this ); }

private:
    bool m_haveMoved;

};

inline QString Rook::getTitle() const
{
    return ( isWhite() ) ? PiecesTitle::WhiteRook : PiecesTitle::BlackRook;
}

inline bool Rook::isMoved() const
{
    return m_haveMoved;
}

inline void Rook::moving( QPoint _to )
{
    m_haveMoved = true;
}


#endif // ROOK_H
