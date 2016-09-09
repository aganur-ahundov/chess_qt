#ifndef GAME_H
#define GAME_H


#include <QSharedPointer>
#include <QObject>


class IGraphicsController;
class IGameController;

class Game
        : public QObject
{
    Q_OBJECT

private:
    static Game * m_Instance;

protected:
    Game();
    ~Game();

public:
    Game( Game const & ) = delete;
    Game & operator = ( Game const & ) = delete;

    static Game * getInstance();
    void display() const;

private:
    QSharedPointer < IGraphicsController > m_graphController;
    QSharedPointer < IGameController >     m_gameController;

};



#endif // GAME_H
