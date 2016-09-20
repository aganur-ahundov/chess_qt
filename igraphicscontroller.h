#ifndef IGRAPHICSCONTROLLER_H
#define IGRAPHICSCONTROLLER_H

#include <QSharedPointer>
#include <QObject>
#include <QMap>
#include <QPoint>
#include "pawntransformationdialog.h"


class Piece;
class BoardWidget;


class IGraphicsController
        :public QObject
{
    Q_OBJECT
public:
    explicit IGraphicsController();
    ~IGraphicsController() = default;

    void repaint_board() const;
    void reset_board() const;  //all pieces/labels on default position
    void show() const;  //show board


signals:
    void clicked_on_board( QPoint _xy ); // signal send board coordinates
    void create_rook_signal( QPoint _xy );
    void create_queen_signal( QPoint _xy );
    void create_knight_signal( QPoint _xy );
    void create_bishop_signal( QPoint _xy );
    void pawn_transformed_signal( PiecesTitle::Piece_ID );

public slots:
    void clicked_point( QPoint _xy );
    void move_piece( QPoint _from, QPoint _to );  //using BoardWidget methods
    void delete_piece( QPoint _xy );
    void create_piece( QString const & _title, QPoint _xy ) const;
    void paint_cells_for_moving( QVector < QPoint > const & _v, QPoint );
    void pawn_transformation_slot();

private:
    void setBackground();
    void loadPiecesInfo();
    QPoint toBoardCoordinates( QPoint _xy ) const;

private:
    QMap < QString, QString >       m_piecesAndRoutes;    //pieces title and routes for pictures
    QSharedPointer < BoardWidget >  m_gameBoard;
    QSharedPointer < PawnTransformationDialog > m_pawnDialog;
};



#endif // IGRAPHICSCONTROLLER_H
