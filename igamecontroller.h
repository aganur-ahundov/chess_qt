#ifndef IGAMECONTROLLER_H
#define IGAMECONTROLLER_H

#include <QSharedPointer>
#include <QObject>
#include <QSet>

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

public slots:
    void boardHaveBeenClicked( QPoint _xy );


private:
    bool isThatColor( QPoint _xy ) const;
    bool isItMove( QPoint _xy ) const;
    void addPositionForMoving( QPoint _xy );
    void addPiece( Piece const * _p );


private:
    QSharedPointer < Board > m_board;
    Piece* m_selectedPiece;
    QSet < QPoint > m_posForMoving;
};

//##########################################//

inline bool IGameController::isThatColor( QPoint _xy ) const
{
    return m_board->getCell( _xy.x(), _xy.y() )->isWhite() == m_board->whitesAreMoving();
}


#endif // IGAMECONTROLLER_H