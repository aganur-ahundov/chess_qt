#ifndef IGAMECONTROLLER_H
#define IGAMECONTROLLER_H

#include <QSharedPointer>
#include <QObject>
#include <QVector>
#include <QPoint>

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

    void start() const;

public slots:
    void boardHaveBeenClicked( QPoint _xy );
    void boared_create_piece_slot( QString const & _title, QPoint _xy );

signals:
    void moved( QPoint _from, QPoint _to );
    void boared_create_piece_signal( QString const & _title, QPoint _xy );
    void have_some_cells_for_moving( QVector < QPoint > const & _v );

private:
    bool isThatColor( QPoint _xy ) const;     //check is it correct piece
    bool failClick( QPoint _xy ) const;       //clicked on enemy or free cell
    bool isMoving ( QPoint _xy ) const;       //clicked for moving
    void clear_data();

private:
    QSharedPointer < Board > m_board;
    Piece* m_selectedPiece;
    QVector < QPoint > m_posForMoving;
};

//##########################################//

inline void IGameController::clear_data()
{
    m_selectedPiece = nullptr;
    m_posForMoving.clear();
}

inline bool IGameController::isMoving(QPoint _xy) const
{
    foreach (  QPoint x , m_posForMoving )
    {
        if( x == _xy )
            return true;
    }

    return false;
}

#endif // IGAMECONTROLLER_H
