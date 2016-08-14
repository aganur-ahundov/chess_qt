#ifndef IGRAPHICSCONTROLLER_H
#define IGRAPHICSCONTROLLER_H

#include <QWidget>
#include <QLabel>
#include <QMap>


class Piece;
class BoardWidget;


class IGraphicsController
{
public:
    explicit IGraphicsController();
    ~IGraphicsController() = default;

    void repaint_board() const;
    void create_piece() const; //??????????????/
    void reset_board() const;  //all pieces/labels on default position

////////////////////////////////////////////////////////
    //void paintPauseMenu();
    // and alike methods??
/////////////////////////////////////////////////////////

signals:
    void clicked_on_board( QPoint _xy ); // signal send board coordinates

public slots:
    void move_piece( QPoint _from, QPoint _to );  //using BoardWidget methods
    void delete_piece( QPoint _xy );

private:
    void setBackground();
    void loadPiecesInfo();
    QPoint toBoardCoordinates( QPoint _xy ) const;

private:
    QMap < QString, QString >       m_piecesAndRoutes;    //pieces title and routes for pictures
    QSharedPointer < BoardWidget >  m_gameBoard;
};


#endif // IGRAPHICSCONTROLLER_H
