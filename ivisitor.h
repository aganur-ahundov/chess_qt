#ifndef IVISITOR_H
#define IVISITOR_H

//################################//
//#include "king.h"
//#include "queen.h"
//#include "pawn.h"
//#include "bishop.h"
//#include "knight.h"
//#include "rook.h"
class King;
class Queen;
class Knight;
class Bishop;
class Rook;
class Pawn;
class Piece;
//################################//


class IVisitor  //interface of design pattern - visitor
{
public:
    virtual void visit( const King & )  = 0;
    virtual void visit( const Queen & ) = 0;
    virtual void visit( const Knight & ) = 0;
    virtual void visit( const Bishop & )  = 0;
    virtual void visit( const Rook & ) = 0;
    virtual void visit( const Pawn & ) = 0;

    virtual bool hit() const = 0;
    virtual void reset_hit() = 0;
};

#endif // IVISITOR_H
