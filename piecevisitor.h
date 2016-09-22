#ifndef PIECEVISITOR_H
#define PIECEVISITOR_H

#include "ivisitor.h"
#include <QPoint>

class PieceVisitor
        : public IVisitor
{
public:
    PieceVisitor( QPoint _kingXY, short _directionX, short _directionY );

    void visit( const King & ) override;
    void visit( const Queen & ) override;
    void visit( const Knight & ) override;  //this funct useless
    void visit( const Bishop & ) override;
    void visit( const Rook & ) override;
    void visit( const Pawn & ) override;

    bool hit() const override;
    void reset_hit() override;

private:
    bool m_hit;
    short m_distance;
    short m_directionX;
    short m_directionY;
    QPoint m_kingPos;

};


inline bool PieceVisitor::hit() const
{
    return m_hit;
}

inline void PieceVisitor::reset_hit()
{
    m_hit = false;
}

#endif // PIECEVISITOR_H
