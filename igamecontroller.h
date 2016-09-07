#ifndef IGAMECONTROLLER_H
#define IGAMECONTROLLER_H

#include <QSharedPointer>
#include <QObject>

//###########################
class Board;
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
    QSharedPointer < Board > m_board;
};

#endif // IGAMECONTROLLER_H
