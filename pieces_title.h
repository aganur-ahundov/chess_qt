#ifndef PIECES_TITLE_H
#define PIECES_TITLE_H

namespace PiecesTitle
{
    /*---------------------------------------------------------*/


    const char * const BlackKing = "Black King";
    const char * const BlackBishop = "Black Bishop";
    const char * const BlackKnight = "Black Knight";
    const char * const BlackPawn = "Black Pawn";
    const char * const BlackQueen = "Black Queen";
    const char * const BlackRook = "Black Rook";


    /*---------------------------------------------------------*/


    const char * const WhiteKing = "White King";
    const char * const WhiteBishop = "White Bishop";
    const char * const WhiteKnight = "White Knight";
    const char * const WhitePawn = "White Pawn";
    const char * const WhiteQueen = "White Queen";
    const char * const WhiteRook = "White Rook";


    /*---------------------------------------------------------*/


    enum Piece_ID
    {
        Pawn_ID,
        Knight_ID,
        Bishop_ID,
        Rook_ID,
        Queen_ID,
        King_ID
    };
}


#endif // PIECES_TITLE_H
