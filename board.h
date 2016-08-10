#ifndef BOARD_H
#define BOARD_H

#include <QWidget>


class Player;

class Board
{
public:
    Board();
    ~Board() = default;

    void display() const;

private:
  Player& m_white;
  Player& m_black;

};

#endif // BOARD_H
