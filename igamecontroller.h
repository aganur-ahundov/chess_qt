#ifndef IGAMECONTROLLER_H
#define IGAMECONTROLLER_H

#include <QSharedPointer>
#include <QObject>
#include <QVector>
#include <QMap>
#include <QSet>
#include <QPoint>
#include "pieces_title.h"

//###########################
class Board;
class Piece;
//###########################


class IGameController
        : public QObject
{
    Q_OBJECT
public:
    IGameController();
    ~IGameController();

    void start();

public slots:
    void boardHaveBeenClicked( QPoint _xy );
    void boared_create_piece_slot( QString const & _title, QPoint _xy );
    void pawn_transformation_slot( QPoint _xy );
    void pawn_transformed_slot( PiecesTitle::Piece_ID );


signals:
    void moved( QPoint _from, QPoint _to );
    void boared_create_piece_signal( QString const & _title, QPoint _xy );
    void have_some_cells_for_moving( QVector < QPoint > const & _v, QPoint );
    void piece_have_been_beaten( QPoint _xy );
    void clearPosOfCurrentPiece();
    void castling_signal( QPoint, QPoint );
    void pawn_transformation_signal();

private:
    /*--------------------------------------------------------------------------*/
    bool isThatColor( QPoint _xy ) const;     //check is it correct piece
    bool isMoving ( QPoint _xy ) const;       //clicked for moving
    bool isAttack( QPoint _xy ) const;
    bool isValidPos( QPoint _xy ) const;

    void clear_data();
    void clearMovePieceMap();


    /*-------------------------------------------------------------------------------*/
    // set of check-functions for move pieces
    short countOfPiecesWhoCanBitKing();
    void countEnemys( Piece* _king, short & _count, QSet < QPoint >  & _moves );
    void countKnights( QPoint _kingPos, short & _count, QSet < QPoint > & _moves );
    void checkKinght( QPoint _xy, short & _count, QSet < QPoint > & _moves );
    void foundEnemyForKingByDirection( short _xDir, short _yDir, Piece* _king, short & _count, QSet < QPoint > & _moves  );
    void fillMovePiecesMap();       //fiil map using check-functions
    void addKingMovesSet();
    bool checkKingIsNotUnderAttack( QPoint _xy );
    bool checkCellByDirection( QPoint _xy, short _x, short _y );
    /*--------------------------------------------------------------------------------*/


private:
    QSharedPointer < Board > m_board;

    /*-----------------------------------------------*/
    QPoint m_pawnTransormPos;
    Piece* m_selectedPiece;
    Piece* m_whiteKing;
    Piece* m_blackKing;

    /*-----------------------------------------------*/
    //positions for move pieces
    QVector < QPoint > m_posForMoving;
    QMap < Piece*, QSet < QPoint > > m_MovePiecesMap;
    QMap < Piece*, QSet < QPoint > > m_mapPinedPiece;
    QSet < QPoint > m_setProtectKingMoves;

};


//##########################################//
inline void IGameController::clear_data()
{
    m_selectedPiece = nullptr;
    m_posForMoving.clear();
}


inline void IGameController::clearMovePieceMap()
{
    m_MovePiecesMap.clear();
    m_mapPinedPiece.clear();
    m_setProtectKingMoves.clear();
}

inline bool IGameController::isMoving( QPoint _xy ) const
{
    foreach (  QPoint x , m_posForMoving )
    {
        if( x == _xy )
            return true;
    }

    return false;
}


inline bool IGameController::isValidPos( QPoint _xy ) const
{
    return _xy.x() >= 0 && _xy.x() < 8 &&
            _xy.y() >= 0 && _xy.y() < 8;
}

#endif // IGAMECONTROLLER_H
