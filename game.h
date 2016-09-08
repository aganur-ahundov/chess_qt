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
public:
    Game();
    ~Game() = default;

    Game( Game const & ) = delete;
    Game & operator = ( Game const & ) = delete;

    void display() const;


private:
    QSharedPointer < IGraphicsController > m_graphController;
    QSharedPointer < IGameController >     m_gameController;

};

#endif // GAME_H
